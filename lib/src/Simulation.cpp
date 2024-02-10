//
// Created by ninte on 11/20/2023.
//

#include "Simulation.h"
#include <random>
#include <thread>

Simulation::Simulation(Grid grid, int doodleBugCount, int queenAntCount,
                       int workerAntCount, int matingAntCount, int randomSeed) {
    this->environment = grid;
    this->doodlebugs.resize(doodleBugCount);
    this->ants.resize(queenAntCount + workerAntCount + matingAntCount);
    this->randomSeed = randomSeed;
    for (auto & doodlebug : doodlebugs) {
        doodlebug = make_unique<DoodleBug>();
    }
    for (auto & ant : ants) {
        if (queenAntCount > 0) {
            ant = make_unique<QueenAnts>();
            queenAntCount--;
        } else if (matingAntCount > 0) {
            ant = make_unique<MatingAnts>();
            matingAntCount--;
        } else if (workerAntCount > 0) {
            ant = make_unique<WorkerAnts>();
            workerAntCount--;
        }
    }
}

void Simulation::runSimulation() {
    cout << "Staring the simulation: \n" << endl;
    mt19937 randomNumberGenerator(randomSeed); //0 -> gridsize -1
    std::uniform_int_distribution<int> gridRange(0, environment.getSize() - 1); //get grid size
    //place randomly on the board
    //for each doodlebug in doodlebug list
    for (int i = 0; i < doodlebugs.size(); i++) {
        int xCoord = gridRange(randomNumberGenerator);
        int yCoord = gridRange(randomNumberGenerator);
        while (environment.getCell(xCoord, yCoord).getOrganism()) {
            xCoord = gridRange(randomNumberGenerator);
            yCoord = gridRange(randomNumberGenerator);
        }
        environment.fillCell(xCoord, yCoord, doodlebugs[i]->getSymbol());
        doodlebugs[i]->setXCoord(xCoord);
        doodlebugs[i]->setYCoord(yCoord);
    }
    //for each ant in ant list
    for (int i = 0; i < ants.size(); i++) {
        int xCoord = gridRange(randomNumberGenerator);
        int yCoord = gridRange(randomNumberGenerator);
        while (environment.getCell(xCoord, yCoord).getOrganism()) {
            xCoord = gridRange(randomNumberGenerator);
            yCoord = gridRange(randomNumberGenerator);
        }
        environment.fillCell(xCoord, yCoord, ants[i]->getSymbol());
        ants[i]->setXCoord(xCoord);
        ants[i]->setYCoord(yCoord);
    }
    int stepsTaken = 0;
    environment.printGrid();
    //while doodlbug list is not empty or ant list is not empty
    while(!doodlebugs.empty() && !ants.empty()) {
        std::this_thread::sleep_for(1s); //does timestep sleep/pause
        //do doodlebug movement
        for (int i = 0; i < doodlebugs.size(); i++) {
            int doodleX = doodlebugs[i]->getXCoord();
            int doodleY = doodlebugs[i]->getYCoord();
            doodlebugs[i]->movement(doodleX,
                                    doodleY,
                                    randomNumberGenerator, environment, doodlebugs);
        }
        //do ant movement
        for (int i = 0; i < ants.size(); i++) {
            int antX = ants[i]->getXCoord();
            int antY = ants[i]->getYCoord();
            ants[i]->movement(antX,
                              antY,
                              randomNumberGenerator, environment, ants);
        }
        //print grid
        environment.printGrid();
        stepsTaken++;
        cout << "Steps Taken: " << stepsTaken << "\n" << endl;
    }
    //all of this below is for fun and to test
    if (ants.empty() && doodlebugs.empty()) {
        cout << "Doodlebugs and ants went extinct ¯\\_(ツ)_/¯\n" << endl;
    } else if (ants.empty()) {
        cout << "Doodlebugs win\n" << endl;
    } else {
        cout << "Ants win\n" << endl;
    }
    cout << "Simulation over\n" << endl;
}
