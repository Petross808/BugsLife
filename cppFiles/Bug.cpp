//
// Created by petrs on 10.04.2024.
//

#include <iostream>
#include "../headerFiles/Bug.h"

Bug::Bug(string type, int id, int x, int y, Bug::Direction direction, int size) {
    this->type = std::move(type);
    this->id = id;
    this->position = pair<int, int>(x,y);
    this->direction = direction;
    this->size = size;
    this->alive = true;
    this->diedTo = -1;
}

bool Bug::isWayBlocked() {
    return false;
}

string Bug::getType() const
{
    return this->type;
}

int Bug::getId() const
{
    return this->id;
}

pair<int, int> Bug::getPosition() const
{
    return position;
}

int Bug::getSize() const
{
    return this->size;
}

Bug::Direction Bug::getDirection() const
{
    return this->direction;
}

string Bug::getStatus() const
{
    return this->alive ? "Alive" : "Dead";
}

std::ostream& operator<<(std::ostream& out, const Bug& bug)
{
    out << bug.getOutputString();
    return out;
}

string Bug::getOutputString() const
{
    return to_string(getId()) + " " + getType()[0] + " (" + to_string(getPosition().first) + ", " + to_string(getPosition().second) + ") " + to_string(getSize()) +
           " " + to_string(getDirection()) + " " + getStatus();
}

string Bug::getHistory() const {
    string out = to_string(id) + " " + type + " Path: ";
    for(auto pos: path)
    {
        out += "(" + to_string(pos.first) + ", " + to_string(pos.second) + "), ";
    }
    if(alive)
    {
        out += "Alive!";
    }
    else
    {
        out += "Eaten by " + to_string(diedTo);
    }
    return out;
}
