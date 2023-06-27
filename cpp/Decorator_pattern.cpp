#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Design Principle : Classes should be open for extensionbut closed for modification.

/* Decorator Pattern
    Definition: The Decorator Pattern attaches additional responsibilities to an object dynamically.
        Decorators provide a flexible alternative to subclassing for extending functionality.

    Note: If you hae code that relies on the concrete component's typedecorator will break that code.
        As long as you only write code againt the abstract component typethe use of decorators will remain
        transparent to the client. Howeveronce you start writing code against the concrete component type,
        you'll want to rethink your application's design.
*/

// --------------------------------------------Coffee Abstract Class-------------------------------------
class Coffee{
protected:
    string description;
    double cost;
public:
    virtual string getDescription(){
        return description;
    }
    virtual double getCost(){
        return cost;
    }
    virtual ~Coffee(){};
};

// --------------------------------------------Coffee Concrete Classes-------------------------------------
class Espresso:public Coffee{
public:
    Espresso(){
        description = "Espresso";
        cost = 1.99;
    }
};
class HouseBlend:public Coffee{
public:
    HouseBlend(){
        description = "House Blend Coffee";
        cost = 0.89;
    }
};
class DarkRoast:public Coffee{
public:
    DarkRoast(){
        description = "Dark Roast Coffee";
        cost = 0.99;
    }
};


// --------------------------------------------Coffee Decorator Abstract Class-------------------------------------
class CoffeeDecorator:public Coffee{
protected:
    Coffee *coffee;
public:

    string getDescription() override {
        return coffee->getDescription() +" "+ description;
    }
    double getCost() override {
        return coffee->getCost() + cost;
    }
};


// --------------------------------------------Coffee Decorator Concrete Classes-------------------------------------
class Mocha:public CoffeeDecorator{
public:
    Mocha(Coffee *coffee){
        this->coffee = coffee;
        description = "Mocha";
        cost = 0.20;
    }
};

class Whip:public CoffeeDecorator{
public:
    Whip(Coffee *coffee){
        this->coffee = coffee;
        description = "Whip";
        cost = 0.10;
    }
    
};

class Soy:public CoffeeDecorator{
public:
    Soy(Coffee *coffee){
        this->coffee = coffee;
        description = "Soy";
        cost = 0.15;
    }
    
};

class SteamedMilk:public CoffeeDecorator{
public:
    SteamedMilk(Coffee *coffee){
        this->coffee = coffee;
        description = "Steamed Milk";
        cost = 0.10;
    }
   
};

int main(){
    Coffee *coffee = new Espresso();
    cout<<coffee->getDescription()<<" = $"<<coffee->getCost()<<endl;
    coffee = new Mocha(coffee);
    cout<<coffee->getDescription()<<" = $"<<coffee->getCost()<<endl;
    coffee = new Whip(coffee);
    cout<<coffee->getDescription()<<" = $"<<coffee->getCost()<<endl;
    coffee = new Soy(coffee);
    cout<<coffee->getDescription()<<" = $"<<coffee->getCost()<<endl;
    coffee = new SteamedMilk(coffee);
    cout<<coffee->getDescription()<<" = $"<<coffee->getCost()<<endl;



    Coffee *coffee2 = new DarkRoast();
    cout<<coffee2->getDescription()<<" = $"<<coffee2->getCost()<<endl;
    coffee2 = new Mocha(coffee2);
    cout<<coffee2->getDescription()<<" = $"<<coffee2->getCost()<<endl;
    return 0;
}