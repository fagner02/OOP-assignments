#include <iostream>
#include <sstream>
#include <vector>
#include "contato.h"

#ifndef busca_h
#define busca_h
class Contacts {
    public:
    std::vector<Contact> contacts;
    
    void add(Contact c);

    void remove(std::string name);
    
    std::vector<Contact> search(std::string pattern);

    Contact* getContact(std::string name);
    
    std::string toString();
};
#endif /* busca_h */