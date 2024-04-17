//
// Created by petrs on 10.04.2024.
//

#include "../headerFiles/Hopper.h"

Hopper::Hopper(int id, int x, int y, Bug::Direction direction, int size, int hopLength) : Bug(id,x,y,direction,size)
{
    this->hopLength = hopLength;
};

void Hopper::move() {

}

int Hopper::getHopLength() const
{
    return this->hopLength;
}

string Hopper::getOutputString() const
{
    return to_string(getId()) + " H " + getPosition() + " " + to_string(getSize()) +
           " " + to_string(getDirection()) + " " + to_string(getHopLength()) + " " + getStatus();
}