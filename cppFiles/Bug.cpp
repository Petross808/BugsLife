//
// Created by petrs on 10.04.2024.
//

#include "../headerFiles/Bug.h"

Bug::Bug(int id, int x, int y, Bug::Direction direction, int size) {
    this->id = id;
    this->position = pair<int, int>(x,y);
    this->direction = direction;
    this->size = size;
    this->alive = true;
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

