#include <iostream>

#ifndef kid_h
#define kid_h

class Kid {
    std::string name = "";
        int age;
        
    public:
        Kid(std::string name, int age);
        int getAge();
        std::string getName();
        bool operator==(const Kid& kid);
        bool operator!=(const Kid& kid);
};
#endif // kid_h