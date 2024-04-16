#include <iostream>

class Creature
{
public:
    Creature() {}
    virtual ~Creature() = default;
    virtual Creature* Clone() { return nullptr; }

    int GetHP() { return HitPoints; }
    int GetAttack() { return Attack; }
    int GetSpeed() { return Speed; }
protected:
    int HitPoints = 0;
    int Attack = 0;
    int Speed = 0;
};

class Goblin : public Creature
{
public:
    Goblin() { HitPoints = 1, Attack = 2, Speed = 3; }
};

class Dwarf : public Creature
{
    Dwarf() { HitPoints = 5, Attack = 5, Speed = 2; }
};

class Elf : public Creature
{
    Elf() { HitPoints = 3, Attack = 3, Speed = 5; }
};


