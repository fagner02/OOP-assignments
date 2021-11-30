#include <iostream>
#include <memory>
#include <algorithm>
#include <list>
#include <map>

class Cliente
{
public:
    std::string phone;
    std::string id;
    Cliente(std::string id, std::string phone) : id(id), phone(phone) {}
};

class Sala
{
    std::map<int ,std::shared_ptr<Cliente>> chairs;
public:
    Sala(int size) {
        for(int i = 0; i < size; i++)
        {
            chairs[i] = nullptr;
        }
    }

    void cancel(std::string id)
    {
        
        for (auto it = chairs.begin(); it != chairs.end(); it++)
        {
            if (it->second->id == id)
            {
                it->second = nullptr; 
                std::cout << "Reserve cancelled" << std::endl; 
                return; 
            }
        }
    }

    void reserve(std::string id, std::string phone, int pos)
    {
        auto existent = std::find_if(chairs.begin(), chairs.end(), 
        [id](const std::pair<int, std::shared_ptr<Cliente>>& p) { 
            if(p.second != nullptr)
                return p.second->id == id;
            else
                return false;
        });
        if (existent != chairs.end()){
            std::cout << "Id already exists\n";
            return;
        }
        auto temp = std::make_shared<Cliente>(Cliente(id, phone));
        if(pos >= chairs.size()) {
            std::cout << "Invalid position" << std::endl;
            return;
        }
        if (chairs[pos] != nullptr) {
            std::cout << "Chair already reserved" << std::endl;
            return;
        }
        chairs[pos] = temp; 
        std::cout << "Chair reserved\n";
    }

    void print()
    {
        int x = 0;
        for (auto it = chairs.begin(); it != chairs.end(); it++)
        {
            if (it->second != nullptr)
            {
                std::cout << x <<  " " << it->second->id << " " << it->second->phone << std::endl;
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