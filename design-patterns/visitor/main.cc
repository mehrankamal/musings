/**
 * An implementation of the basic barebones of Visitor pattern
 */

#include <iostream>

class ComponentA;
class ComponentB;

class Visitor
{
public:
    virtual void visit_component_a(const ComponentA *elem) = 0;
    virtual void visit_component_b(const ComponentB *elem) = 0;
};

class Component
{
public:
    virtual ~Component() {}
    virtual void accept(Visitor *visitor) = 0;
};

class ComponentA : public Component
{
public:
    void accept(Visitor *visitor)
    {
        visitor->visit_component_a(this);
    }

    std::string do_something_a() const
    {
        return "I am Component A\n"; 
    }
};

class ComponentB : public Component 
{
public:
    void accept(Visitor *visitor)
    {
        visitor -> visit_component_b(this);
    }

    std::string do_something_b() const
    {
        return "I'm Component B\n";
    }
};

class NamePrinter : public Visitor
{
public:
    void visit_component_a(const ComponentA *a)
    {
        std::cout << a -> do_something_a();
    }

    void visit_component_b(const ComponentB *b)
    {
        std::cout << b -> do_something_b();
    }
};

int main()
{
    ComponentA a;
    ComponentB b;
    ComponentB bb;

    NamePrinter name_printer;

    a.accept(&name_printer);
    b.accept(&name_printer);
    bb.accept(&name_printer);

    return 0;
}