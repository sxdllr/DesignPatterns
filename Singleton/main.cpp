#include "singleton.h"

//Ensures that the class has only one instance and provides a global access point to it

int main()
{
    Singleton::Instance()->Register("Object 1");
    Singleton::Instance()->Register("Object 2");
    Singleton::Instance()->Register("Object 3");
    Singleton::Instance()->PrintRegister();

    Singleton* singleton1 = Singleton::Instance();
    singleton1->Register("Object 4");

    Singleton* singleton2 = Singleton::Instance();
    singleton2->Register("Object 5");

    Singleton::Instance()->PrintRegister();

    return EXIT_SUCCESS;
}