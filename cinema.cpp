#include <iostream>
#include <memory>
#include <algorithm>
#include <list>

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
                std::cout << "Reserve cancelled" << std::endl;
                return;
            }
        }
    }

    void reserve(std::string id, std::string phone, int pos)
    {
        auto existent = std::find_if(chairs.begin(), chairs.end(), [id](std::shared_ptr<Cliente> c) { 
            if(c != nullptr)
                return c->id == id;
            else
                return false;
            });
        if (existent != chairs.end()){
            std::cout << "Id already exists\n";
            return;
        }
        auto temp = std::make_shared<Cliente>(Cliente(id, phone));
        if(pos >= chairs.size())
        {
            std::cout << "Invalid position" << std::endl;
            return;
        }
        if (*std::next(chairs.begin(), 2) != nullptr)
        {
            std::cout << "Chair already resesrved" << std::endl;
            return;
        }
        auto index = std::next(chairs.begin(), pos);
        *index = temp;
        std::cout << "Chair reserved\n";
    }

    void print()
    {
        int x = 0;
        for (auto it = chairs.begin(); it != chairs.end(); it++)
        {
            if (*it != nullptr)
            {
                std::cout << x <<  " " << (*it)->id << " " << (*it)->phone << std::endl;
            } else
            {
                std::cout << x << " null" << std::endl;
            }
            x++;
        }
    }
};

int main() {
    Sala sala(3);
    sala.print();
    sala.reserve("1", "123", 0);
    sala.print();
    sala.reserve("2", "456", 1);
    sala.reserve("3", "789", 2);
    sala.print();
    sala.cancel("1");
    sala.reserve("2", "123", 0);
    sala.print();
    return 0;
}
