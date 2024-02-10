//
// Created by ninte on 11/20/2023.
//

#ifndef PREDORPREY_GRID_H
#define PREDORPREY_GRID_H

#include "Cell.h"
#include <vector>
#include <iostream>

using namespace std;

class Grid {
private:
    int gridSize;
    vector<vector<Cell>> grid;
public:
    Grid() = default;
    Grid(int size);
    Grid (const Grid& arg);
    void printGrid();
    void fillCell(int x, int y, char symbol);
    int getSize();
    Cell& getCell(int x, int y);
    bool lookForOrganism(int x, int y, char symbol);
    vector<pair<int, int>> validSpawnLocations(int x, int y);
    vector<vector<Cell>>& getGrid();
};

#endif //PREDORPREY_GRID_H
