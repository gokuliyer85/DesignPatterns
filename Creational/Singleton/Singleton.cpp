#include <iostream>

using namespace std;

class Singleton
{
    private:
        static Singleton* __instance;
        Singleton() {}
    public:
        Singleton(Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(Singleton&) = delete;
        Singleton&& operator=(Singleton&&) = delete;

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