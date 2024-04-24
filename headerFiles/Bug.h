//
// Created by petrs on 10.04.2024.
//

#ifndef BUGSLIFE_BUG_H
#define BUGSLIFE_BUG_H

#include <list>
#include <string>
using namespace std;

class Bug {
public:
    enum Direction { NORTH, EAST, SOUTH, WEST };
    Bug(string type, int id, int x, int y, Direction direction, int size);
    string getType() const;
    int getId() const;
    pair<int, int> getPosition() const;
    int getSize() const;
    Direction getDirection() const;
    bool getStatus() const;
    void setStatus(bool status);
    void setDiedTo(int id);
    virtual string getOutputString() const;
    friend std::ostream& operator<<(std::ostream& out, const Bug& bug);

    virtual void move() = 0;
    string getHistory() const;
    void killBug(Bug& food);

    static bool bugCompare(Bug*, Bug*);

protected:
    string type;
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;
    int diedTo;
    bool isWayBlocked();
    pair<pair<int, int>,int> calculateNewPosition(int deltaForward);
};


#endif //BUGSLIFE_BUG_H
