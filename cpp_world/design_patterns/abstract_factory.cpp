/*
Abstract factory provides an interface for creating families of related or dependent objects
without specifying their concrete classes. This pattern is a way to encapsulate the creation of
objects and ensure that they are compatible and properly configured.


1-Abstract Factory Interface: This interface defines a set of methods for creating various abstract product types.
  Each method in the interface corresponds to a different product family.
2-Concrete Factories: Concrete factory classes implement the Abstract Factory interface.
  Each concrete factory is responsible for creating a specific family of related products.
3-Abstract Product Interfaces: These interfaces define the structure and behavior of the product objects created by the factory.
  Each product family has its set of abstract product interfaces.
4-Concrete Products: Concrete product classes implement the abstract product interfaces.
  These classes represent the actual objects that the client code will use.
5-Client: The client code works with the abstract factory and abstract product interfaces.
  It doesn’t need to know the concrete classes of the products it uses. Instead, it relies on the factory to create compatible objects.
*/

#include <iostream>
 
// Abstract Product Interface
class Pizza {
public:
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

// Concrete Products - New York Cheese Pizza
class NewYorkCheesePizza : public Pizza {
public:
    void bake() override
    {
        std::cout << "Baking New York-style cheese pizza."
                  << std::endl;
    }
 
    void cut() override
    {
        std::cout << "Cutting New York-style cheese pizza."
                  << std::endl;
    }
 
    void box() override
    {
        std::cout << "Boxing New York-style cheese pizza."
                  << std::endl;
    }
};

// Concrete New York Pepperoni Pizza
class NewYorkPepperoniPizza : public Pizza {
public:
    void bake() override
    {
        std::cout
            << "Baking New York-style pepperoni pizza."
            << std::endl;
    }
 
    void cut() override
    {
        std::cout
            << "Cutting New York-style pepperoni pizza."
            << std::endl;
    }
 
    void box() override
    {
        std::cout
            << "Boxing New York-style pepperoni pizza."
            << std::endl;
    }
};
 
// Concrete Chicago Cheese Pizza
class ChicagoCheesePizza : public Pizza {
public:
    void bake() override
    {
        std::cout << "Baking Chicago-style cheese pizza."
                  << std::endl;
    }
 
    void cut() override
    {
        std::cout << "Cutting Chicago-style cheese pizza."
                  << std::endl;
    }
 
    void box() override
    {
        std::cout << "Boxing Chicago-style cheese pizza."
                  << std::endl;
    }
};
 
// Concrete Chicago Pepperoni Pizza
class ChicagoPepperoniPizza : public Pizza {
public:
    void bake() override
    {
        std::cout << "Baking Chicago-style pepperoni pizza."
                  << std::endl;
    }
 
    void cut() override
    {
        std::cout
            << "Cutting Chicago-style pepperoni pizza."
            << std::endl;
    }
 
    void box() override
    {
        std::cout << "Boxing Chicago-style pepperoni pizza."
                  << std::endl;
    }
};

// Abstract Factory Interface
class PizzaFactory {
public:
    virtual Pizza* createCheesePizza() = 0;
    virtual Pizza* createPepperoniPizza() = 0;
};

// Concrete New York Pizza Factory
class NewYorkPizzaFactory : public PizzaFactory {
public:
    Pizza* createCheesePizza() override
    {
        return new NewYorkCheesePizza();
    }
 
    Pizza* createPepperoniPizza() override
    {
        return new NewYorkPepperoniPizza();
    }
};
 
// Concrete Chicago Pizza Factory
class ChicagoPizzaFactory : public PizzaFactory {
public:
    Pizza* createCheesePizza() override
    {
        return new ChicagoCheesePizza();
    }
 
    Pizza* createPepperoniPizza() override
    {
        return new ChicagoPepperoniPizza();
    }
};

int main()
{
    // Create a New York Pizza Factory
    PizzaFactory* newYorkFactory
        = new NewYorkPizzaFactory();
    Pizza* newYorkCheesePizza
        = newYorkFactory->createCheesePizza();
    Pizza* newYorkPepperoniPizza
        = newYorkFactory->createPepperoniPizza();
 
    // Create a Chicago Pizza Factory
    PizzaFactory* chicagoFactory
        = new ChicagoPizzaFactory();
    Pizza* chicagoCheesePizza
        = chicagoFactory->createCheesePizza();
    Pizza* chicagoPepperoniPizza
        = chicagoFactory->createPepperoniPizza();
 
    // Order and prepare the pizzas
    newYorkCheesePizza->bake();
    newYorkCheesePizza->cut();
    newYorkCheesePizza->box();
 
    newYorkPepperoniPizza->bake();
    newYorkPepperoniPizza->cut();
    newYorkPepperoniPizza->box();
 
    chicagoCheesePizza->bake();
    chicagoCheesePizza->cut();
    chicagoCheesePizza->box();
 
    chicagoPepperoniPizza->bake();
    chicagoPepperoniPizza->cut();
    chicagoPepperoniPizza->box();
 
    // Clean up
    delete newYorkFactory;
    delete newYorkCheesePizza;
    delete newYorkPepperoniPizza;
    delete chicagoFactory;
    delete chicagoCheesePizza;
    delete chicagoPepperoniPizza;
 
    return 0;
}