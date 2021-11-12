#include <iostream>
#include <list>
#include "kid.h"

#ifndef pula_h
#define pula_h
class Trampoline {
    std::list<Kid> playing;
    std::list<Kid> waiting;
    public:
    static Kid removeKid(std::string name, std::list<Kid> &kids);
    Trampoline();
    void arrive(Kid kid);
    void in();
    void out();
    void print();
    Kid remove(std::string name);
};
#endif // pula_h