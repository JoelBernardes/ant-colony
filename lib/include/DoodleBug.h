//
// Created by ninte on 11/20/2023.
//

#ifndef PREDORPREY_DOODLEBUG_H
#define PREDORPREY_DOODLEBUG_H

#include "Organisms.h"

class DoodleBug : public Organisms {
private:
    char symbol{};
    int starveCount{};
    int breedCount{};
public:
    DoodleBug();
    void movement(int& x, int& y, mt19937& randomNumberGenerator, Grid& grid,
                  vector<unique_ptr<Organisms>>& critterList) override;
    void breeding(int x, int y, Grid &grid, mt19937 &randomNumberGenerator,
                  vector<unique_ptr<Organisms>> &critterList);
    virtual char getSymbol() override;
};

#endif //PREDORPREY_DOODLEBUG_H
