//
// Created by ninte on 11/20/2023.
//
#include "Organisms.h"

Organisms::Organisms(const Organisms &arg) {
    this->xCoord = arg.xCoord;
    this->yCoord = arg.yCoord;
    this->symbol - arg.symbol;
}

void Organisms::movement(int& x, int& y, mt19937& randomNumberGenerator, Grid& grid,
                         vector<unique_ptr<Organisms>>& critterList) {
    std::uniform_int_distribution<int> movement(-1, 1); //movement
    int newX = x + movement(randomNumberGenerator);
    int newY = y + movement(randomNumberGenerator);
    while (newY == y && newX == x) { //make sure it doesnt pick zero zero for move cords
        newX = x + movement(randomNumberGenerator);
        newY = y + movement(randomNumberGenerator);
    }
    //if location exists
    if (newX >= 0 && newX < grid.getSize() && newY >= 0 && newY < grid.getSize()) {
        //if not occupied
        if (!grid.getCell(newX, newY).getOrganism()) {
            char organismSymbol = grid.getCell(x, y).getSymbol();
            grid.getCell(newX, newY).setSymbol(organismSymbol);
            grid.getCell(newX, newY).putOrganism();
            grid.getCell(x, y).removeOrganism();
            grid.getCell(x, y).setSymbol('.');
        } else {
            newX = x;
            newY = y;
        }
    } else if (newX < 0 && newY >= 0 && newY < grid.getSize()) { //left
        if (y - newY == 1) { //up left
            if (newY - 1 > 0) { //two up
                if (!grid.getCell(x, newY - 1).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(x, newY - 1).setSymbol(organismSymbol);
                    grid.getCell(x, newY - 1).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX = x;
                    newY--;
                } else {
                    newX = x;
                    newY = y;
                }
            }
            else { //up right
                if (!grid.getCell(x + 1, newY).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(x + 1, newY).setSymbol(organismSymbol);
                    grid.getCell(x + 1, newY).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX = x + 1;
                } else {
                    newX = x;
                    newY = y;
                }
            }
        } else if (y - newY == -1) { //down left
            if (newY + 1 < grid.getSize()) { //two down
                if (!grid.getCell(x, newY + 1).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(x, newY + 1).setSymbol(organismSymbol);
                    grid.getCell(x, newY + 1).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX = x;
                    newY++;
                }
                else {
                    newX = x;
                    newY = y;
                }
            }
            else { //down right
                if (!grid.getCell(x + 1, newY).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(x + 1, newY).setSymbol(organismSymbol);
                    grid.getCell(x + 1, newY).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX = x + 1;
                }
                else {
                    newX = x;
                    newY = y;
                }
            }
        }
        else { //just left
            newX = x;
            newY = y;
        }
    } else if (newX >= grid.getSize() && newY >= 0 && newY < grid.getSize()) { //right
        if (y - newY == 1) { //up right
            if (newY - 1 >= 0) { //two up
                if (!grid.getCell(x, newY - 1).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(x, newY - 1).setSymbol(organismSymbol);
                    grid.getCell(x, newY - 1).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX = x;
                    newY--;
                } else {
                    newX = x;
                    newY = y;
                }
            }
            else { //up left
                if (!grid.getCell(x - 1, newY).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(x - 1, newY).setSymbol(organismSymbol);
                    grid.getCell(x - 1, newY).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX = x - 1;
                } else {
                    newX = x;
                    newY = y;
                }
            }
        } else if (y - newY == -1) { //down right
            if (newY + 1 < grid.getSize()) { //two down
                if (!grid.getCell(x, newY + 1).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(x, newY + 1).setSymbol(organismSymbol);
                    grid.getCell(x, newY + 1).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX = x;
                    newY++;
                }
                else {
                    newX = x;
                    newY = y;
                }
            }
            else { //down left
                if (!grid.getCell(x - 1, newY).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(x - 1, newY).setSymbol(organismSymbol);
                    grid.getCell(x - 1, newY).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX = x - 1;
                } else {
                    newX = x;
                    newY = y;
                }
            }
        }
        else { //just right
            newX = x;
            newY = y;
        }
    } else if (newY < 0 && newX >= 0 && newX < grid.getSize()) { //up
        if (x - newX == 1) { //up left
            if (newX - 1 >= 0) { //two left
                if (!grid.getCell(newX - 1, y).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(newX - 1, y).setSymbol(organismSymbol);
                    grid.getCell(newX - 1, y).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX--;
                    newY = y;
                } else {
                    newX = x;
                    newY = y;
                }
            } else { //down left
                if (!grid.getCell(newX, y).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(newX, y + 1).setSymbol(organismSymbol);
                    grid.getCell(newX, y + 1).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newY = y + 1;
                } else {
                    newX = x;
                    newY = y;
                }
            }
        } else if (x - newX == -1) { //up right
            if (newX + 1 < grid.getSize()) { //two right
                if (!grid.getCell(newX + 1, y).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(newX + 1, y).setSymbol(organismSymbol);
                    grid.getCell(newX + 1, y).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX++;
                    newY = y;
                } else {
                    newX = x;
                    newY = y;
                }
            } else { //down right
                if (!grid.getCell(newX, y + 1).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(newX, y + 1).setSymbol(organismSymbol);
                    grid.getCell(newX, y + 1).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newY = y + 1;
                } else {
                    newX = x;
                    newY = y;
                }
            }
        } else { //just up
            newX = x;
            newY = y;
        }
    }
    else if (newY >= grid.getSize() && newX >= 0 && newX < grid.getSize()) { //down
        if (x - newX == 1) { //down left
            if (newX - 1 >= 0) { //two left
                if (!grid.getCell(newX - 1, y).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(newX - 1, y).setSymbol(organismSymbol);
                    grid.getCell(newX - 1, y).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX--;
                    newY = y;
                } else {
                    newX = x;
                    newY = y;
                }
            } else { //up left
                if (!grid.getCell(newX, y - 1).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(newX, y - 1).setSymbol(organismSymbol);
                    grid.getCell(newX, y - 1).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newY = y - 1;
                } else {
                    newX = x;
                    newY = y;
                }
            }
        } else if (x - newX == -1) { //down right
            if (newX + 1 < grid.getSize()) { //two right
                if (!grid.getCell(newX + 1, y).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(newX + 1, y).setSymbol(organismSymbol);
                    grid.getCell(newX + 1, y).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newX++;
                    newY = y;
                } else {
                    newX = x;
                    newY = y;
                }
            } else { //up right
                if (!grid.getCell(newX, y - 1).getOrganism()) { //if not occupied
                    char organismSymbol = grid.getCell(x, y).getSymbol();
                    grid.getCell(newX, y - 1).setSymbol(organismSymbol);
                    grid.getCell(newX, y - 1).putOrganism();
                    grid.getCell(x, y).removeOrganism();
                    grid.getCell(x, y).setSymbol('.');
                    newY = y - 1;
                } else {
                    newX = x;
                    newY = y;
                }
            }
        } else { //just down
            newX = x;
            newY = y;
        }
    } else { //in a corner trying to go diagonally out of bounds
        newX = x;
        newY = y;
    }
    x = newX;
    y = newY;
    setXCoord(newX);
    setYCoord(newY);
}

void Organisms::death(int x, int y, Grid& grid, vector<unique_ptr<Organisms>>& critterList, char getSymbol) {
    grid.getCell(x, y).setSymbol(getSymbol);
    if (grid.getCell(x, y).getSymbol() == '.') {
        grid.getCell(x, y).removeOrganism();
    }
    //remove from list
    vector<unique_ptr<Organisms>> tempVector;

    for (auto & i : critterList) {
        if (i.get() != this) {
            tempVector.emplace_back(i.release());
        }
    }
    critterList.clear();

    for (auto& organism : tempVector) {
        critterList.push_back(std::move(organism));
    }
}

char Organisms::getSymbol() {
    return symbol;
}

void Organisms::setXCoord(int x) {
    this->xCoord = x;
}

int Organisms::getXCoord() {
    return xCoord;
}

void Organisms::setYCoord(int y) {
    this->yCoord = y;
}

int Organisms::getYCoord() {
    return yCoord;
}
