#include "kid.h"

int Kid::getAge(){
    return age;
}

std::string Kid::getName(){
    return this->name;
}

Kid::Kid(std::string name, int age): name(name), age(age){
    std::cout << name << age << "\n";
}

bool Kid::operator==(const Kid & kid){
    return (kid.name == this->name);
}

bool Kid::operator!=(const Kid& kid){
    return (kid.name != this->name);
}