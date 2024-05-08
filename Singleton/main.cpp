#include "singleton.h"

//Ensures that the class has only one instance and provides a global access point to it

int main()
{
    Inventory::Instance().addItem("Scroll");
    Inventory::Instance().addItem("Sword");
    Inventory::Instance().addItem("Potion");

    Inventory::Instance().printInventory();

    Inventory& slot1 = Inventory::Instance();
    slot1.addItem("Shield");

    Inventory& slot2 = Inventory::Instance();
    slot2.addItem("Helmet");

    Inventory::Instance().printInventory();

    return EXIT_SUCCESS;
}