#include "creature.h"
#include <vector>

class Spawner
{
public:
    virtual ~Spawner() {}
    virtual Creature* Spawn() = 0;
};

class GoblinSpawner : public Spawner
{
public:
    Creature* Spawn() override { return new Goblin(); }
};

class DwarfSpawner : public Spawner
{
public:
    Creature* Spawn() override { return new Dwarf(); }
};

class ElfSpawner : public Spawner
{
public:
    Creature* Spawn() override { return new Elf(); }
};

class LizardSpawner : public Spawner
{
public:
    Creature* Spawn() override { return new Lizard(1, 1, 1); }
};
