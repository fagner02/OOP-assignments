#include <iostream>

#pragma once
class Bacteria {
public:
    bool is_alive = true;
    bool is_visible;
    std::string type;
    Bacteria(std::string type, bool is_visible);
    void Die();
};