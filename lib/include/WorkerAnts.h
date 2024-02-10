//
// Created by ninte on 11/20/2023.
//

#ifndef PREDORPREY_WORKERANTS_H
#define PREDORPREY_WORKERANTS_H

#include "Organisms.h"

class WorkerAnts : public Organisms {
private:
    int starvationCount{0};
    char symbol;
public:
    WorkerAnts();
    virtual void movement(int& x, int& y, mt19937& randomNumberGenerator, Grid& grid,
                          vector<unique_ptr<Organisms>>& critterList) override;
    virtual char getSymbol() override;

};

#endif //PREDORPREY_WORKERANTS_H
