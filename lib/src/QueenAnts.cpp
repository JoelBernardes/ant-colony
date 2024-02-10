//
// Created by ninte on 11/20/2023.
//

#include "QueenAnts.h"
#include "MatingAnts.h"
#include "WorkerAnts.h"

QueenAnts::QueenAnts() {
    this->symbol = 'Q';
    this->deathCount = 60;
    this->breedCooldown = 0;
    this->pregnantCount = 30;
    this->isPregnant = false;
}

void QueenAnts::movement(int& x, int& y, mt19937 &randomNumberGenerator, Grid &grid,
                         vector<unique_ptr<Organisms>> &critterList) {
    bool isAlive = true;
    if (grid.getCell(x, y).getSymbol() == 'D') {
        //eaten
        isAlive = false;
        Organisms::death(x, y, grid, critterList, grid.getCell(x, y).getSymbol());
    }
    else if (deathCount == 0) {
        Organisms::death(x, y, grid, critterList, '.');
    }
    else if (pregnantCount == 0 && isPregnant) {
        breeding(x, y, randomNumberGenerator, grid, critterList);
        deathCount = 60;
        breedCooldown = 15;
        isPregnant = false;
    } else if (isPregnant){
        pregnantCount--;
    }
    else if (!isPregnant && breedCooldown == 0) {
        //do search
        //if it finds
        for (int i = y - 1; i < y + 2; i++) {
            for (int j = x - 1; j < x + 2; j++) {
                if (grid.lookForOrganism(j, i, 'y')) {
                    isPregnant = true;
                    pregnantCount = 30;
                }
            }
        }
    }
    if (!isPregnant && isAlive) {
        Organisms::movement(x, y, randomNumberGenerator, grid, critterList);
    }
    deathCount--;
}

void QueenAnts::breeding(int x, int y, mt19937 &randomNumberGenerator, Grid &grid,
                         vector<unique_ptr<Organisms>> &critterList) {
    int numberOfNewAnts = 0;
    while (numberOfNewAnts < 10) {
        //spawn new ants
        vector<pair<int, int>> spawnLocations = grid.validSpawnLocations(x, y);
        if (spawnLocations.empty()) {
            numberOfNewAnts = 10;
        } else {
            std::uniform_int_distribution<int> newSpawnType(0, 10000); //type of bug
            int antType = newSpawnType(randomNumberGenerator);
            if (antType <= 50) {
                //spawn Queen ant
                critterList.push_back(make_unique<QueenAnts>());
            } else if (antType <= 2775) {
                //spawn mating ant
                critterList.push_back(make_unique<MatingAnts>());
                numberOfNewAnts++;
            } else {
                //spawn worker ant
                critterList.push_back(make_unique<WorkerAnts>());
            }
            std::uniform_int_distribution<int> newSpawnSpot(0, spawnLocations.size() - 1);
            pair<int, int> newCoords = spawnLocations[newSpawnSpot(randomNumberGenerator)];
            critterList[critterList.size() - 1]->setXCoord(newCoords.first);
            critterList[critterList.size() - 1]->setYCoord(newCoords.second);
            grid.getCell(newCoords.second, newCoords.first).putOrganism();
            grid.getCell(newCoords.second, newCoords.first).setSymbol(critterList[critterList.size() - 1]->getSymbol());
            numberOfNewAnts++;
        }
    }
}

char QueenAnts::getSymbol() {
    return this->symbol;
}
