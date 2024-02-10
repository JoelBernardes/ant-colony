//
// Created by ninte on 11/20/2023.
//

#ifndef PREDORPREY_QUEENANTS_H
#define PREDORPREY_QUEENANTS_H

#include "Organisms.h"

class QueenAnts : public Organisms {
private:
    char symbol;
    int breedCooldown{};
    int pregnantCount{};
    int deathCount{};
    bool isPregnant;
public:
    QueenAnts();
    void movement(int& x, int& y, mt19937& randomNumberGenerator, Grid& grid,
                  vector<unique_ptr<Organisms>>& critterList) override;
    void breeding(int x, int y, mt19937 &randomNumberGenerator, Grid &grid,
                  vector<unique_ptr<Organisms>> &critterList);
    virtual char getSymbol() override;

};

#endif //PREDORPREY_QUEENANTS_H
