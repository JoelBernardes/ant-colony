//
// Created by ninte on 11/20/2023.
//

#ifndef PREDORPREY_CELL_H
#define PREDORPREY_CELL_H

class Cell {
private:
    bool organismPresent = false;
    char organismSymbol{'.'};

public:
    Cell() = default;
    void putOrganism();
    void removeOrganism();
    void setSymbol(char symbol);
    bool getOrganism();
    char getSymbol();
};

#endif //PREDORPREY_CELL_H
