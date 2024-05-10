
#include <iostream>
#include <string>
#include <utility>

struct Character
{
    float x;
    float y;
    std::string name;
    explicit Character(std::string _name)
        : x(0.f)
        , y(0.f)
        , name(std::move(_name)) {}

    void Move(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
};

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute(Character& _character) = 0;
    virtual void undo(Character& _character) = 0;
};

class Move: public Command
{
public:
    void execute(Character& character) override
    {
        std::cout << character.name << " moved\n";
    }
    void undo(Character& character) override
    {

    }
};