#include <iostream>

using namespace std;

class AbstractProduct1
{
    private:
        //nothing to declare
    public:
        AbstractProduct1()
        {
            cout << "AbstractProduct1 base class" << endl;
        }

        virtual ~AbstractProduct1() {}
};

class AbstractProduct2
{
    private:
        //nothing to declare
    public:
        AbstractProduct2()
        {
            cout << "AbstractProduct2 base class" << endl;
        }

        virtual ~AbstractProduct2() {}
};

class ConcreteProduct1 : public AbstractProduct1
{
    private:
        //nothing to declare
    public:
        ConcreteProduct1()
        {
            cout << "Concrete Product 1" << endl;
        }
};

class ConcreteProduct2 : public AbstractProduct2
{
    private:
        //nothing to declare
    public:
        ConcreteProduct2()
        {
            cout << "Concrete Product 2" << endl;
        }
};

class AbstractFactory
{
    private:
        //nothing to declare
    public:
        AbstractFactory() 
        {
            cout << "AbstractFactory base class" << endl;
        }

        virtual ~AbstractFactory() {}

        virtual AbstractProduct1* CreateProduct1() = 0;
        virtual AbstractProduct2* CreateProduct2() = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
    private:
        //nothing to declare
    public:
        ConcreteFactory1()
        {
            cout << "ConcreteFactory1 class" << endl;
        }

        AbstractProduct1* CreateProduct1() override
        {
            return new ConcreteProduct1();
        }
        AbstractProduct2* CreateProduct2() override
        {
            return new ConcreteProduct2();
        }
};

class ConcreteFactory2 : public AbstractFactory
{
    private:
        //nothing to declare
    public:
        ConcreteFactory2()
        {
            cout << "ConcreteFactory2 class" << endl;
        }

        AbstractProduct1* CreateProduct1() override
        {
            return new ConcreteProduct1();
        }
        AbstractProduct2* CreateProduct2() override
        {
            return new ConcreteProduct2();
        }
};

void main()
{
    std::unique_ptr<AbstractFactory> factory1(new ConcreteFactory1());
    std::unique_ptr<AbstractFactory> factory2(new ConcreteFactory2());

    std::unique_ptr<AbstractProduct1> product1_factory1(factory1->CreateProduct1());
    std::unique_ptr<AbstractProduct2> product2_factory1(factory1->CreateProduct2());
    std::unique_ptr<AbstractProduct1> product1_factory2(factory2->CreateProduct1());
    std::unique_ptr<AbstractProduct2> product2_factory2(factory2->CreateProduct2());
}