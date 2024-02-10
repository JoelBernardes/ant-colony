//
// Created by ninte on 11/20/2023.
//

#include "WorkerAnts.h"

WorkerAnts::WorkerAnts() {
    this->starvationCount = 5;
    this->symbol = 'x';
}



char WorkerAnts::getSymbol() {
    return this->symbol;
}

void WorkerAnts::movement(int& x, int& y, mt19937 &randomNumberGenerator, Grid &grid,
                          vector<unique_ptr<Organisms>> &critterList) {
    if (grid.getCell(x, y).getSymbol() == 'D') {
        //eaten
        death(x, y, grid, critterList, grid.getCell(x, y).getSymbol());
    }
    else if (starvationCount == 0) {
        death(x, y, grid, critterList, '.');
    } else {
        int xSpot = x;
        int ySpot = y;
        Organisms::movement(x, y, randomNumberGenerator, grid, critterList);
        //if position is same decrease count
        if (grid.getCell(xSpot, ySpot).getSymbol() != '.') {
            starvationCount--;
        }
    }
}
