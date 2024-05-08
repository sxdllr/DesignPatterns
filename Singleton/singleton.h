#include <iostream>
#include <string>
#include <vector>

class Singleton
{
public:
    static Singleton* Instance()
    {
        if (!_instance)
        {
            _instance = new Singleton;
        }
        return _instance;
    }

    void PrintRegister()
    {
        std::cout << "Accessing the Singleton\n";
        for (auto i : _registry)
            std::cout << i << "\n";
    }

    void Register(std::string s)
    {
        _registry.push_back(s);
    }

private:
    Singleton() { std::cout << "Singleton was created\n"; }
    ~Singleton() { std::cout << "Singleton was deleted\n"; }

    static Singleton* _instance;
    std::vector<std::string> _registry;
};

Singleton* Singleton::_instance = nullptr;