#include "cell.h"

void Cell::Die() {
    is_alive = false;
    std::cout << "Cell died\n";
}

void Cell::ConsumeEnergy() {
    energy--;
    std::cout << "Cell consumed energy, left energy: " << energy << '\n';
    if (energy <= 0) {
        Die();
    }
}