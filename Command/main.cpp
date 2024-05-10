#include "command.h"

//way to take objects && model them as commands that execute actions

int main()
{
    Character ch("Yurii");
    Move w;
    w.execute(ch);

    return EXIT_SUCCESS;
}
