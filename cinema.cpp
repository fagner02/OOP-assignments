#include <iostream>
#include <list>
#include <memory>
// #include <thread>
// #include <chrono>
// #include <mutex>

class Cliente
{
public:
    std::string phone;
    std::string id;
    Cliente(std::string id, std::string phone) : id(id), phone(phone) {}
};

class Sala
{
    std::list<std::shared_ptr<Cliente>> chairs;

public:
    Sala(int size) : chairs(size, nullptr) {}

    void cancel(std::string id)
    {
        for (auto it = chairs.begin(); it != chairs.end(); it++)
        {
            if ((*it)->id == id)
            {
                *it = nullptr; 
                return;
            }
        }
    }

    void reserve(std::string id, std::string phone, int pos)
    {
        auto temp = std::make_shared<Cliente>(Cliente(id, phone));
        if (*std::next(chairs.begin(), 2) != nullptr)
        {
            std::cout << "Sala cheia" << std::endl;
            return;
        }
        chairs.push_back(temp);
    }

    void print()
    {
        for (auto it = chairs.begin(); it != chairs.end(); it++)
        {
            if (*it != nullptr)
            {
                std::cout << (*it)->id << " " << (*it)->phone << std::endl;
            } else
            {
                std::cout << "null" << std::endl;
            }
        }
    }
};

int main() {
    Sala sala(3);
    sala.print();
    sala.reserve("1", "123", 0);
    sala.reserve("2", "456", 1);
    sala.reserve("3", "789", 2);
    sala.print();
    sala.cancel("1");
    sala.print();
    return 0;
}