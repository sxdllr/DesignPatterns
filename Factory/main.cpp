#include "spawner.h"

//spawn different numbers of creatures depending on the difficulty mode
enum class GameMode
{
    easy,
    medium,
    hard
};

int main()
{
    //setting spawner
    GoblinSpawner gs;
    DwarfSpawner ds;
    ElfSpawner es;
    LizardSpawner ls;

    //spawning creature by one test
    Creature* pCreature[4] = {nullptr, nullptr, nullptr, nullptr};

    pCreature[0] = gs.Spawn();
    pCreature[1] = ds.Spawn();
    pCreature[2] = es.Spawn();
    pCreature[3] = ls.Spawn();

    // casting creatures to proper type
    for(auto& i : pCreature)
    {
        auto pGoblin = dynamic_cast<Goblin*>(i);
        if(pGoblin)
        {
            std::cout << "Goblin: \n"
                      << "HP: " << pGoblin->GetHP() << ' '
                      << "Attack: " <<pGoblin->GetAttack() << ' '
                      << "Speed: " <<pGoblin->GetSpeed() << "\n";
        }

        auto pDwarf = dynamic_cast<Dwarf*>(i);
        if(pDwarf)
        {
            std::cout << "Dwarf: \n"
                      << "HP: " << pDwarf->GetHP() << ' '
                      << "Attack: " <<pDwarf->GetAttack() << ' '
                      << "Speed: " <<pDwarf->GetSpeed() << "\n";
        }

        auto pElf = dynamic_cast<Elf*>(i);
        if(pElf)
        {
            std::cout << "Elf: \n"
                      << "HP: " << pElf->GetHP() << ' '
                      << "Attack: " <<pElf->GetAttack() << ' '
                      << "Speed: " <<pElf->GetSpeed() << "\n";
        }
    }

    //clone test
    Creature* pLiz = ls.Spawn();

    auto pLizard = dynamic_cast<Lizard*>(pLiz);
    if(pLizard)
    {
        std::cout << "Lizard: \n"
                  << "HP: " << pLizard->GetHP() << ' '
                  << "Attack: " <<pLizard->GetAttack() << ' '
                  << "Speed: " <<pLizard->GetSpeed() << "\n";
    }

    auto pCL = pLizard->Clone(5, 5, 5);
    auto pClonedLizard = dynamic_cast<Lizard*>(pCL);
    if(pClonedLizard)
    {
        std::cout << "Cloned Lizard: \n"
                  << "HP: " << pClonedLizard->GetHP() << ' '
                  << "Attack: " <<pClonedLizard->GetAttack() << ' '
                  << "Speed: " <<pClonedLizard->GetSpeed() << "\n";
    }

    return EXIT_SUCCESS;
}