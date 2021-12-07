#include "immune_cell.h"

ImmuneCell::ImmuneCell() {
    type = "Immune Cell";
}

void ImmuneCell::Kill(Bacteria& b) {
    if (!is_alive) {
        std::cout << "ImmuneCell called is dead\n";
        return;
    }
    if (!b.is_alive) {
        std::cout << "Bacteria is already dead\n";
        return;
    }
    if (!b.is_visible) {
        std::cout << "Bacteria couldn't be detected\n";
        return;
    }
    b.Die();
    std::cout << "Bacteria " << b.type << " killed by ImmuneCell\n";
    this->ConsumeEnergy();
}