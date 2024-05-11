#include "iterator.h"

int main()
{
    unsigned int size = 5;
    ConcreteAggregate list = ConcreteAggregate(size);

    Iterator *it = list.createIterator();
    for ( ; !it->isDone(); it->next())
    {
        std::cout << "Item value: " << it->currentItem() << std::endl;
    }

    delete it;

    return EXIT_SUCCESS;
}
