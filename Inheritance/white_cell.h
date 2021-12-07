#include "bacteria.h"
#include "immune_cell.h"

#pragma once
class WhiteCell : public ImmuneCell {
public:
    std::string type = "White Cell";
    WhiteCell() = default;
    void PresentAntigen(Bacteria& b);
    void Kill(Bacteria& b);
};