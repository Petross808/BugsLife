//
// Created by petrs on 10.04.2024.
//

#ifndef BUGSLIFE_BUG_H
#define BUGSLIFE_BUG_H

#include "utility"
#include "list"

using namespace std;

class Bug {
public:
    enum Direction {
        NORTH, SOUTH, WEST, EAST
    };
protected:
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;
    virtual void move() = 0;
    bool isWayBlocked();
};


#endif //BUGSLIFE_BUG_H
