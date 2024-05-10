#include "command.h"
#include <memory>

//way to take objects && model them as commands that execute actions

int main()
{
    Character ch("Yurii");
    std::vector<std::unique_ptr<Command>> command_queue;

    command_queue.push_back(std::make_unique<Move>());
    command_queue.push_back(std::make_unique<Move>());
    command_queue.push_back(std::make_unique<Move>());
    command_queue.push_back(std::make_unique<Move>());

    for(auto& it : command_queue)
    {
        it->execute(ch);
    }

    std::cout << "\n";

    for(auto it = command_queue.rbegin(); it != command_queue.rend(); ++it) {
        (*it)->undo(ch);
    }

    return EXIT_SUCCESS;
}