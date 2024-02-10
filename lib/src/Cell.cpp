//
// Created by ninte on 11/20/2023.
//

#include "Cell.h"

char Cell::getSymbol() {
    return organismSymbol;
}

bool Cell::getOrganism() {
    return organismPresent;
}

void Cell::putOrganism() {
    organismPresent = true;
}
void Cell::removeOrganism() {
    organismPresent = false;
}

void Cell::setSymbol(char symbol) {
    organismSymbol = symbol;
}


