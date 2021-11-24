#include "busca.h"

void Contacts::add(Contact c) {
    this->contacts.push_back(c);
}

void Contacts::remove(std::string name) {
    for(int i = 0; i < this->contacts.size(); i++){
        if(contacts[i].name == name){
            contacts.erase(contacts.begin() + i);
            return;
        }
    }
    std::cout << "name not existent";
}

Contact* Contacts::getContact(std::string name){
    for(auto& x : this->contacts){
        if(x.name == name){
            return &x;
        }
    }
    return nullptr;
}

std::vector<Contact> Contacts::search(std::string pattern) {
    std::vector<Contact> temp;
    for(auto& x : contacts){
        if(x.name.find(pattern) != std::string::npos || x.prefix.find(pattern) != std::string::npos){
            temp.push_back(x);
            continue;
        }
        for(auto& y : x.phones){
            if(y.id.find(pattern) != std::string::npos || y.number.find(pattern) != std::string::npos){
                temp.push_back(x);
                break;
            }
        }
    }
    return temp;
}

std::string Contacts::toString(){
    std::stringstream ss;
    for(auto& x : this->contacts){
        ss << x.name << ": " << x.phones[0];
    }
    return ss.str();
}