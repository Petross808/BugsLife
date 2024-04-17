//
// Created by petrs on 10.04.2024.
//

#include <iostream>
#include "../headerFiles/Bug.h"

Bug::Bug(string type, int id, int x, int y, Bug::Direction direction, int size) {
    this->type = type;
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

int Bug::getId() const
{
    return this->id;
}

string Bug::getPosition() const
{
    return "(" + to_string(this->position.first) + ", " + to_string(this->position.second) + ")";
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

void Bug::displayHistory() const {
    cout << id << " " << type << " Path: ";
    for(auto pos: path)
    {
        cout << "(" << pos.first << ", " << pos.second << "), ";
    }
    if(alive)
    {
        cout << "Alive!" << endl;
    }
    else
    {
        cout << "Eaten by " << diedTo << endl;
    }
}
