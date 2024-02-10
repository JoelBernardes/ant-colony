//
// Created by ninte on 11/20/2023.
//

#ifndef PREDORPREY_SIMULATION_H
#define PREDORPREY_SIMULATION_H

#include <memory>
#include "Grid.h"
#include "Organisms.h"
#include "DoodleBug.h"
#include "QueenAnts.h"
#include "MatingAnts.h"
#include "WorkerAnts.h"

class Simulation {
private:
    Grid environment;
    vector<unique_ptr<Organisms>> ants;
    vector<unique_ptr<Organisms>> doodlebugs;
    int randomSeed;
public:
    Simulation(Grid grid, int doodleBugCount, int queenAntCount,
               int workerAntCount, int matingAnt, int randomSeed);
    void runSimulation();
};

#endif //PREDORPREY_SIMULATION_H
