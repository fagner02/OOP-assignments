#include <iostream>

#pragma once
class Cell {
public:
    std::string type = "Common Cell";
    bool is_alive = true;
    int energy = 2;
    Cell() = default;
    void Die();
    void ConsumeEnergy();
};