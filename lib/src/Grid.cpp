//
// Created by ninte on 11/20/2023.
//

#include "Grid.h"

Grid::Grid(int size) {
    this->gridSize = size;
    this->grid.resize(gridSize);
    for (int i = 0; i < gridSize; i++) {
        this->grid[i].resize(gridSize);
    }
}

Grid::Grid(const Grid &arg) {
    this->gridSize = arg.gridSize;
    this->grid = arg.grid;
}

void Grid::printGrid() {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            cout << grid[i][j].getSymbol() << ' ';
        }
        cout << endl;
    }
    cout << "\n-----------------------------------------------------------" << endl;
}

void Grid::fillCell(int x, int y, char symbol) {
    grid[y][x].setSymbol(symbol);
    grid[y][x].putOrganism();
}

int Grid::getSize() {
    return this->gridSize;
}

vector<vector<Cell>>& Grid::getGrid() {
    return this->grid;
}

Cell& Grid::getCell(int x, int y) {
    return grid[y][x];
}

bool Grid::lookForOrganism(int x, int y, char symbol) {
    if (x >= 0 && x < getSize() && y >= 0 && y < getSize()) {
        if (getCell(x, y).getOrganism()) {
            if (getCell(x, y).getSymbol() == symbol) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

vector<pair<int, int>> Grid::validSpawnLocations(int x, int y) {
    vector<pair<int, int>> spawnLocations;
    for (int i = y - 2; i < y + 3; i++) {
        for (int j = x - 2; j < x + 3; j++) {
            if (i >= 0 && i < getSize() && j >= 0 && j < getSize()) {
                if (!getCell(j, i).getOrganism()) {
                    spawnLocations.emplace_back(j, i);
                }
            }
        }
    }
    return spawnLocations;
}
