#include "busca_map.h"

void Contacts::add(Contact c) {
    auto& it = contacts.find(c.name);
    if(it == contacts.end()){
        contacts.insert(std::make_pair(c.name, c));
    }else{
        for(auto& x : c.phones){
            it->second.phones.push_back(x);
        }
    }
}

void Contacts::remove(std::string name) {
    auto& it = contacts.find(name);
    if(it != contacts.end()){
        contacts.erase(it);
    }else{
        std::cout << "Contact not found" << std::endl;
    }
}

Contact* Contacts::getContact(std::string name){
    auto& it = contacts.find(name);
    if (it != contacts.end()) {
        return &it->second;
    } else {
        return nullptr;
    }
}

std::vector<Contact> Contacts::search(std::string pattern) {
    std::vector<Contact> temp;
    for(auto& [key, x] : contacts){
        if(key.find(pattern) != std::string::npos || key.find(pattern) != std::string::npos){
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

    for(auto& [key, x] : this->contacts){
        ss << x.name << ": " ;
        for(int i = 0; i < x.phones.size(); i++){
            if(i == 0){
                ss << x.phones[i].number << "\n";
                continue;
            }
            ss << x.phones[i].number << "\n";
        }
    }
    
    return ss.str();
}