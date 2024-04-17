//
// Created by petrs on 10.04.2024.
//

#ifndef BUGSLIFE_BUG_H
#define BUGSLIFE_BUG_H

#include "utility"
#include "list"
#include "ostream"

using namespace std;

class Bug {
public:
    enum Direction { NORTH, EAST, SOUTH, WEST };
    Bug(int id, int x, int y, Direction direction, int size);
    int getId() const;
    string getPosition() const;
    int getSize() const;
    Direction getDirection() const;
    string getStatus() const;
    virtual string getOutputString() const = 0;
    friend std::ostream& operator<<(std::ostream& out, const Bug& bug);
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
