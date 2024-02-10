//
// Created by ninte on 11/20/2023.
//
#include "DoodleBug.h"

DoodleBug::DoodleBug() {
    this->symbol ='D';
    this->starveCount = 10;
    this->breedCount = 0;
}

void DoodleBug::movement(int& x, int& y, mt19937& randomNumberGenerator, Grid& grid,
                         vector<unique_ptr<Organisms>>& critterList) {
    bool didMove = false;
    if (starveCount == 0) {
        Organisms::death(x, y, grid, critterList, '.');
    }
    else if (breedCount == 10) {
        breeding(x, y, grid, randomNumberGenerator, critterList);
        breedCount = -1;
    }
    if (starveCount != 0) {
        for (int i = y - 1; i < y + 2; i++) {
            for (int j = x - 1; j < x + 2; j++) {
                if (i >= 0 && i < grid.getSize() && j >= 0 && j < grid.getSize()) {
                    if (!didMove) {
                        if (grid.lookForOrganism(j, i, 'Q') ||
                            grid.lookForOrganism(j, i, 'y') ||
                            grid.lookForOrganism(j, i, 'x')) {
                            grid.getCell(j, i).removeOrganism();
                            grid.getCell(j, i).setSymbol(this->symbol);
                            grid.getCell(j, i).putOrganism();
                            grid.getCell(x, y).removeOrganism();
                            grid.getCell(x, y).setSymbol('.');
                            didMove = true;
                            x = j;
                            y = i;
                            setXCoord(j);
                            setYCoord(i);
                            starveCount = 10;
                        }
                    }
                }
            }
        }
        if (!didMove) {
            Organisms::movement(x, y, randomNumberGenerator, grid, critterList);
            starveCount--;
        }
        breedCount++;
    }
}

void DoodleBug::breeding(int x, int y, Grid &grid, mt19937 &randomNumberGenerator,
                         vector<unique_ptr<Organisms>> &critterList) {
    int numberOfNewDoodleBugs = 0;
    while (numberOfNewDoodleBugs < 2) {
        //spawn new doodlebugs
        vector<pair<int, int>> spawnLocations = grid.validSpawnLocations(x, y);
        if (spawnLocations.empty()) {
            numberOfNewDoodleBugs = 2;
        } else {
            critterList.push_back(make_unique<DoodleBug>());
            std::uniform_int_distribution<int> newSpawnSpot(0, spawnLocations.size() - 1);
            pair<int, int> newCoords = spawnLocations[newSpawnSpot(randomNumberGenerator)];
            critterList[critterList.size() - 1]->setXCoord(newCoords.first);
            critterList[critterList.size() - 1]->setYCoord(newCoords.second);
            grid.getCell(newCoords.second, newCoords.first).putOrganism();
            grid.getCell(newCoords.second, newCoords.first).setSymbol(critterList[critterList.size() - 1]->getSymbol());
            numberOfNewDoodleBugs++;
        }
    }
}

char DoodleBug::getSymbol() {
    return this->symbol;
}
