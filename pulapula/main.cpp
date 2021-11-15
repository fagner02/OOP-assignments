#include <iostream>
#include <list>
#include <sstream>
#include "kid.h"
#include "pula.h"

int main(){
    Trampoline t;
    Kid k("ron", 18), k1("von", 18), k2("jon", 18);
    t.print();
    t.arrive(k);
    t.arrive(k1);
    t.arrive(k2);
    t.remove("von");
    t.print();
    t.in();
    t.in();
    t.in();
    t.print();
}
