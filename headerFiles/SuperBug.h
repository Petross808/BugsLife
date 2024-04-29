//
// Created by petrs on 29.04.2024.
//

#ifndef BUGSLIFE_SUPERBUG_H
#define BUGSLIFE_SUPERBUG_H


#include "Bug.h"

class SuperBug : public Bug {
private:
    bool isControlled;
    static SuperBug* lastAddedSuperBug;
public:
    SuperBug(string type, int id, int x, int y, Direction direction, int size);
    void move() override;
    void setControlled(bool);
    bool getControlled() const;
    void manualMove(Direction);

    static SuperBug* getLastAddedSuperBug();
};


#endif //BUGSLIFE_SUPERBUG_H
