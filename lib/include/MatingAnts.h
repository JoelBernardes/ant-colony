//
// Created by ninte on 11/20/2023.
//

#ifndef PREDORPREY_MATINGANTS_H
#define PREDORPREY_MATINGANTS_H

#include "Organisms.h"

class MatingAnts : public Organisms {
private:
    int starvationCount{0};
    char symbol;
public:
    MatingAnts();
    virtual void movement(int& x, int& y, mt19937& randomNumberGenerator, Grid& grid,
                          vector<unique_ptr<Organisms>>& critterList) override;
    virtual char getSymbol() override;

};

#endif //PREDORPREY_MATINGANTS_H
