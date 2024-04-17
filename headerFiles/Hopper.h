//
// Created by petrs on 10.04.2024.
//

#ifndef BUGSLIFE_HOPPER_H
#define BUGSLIFE_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;
public:
    Hopper(string type, int id, int x, int y, Direction direction, int size, int hopLength);
    void move() override;
    int getHopLength() const;
    string getOutputString() const override;
};


#endif //BUGSLIFE_HOPPER_H
