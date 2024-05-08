#include <iostream>
#include <string>
#include <vector>
#include <mutex>

class Item {
public:
    Item(const std::string& name) : _name(name) {}
    const std::string& getName() const { return _name; }
private:
    std::string _name;
};

class Inventory
{
public:
    static Inventory & Instance()
    {
        static Inventory  _instance;
        return _instance;
    }

    void addItem(const std::string& itemName) {
        std::lock_guard<std::mutex> lock(_mutex);
        _items.emplace_back(itemName);
    }

    void printInventory() const {
        std::lock_guard<std::mutex> lock(_mutex);
        std::cout << "Inventory:\n";
        for (const auto& item : _items) {
            std::cout << "- " << item.getName() << "\n";
        }
    }

    Inventory (const Inventory &) = delete;
    Inventory & operator=(const Inventory &) = delete;

private:
    Inventory () = default;
    ~Inventory () = default;

    std::vector<Item> _items;
    mutable std::mutex _mutex;
};