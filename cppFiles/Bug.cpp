//
// Created by petrs on 10.04.2024.

#include <iostream>
#include <algorithm>
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

bool Bug::getStatus() const
{
    return this->alive;
}

void Bug::setStatus(bool status) {
    this->alive = status;
}

void Bug::setDiedTo(int killerId) {
    this->diedTo = killerId;
}

std::ostream& operator<<(std::ostream& out, const Bug& bug)
{
    out << bug.getOutputString();
    return out;
}

string Bug::getOutputString() const
{
    return to_string(getId()) + " " + getType()[0] + " (" + to_string(getPosition().first) + ", " + to_string(getPosition().second) + ") " + to_string(getSize()) +
           " " + to_string(getDirection()) + " " + (getStatus() ? "Alive" : "Dead");
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

pair<pair<int, int>, int> Bug::calculateNewPosition(const int deltaForward) {
    pair pos(position.first,position.second);
    switch(direction)
    {
        case NORTH:
            pos.second-=deltaForward;
            break;
        case SOUTH:
            pos.second+=deltaForward;
            break;
        case EAST:
            pos.first+=deltaForward;
            break;
        case WEST:
            pos.first-=deltaForward;
            break;
    }
    pair<int, int> overshoot(pos.first, pos.second);
    pos.first = std::clamp(pos.first, 0,9);
    pos.second = std::clamp(pos.second, 0,9);
    overshoot.first -= pos.first;
    overshoot.second -= pos.second;

    return {pos,abs(overshoot.first + overshoot.second)};
}

bool Bug::bugCompare(Bug* bug1, Bug* bug2) {
    if(bug1->getPosition() < bug2->getPosition())
    {
        return false;
    }
    else if(bug1->getPosition() > bug2->getPosition())
    {
        return true;
    }
    else if(bug1->getSize() < bug2->getSize())
    {
        return false;
    }
    else if(bug1->getSize() > bug2->getSize())
    {
        return true;
    }
    else
    {
        return (rand()%2 == 0);
    }
}

void Bug::killBug(Bug &food) {
    if(id == food.id)
        return;
    food.setStatus(false);
    food.setDiedTo(this->id);
    this->size += food.getSize();
}
