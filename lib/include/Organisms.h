//
// Created by ninte on 11/20/2023.
//

#ifndef PREDORPREY_ORGANISMS_H
#define PREDORPREY_ORGANISMS_H

#include <random>
#include <memory>
#include "Grid.h"
using namespace std;

class Organisms {
private:
    char symbol{'.'};
    int xCoord{0};
    int yCoord{0};
public:
    Organisms() = default;
    virtual void movement(int& x, int& y, mt19937& randomNumberGenerator, Grid& grid,
                          vector<unique_ptr<Organisms>>& critterList);
    Organisms (const Organisms& arg);
    virtual void death(int x, int y, Grid& grid, vector<unique_ptr<Organisms>>& critterList, char getSymbol);
    virtual char getSymbol();

    virtual int getXCoord();
    virtual int getYCoord();
    virtual void setXCoord(int x);
    virtual void setYCoord(int y);
};

#endif //PREDORPREY_ORGANISMS_H
