#include <iostream>
#include <regex>

#ifndef contato_h
#define contato_h
class Phone {
    public:
        std::string number;
        std::string id;

        Phone(std::string number, std::string id);

        bool validate();
};

class Contact {
    public:
        std::string prefix;
        std::string name = "";
        std::vector<Phone> phones;

        Contact(std::string name, std::vector<Phone> phones);

        void addPhone(Phone phone);
        void remove(int index);
        void show();
};
#endif /* contato_h */