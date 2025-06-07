#include <iostream>

using namespace std;

class Product
{
    private:
        //nothing to declare
    public:
        Product()
        {
            cout << "Product base class" << endl;
        }

        virtual ~Product() {}
};

class ConcreteProductA : public Product
{
    private:
        //nothing to declare
    public:
        ConcreteProductA()
        {
            cout << "Concrete Product A" << endl;
        }
};

class ConcreteProductB : public Product
{
    private:
        //nothing to declare
    public:
        ConcreteProductB()
        {
            cout << "Concrete Product B" << endl;
        }
};

class Factory
{
    private:
        //nothing to declare
    public:
        Factory() 
        {
            cout << "Factory base class" << endl;
        }

        virtual ~Factory() {}

        virtual Product* CreateProductA() = 0;
        virtual Product* CreateProductB() = 0;
};

class ConcreteFactory : public Factory
{
    private:
        //nothing to declare
    public:
        ConcreteFactory()
        {
            cout << "Concrete Factory" << endl;
        }

        virtual Product* CreateProductA()
        {
            return new ConcreteProductA();
        }

        virtual Product* CreateProductB()
        {
            return new ConcreteProductB();
        }
};

void main()
{
    std::unique_ptr<ConcreteFactory> factory = std::make_unique<ConcreteFactory>();

    std::unique_ptr<Product> productA(factory->CreateProductA());
    std::unique_ptr<Product> productB(factory->CreateProductB());
}