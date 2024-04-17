#include "spawner.h"
#include <random>

int Rnd();

int main()
{
    //setting spawner
    GoblinSpawner gs;
    DwarfSpawner ds;
    ElfSpawner es;

    //spawning creature by one test
    Creature* pCreature[3] = {nullptr, nullptr, nullptr };

    pCreature[0] = gs.Spawn();
    pCreature[1] = ds.Spawn();
    pCreature[2] = es.Spawn();
    // casting creatures to proper type
    for(const auto& i : pCreature)
    {
        auto pGoblin = dynamic_cast<Goblin*>(i);
        if(pGoblin)
        {
            pGoblin->Spawned();
        }

        auto pDwarf = dynamic_cast<Dwarf*>(i);
        if(pDwarf)
        {
            pDwarf->Spawned();
        }

        auto pElf = dynamic_cast<Elf*>(i);
        if(pElf)
        {
            pElf->Spawned();
        }
    }
    std::cout << "\n";

    int rnd = Rnd();

    //spawning a pack of Goblins tests
    std::vector<Creature*> GoblinPack(Rnd());
    gs.SpawnPack(GoblinPack, rnd);

    for(const auto& i: GoblinPack)
    {
        auto pGoblin = dynamic_cast<Goblin*>(i);
        if(pGoblin)
        {
            pGoblin->Spawned();
        }
    }
    return EXIT_SUCCESS;
}

int Rnd()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 5);
    int rnd = distribution(gen);
    return rnd;
}