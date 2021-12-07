#include "bacteria.h"

Bacteria::Bacteria(std::string type, bool is_visible) {
    this->type = type;
    this->is_visible = is_visible;
}

void Bacteria::Die() {
    is_alive = false;
}