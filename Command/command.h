
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <utility>

float Rnd();

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
        float rnd_x = Rnd();
        float rnd_y = Rnd();
        character.Move(rnd_x, rnd_y);
        _x = rnd_x;
        _y = rnd_y;
        std::cout << character.name << " moved to ("
            << _x << ";" << _y << ") position\n";
    }
    void undo(Character& character) override
    {
        character.Move(-_x,-_y);
        std::cout << character.name << " undo to ("
                  << -_x << ";" << -_y << ") position\n";
    }
private:
    float _x;
    float _y;
};

float Rnd() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(1.f, 10.f);
    float rnd = std::ceil(distribution(gen) * 10) / 10;;
    return rnd;
}