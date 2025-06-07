#include <iostream>

using namespace std;

class Singleton
{
    private:
        static Singleton* __instance;
        Singleton() {}
    public:
        Singleton(Singleton&) = delete; //removing copy constructor
        Singleton(Singleton&&) = delete; //removing move constructor
        Singleton& operator=(Singleton&) = delete; //removing copy assignment
        Singleton&& operator=(Singleton&&) = delete; //removing move assignment

        static Singleton* GetInstance()
        {
           if(__instance == nullptr)
           {
                __instance = new Singleton();
           } 

           return __instance;
        }

        void CheckInstance()
        {
            cout << "This is called from Singleton instance" << endl;
        }
};

Singleton* Singleton::__instance = nullptr;

void main()
{
    Singleton *instance = Singleton::GetInstance();
    instance->CheckInstance();
}