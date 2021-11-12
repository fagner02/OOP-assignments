#include "pula.h"

Trampoline::Trampoline(){

}

Kid Trampoline::removeKid(std::string name, std::list<Kid> &kids){
    Kid kid(name, 0);

    kids.remove(kid);

    return kid;
}

void Trampoline::arrive(Kid kid){
    waiting.push_front(kid);
}

void Trampoline::in(){
    std::cout << waiting.front().getName() << " in\n";
    playing.push_back(waiting.front());
    waiting.pop_front();
}

void Trampoline::out(){
    std::cout << playing.front().getName() << " out\n";
    waiting.push_back(playing.front());
    playing.pop_front();
}

Kid Trampoline::remove(std::string name){
    Kid kid= Kid("", 0); 
    for(auto x : waiting){
        if(x.getName() == name){
            kid = x;
        }
    }
    waiting.remove(kid);
    
    for(auto x : playing){
        if(x.getName() == name){
            kid = x;
        }
    }
    playing.remove(kid);

    return kid;
}
void Trampoline::print(){
    std::cout << "waiting: \n";
    for(auto i = waiting.rbegin(); i != waiting.rend(); i++){
        std::cout << i->getName() << "\n";
    }
    std::cout << "playing: \n";
    for(auto i = playing.rbegin(); i != playing.rend(); i++){
        std::cout << i->getName() << "\n";
    }
}