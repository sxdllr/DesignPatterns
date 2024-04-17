#include "creature.h"
#include <vector>

class Spawner
{
public:
    virtual ~Spawner() = default;
    virtual Creature* Spawn() = 0;
    virtual void SpawnPack(std::vector<Creature*>&, int&) = 0;
};

class GoblinSpawner : public Spawner
{
public:
    Creature* Spawn() override { return new Goblin(); }
    void SpawnPack(std::vector<Creature*>& OutPack, int& input) override
    {
        for(int i = 0; i < input; ++i)
        {
            OutPack.push_back(new Goblin());
        }
    }
};

class DwarfSpawner : public Spawner
{
public:
    Creature* Spawn() override { return new Dwarf(); }
    void SpawnPack(std::vector<Creature*>& OutPack, int& input) override
    {
        for(int i = 0; i < input; ++i)
        {
            OutPack.push_back(new Dwarf());
        }
    }
};

class ElfSpawner : public Spawner
{
public:
    Creature* Spawn() override { return new Elf(); }
    void SpawnPack(std::vector<Creature*>& OutPack, int& input) override
    {
        for(int i = 0; i < input; ++i)
        {
            OutPack.push_back(new Elf());
        }
    }
};
