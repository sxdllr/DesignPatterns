#include <iostream>

class Creature
{
public:
    Creature() = default;
    virtual ~Creature() = default;
    virtual void Spawned() = 0;

protected:
    int HitPoints = 0;
    int Attack = 0;
    int Speed = 0;
};

class Goblin : public Creature
{
public:
    Goblin() { HitPoints = 1, Attack = 2, Speed = 3; }
    void Spawned() override { std::cout << "Goblin Spawned\n"; }
};

class Dwarf : public Creature
{
public:
    Dwarf() { HitPoints = 5, Attack = 5, Speed = 2; }
    void Spawned() override { std::cout << "Dwarf Spawned\n"; }
};

class Elf : public Creature
{
public:
    Elf() { HitPoints = 3, Attack = 3, Speed = 5; }
    void Spawned() override { std::cout << "Elf Spawned\n"; }
};


