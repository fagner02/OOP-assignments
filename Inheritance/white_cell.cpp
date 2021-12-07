#include "white_cell.h"

void WhiteCell::PresentAntigen(Bacteria& b) {
    std::cout << "Bacteria " << b.type << " presented as antigen\n";
    b.is_visible = true;
    ConsumeEnergy();
}
void WhiteCell::Kill(Bacteria& b) {
    if (!is_alive) {
        std::cout << "WhiteCell called is dead\n";
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
    std::cout << "Bacteria " << b.type << " killed by WhiteCell\n";
    this->ConsumeEnergy();
}