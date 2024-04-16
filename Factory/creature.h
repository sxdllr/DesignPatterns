#include <iostream>
#include <vector>

class Creature
{
public:
    Creature() = default;
    virtual ~Creature() = default;
    virtual Creature* Clone() { return nullptr; }

    int GetHP() const  { return HitPoints; }
    int GetAttack() const { return Attack; }
    int GetSpeed() const { return Speed; }

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
public:
    Dwarf() { HitPoints = 5, Attack = 5, Speed = 2; }
};

class Elf : public Creature
{
public:
    Elf() { HitPoints = 3, Attack = 3, Speed = 5; }
};

class Lizard : public Creature
{
public:
    Lizard(int hp, int at, int sp) { HitPoints = hp, Attack = at, Speed = sp; }
    Creature* Clone() override { return new Lizard(HitPoints, Attack, Speed); }
    Creature* Clone(int hp, int at, int sp) { return new Lizard(hp, at, sp); }
};


