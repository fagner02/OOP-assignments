#include <iostream>
#include <vector>
#include <regex>
#include "contato.h"


Phone::Phone(std::string number, std::string id) {
    this->number = number;
    this->id = id;
}

bool Phone::validate(){
    std::regex pattern("[0-9.\\(\\)]+");
    std::smatch match;
    std::regex_match(number, match, pattern);
    if(match.length() < number.length()){
        return false;
    }
    return true;
}


Contact::Contact(std::string name, std::vector<Phone> phones){
    this->name = name;
    this->phones = phones;
}

void Contact::addPhone(Phone phone) {
    if(!phone.validate()) {
        std::cout << "Invalid phone" << std::endl;
        return;
    }
    phones.push_back(phone);
}

void Contact::remove(int index) {
    if(index < 0 || index >= phones.size()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    phones.erase(phones.begin() + index);
}

void Contact::show() {
    for(auto phone : phones) {
        std::cout << name << phone.number << "\n";
    }
}
