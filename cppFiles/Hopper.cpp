//
// Created by petrs on 10.04.2024.
//

#include "../headerFiles/Hopper.h"
#include <string>
#include <utility>
#include <iostream>

Hopper::Hopper(string type, int id, int x, int y, Bug::Direction direction, int size, int hopLength) : Bug(std::move(type),id,x,y,direction,size)
{
    this->hopLength = hopLength;
};

void Hopper::move() {
    auto pos_over = calculateNewPosition(hopLength);
    this->position = pos_over.first;
    while(pos_over.second != 0)
    {
        this->direction = Direction((this->direction + 1 + (rand() % 3)) % 4);
        pos_over = calculateNewPosition(pos_over.second);
        this->position = pos_over.first;
    }
}

int Hopper::getHopLength() const
{
    return this->hopLength;
}

string Hopper::getOutputString() const
{
    return Bug::getOutputString() + " " + to_string(getHopLength());
}