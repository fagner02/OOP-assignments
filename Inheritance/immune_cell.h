#include <iostream>
#include "bacteria.h"
#include "cell.h"

#pragma once
class ImmuneCell : public Cell {
public:
    ImmuneCell();
    void virtual Kill(Bacteria& b);
};