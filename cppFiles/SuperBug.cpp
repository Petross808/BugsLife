//
// Created by petrs on 29.04.2024.
//

#include "../headerFiles/SuperBug.h"

SuperBug* SuperBug::lastAddedSuperBug = nullptr;

SuperBug::SuperBug(string type, int id, int x, int y, Bug::Direction direction, int size) : Bug(std::move(type),id,x,y,direction,size)
{
    this->isControlled = true;
    if(lastAddedSuperBug)
    {
        lastAddedSuperBug->setControlled(false);
    }
    lastAddedSuperBug = this;
};

void SuperBug::setControlled(bool controlled) {
    isControlled = controlled;
}

bool SuperBug::getControlled() const {
    return isControlled;
}

SuperBug* SuperBug::getLastAddedSuperBug() {
    return lastAddedSuperBug;
}

void SuperBug::move() {
    if(!isControlled)
    {
        auto pos_over = calculateNewPosition(1);
        while(pos_over.second != 0)
        {
            this->direction = Direction((this->direction + 1 + (rand() % 3)) % 4);
            pos_over = calculateNewPosition(1);
        }
        this->position = pos_over.first;
    }
}

void SuperBug::manualMove(Direction dir)
{
    direction = dir;
    auto pos_over = calculateNewPosition(1);
    this->position = pos_over.first;
}