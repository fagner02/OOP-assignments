#include <iostream>
#include <vector>
#include <regex>

class Phone {
    public:
        std::string number;
        std::string id;

        Phone(std::string number, std::string id) {
            this->number = number;
            this->id = id;
        }

        bool validate(){
            std::regex pattern("[0-9.\\(\\)]+");
            std::smatch match;
            std::regex_match(number, match, pattern);
            if(match.length() < number.length()){
                return false;
            }
            return true;
        }
};

class Contact {
    public:
        std::string prefix;
        std::string name = "";
        std::vector<Phone> phones;

        Contact(std::string name, std::vector<Phone> Phones) : name(name), phones(phones) {}

        void addPhone(Phone phone) {
            if(!phone.validate()) {
                std::cout << "Invalid phone" << std::endl;
                return;
            }
            phones.push_back(phone);
        }

        void remove(int index) {
            if(index < 0 || index >= phones.size()) {
                std::cout << "Invalid index" << std::endl;
                return;
            }
            phones.erase(phones.begin() + index);
        }

        void show() {
            for(auto phone : phones) {
                std::cout << name << phone.number << "\n";
            }
        }
};

int main(){
    Contact contact = Contact("Joao", {Phone("123456789", "123")});
}
