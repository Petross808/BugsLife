//
// Created by petrs on 10.04.2024.
//

#include "../headerFiles/Hopper.h"
#include <string>
#include <utility>

Hopper::Hopper(string type, int id, int x, int y, Bug::Direction direction, int size, int hopLength) : Bug(std::move(type),id,x,y,direction,size)
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
    return Bug::getOutputString() + " " + to_string(getHopLength());
}