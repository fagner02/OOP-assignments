#include "busca.h"

void Contacts::add(Contact c) {
    // this->contacts.push_back(c);
    // std::sort(this->contacts.begin(), this->contacts.end(), [](Contact x, Contact y){
    //     return (x.name.compare(y.name) < 0);
    // });
    int insertPos = 0;
    for(int i = 0; i < this->contacts.size(); i++){
        if(!(this->contacts[i].name.compare(c.name) < 0)){
            break;
        }
        insertPos = i+1;
    }
    this->contacts.insert(this->contacts.begin() + insertPos, c);
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
    std::string m = std::max_element(this->contacts.begin(), this->contacts.end(), [](Contact& a, Contact& b){
        return a.name.length() < b.name.length();
    })->name;

    for(auto& x : this->contacts){
        ss << x.name << ": " ;
        for(int i = 0; i < x.phones.size(); i++){
            if(i == 0){
                ss << std::string(m.length() - x.name.length(), ' ')<< x.phones[i].number << "\n";
                continue;
            }
            ss << std::string(m.length() + 2, ' ') << x.phones[i].number << "\n";
        }
    }
    
    return ss.str();
}