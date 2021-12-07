#include <iostream>
#include <vector>
#include "immune_cell.h"
#include "bacteria.h"
#include "cell.h"
#include "white_cell.h"

int main() {
    std::vector<Bacteria> bacteria{
        Bacteria("N",true), Bacteria("M",true),
        Bacteria("A",false), Bacteria("B",true)
    };

    std::vector<WhiteCell> white_cells{
        WhiteCell(), WhiteCell(),
    };

    std::vector<ImmuneCell*> immune_cells{
        new ImmuneCell(),
        new ImmuneCell(),
        (ImmuneCell*)&white_cells[0],
        (ImmuneCell*)&white_cells[1]
    };

    std::vector<Cell*> cells{
        new Cell(),
        new Cell(),
        (Cell*)immune_cells[0],
        (Cell*)immune_cells[1],
        (Cell*)immune_cells[2],
        (Cell*)immune_cells[3],
    };

    std::cout << 0 << '\n';
    immune_cells[2]->Kill(bacteria[0]);
    std::cout << 1 << '\n';
    immune_cells[0]->Kill(bacteria[2]);
    std::cout << 2 << '\n';
    white_cells[0].PresentAntigen(bacteria[2]);
    std::cout << 3 << '\n';
    immune_cells[0]->Kill(bacteria[2]);
    std::cout << 4 << '\n';
    white_cells[1].Kill(bacteria[3]);
    std::cout << 5 << '\n';
    immune_cells[0]->Kill(bacteria[1]);
    std::cout << 6 << '\n';
    immune_cells[1]->Kill(bacteria[3]);
    std::cout << 7 << '\n';
    immune_cells[0]->Kill(bacteria[1]);

    std::cout << "\nCells:" << '\n';
    for (int i = 0; i < cells.size(); i++) {
        std::cout << cells[i]->type << " " << i << " - energy left: "
            << cells[i]->energy << ", is alive: " << (cells[i]->is_alive ? "yes" : "no") << '\n';
    }

    std::cout << "\nImmuneCells:" << '\n';
    for (int i = 0; i < immune_cells.size(); i++) {
        std::cout << immune_cells[i]->type << " " << i << " - energy left: " << immune_cells[i]->energy
            << ", is alive: " << (immune_cells[i]->is_alive ? "yes" : "no") << '\n';
    }

    std::cout << "\nWhiteCells:" << '\n';
    for (int i = 0; i < white_cells.size(); i++) {
        std::cout << white_cells[i].type << " " << i << " - energy left: " << white_cells[i].energy
            << ", is alive: " << (white_cells[i].is_alive ? "yes" : "no") << '\n';
    }
}