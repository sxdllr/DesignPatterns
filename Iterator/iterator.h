#include <iostream>
#include <stdexcept>
#include <vector>

class Iterator;
class ConcreteAggregate;

class Aggregate
{
public:
    virtual ~Aggregate() = default;

    virtual Iterator *createIterator() = 0;
};

class ConcreteAggregate : public Aggregate
{
public:
    explicit ConcreteAggregate( const unsigned int size )
    {
        list = new int[size]();
        count = size;
    }

    ~ConcreteAggregate() { delete[] list; }

    Iterator *createIterator();

    unsigned int size() const { return count; }

    int at( unsigned int index ) { return list[ index ]; }

private:
    int *list;
    unsigned int count;
};

class Iterator
{
public:
    virtual ~Iterator() = default;

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual int currentItem() const = 0;
};

class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator( ConcreteAggregate *l ) :
            list( l ), index( 0 ) {}

    void first() override { index = 0; }

    void next() override { index++; }

    bool isDone() const override { return ( index >= list->size() ); }

    int currentItem() const override
    {
        if ( isDone() ) { return -1; }
        return list->at(index);
    }

private:
    ConcreteAggregate *list;
    unsigned int index;
};

Iterator *ConcreteAggregate::createIterator()
{
    return new ConcreteIterator( this );
}
