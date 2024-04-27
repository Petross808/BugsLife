//
// Created by petrs on 27.04.2024.
//

#ifndef BUGSLIFE_ANT_H
#define BUGSLIFE_ANT_H


#include "Bug.h"

class Ant : public Bug {
public:
    using Bug::Bug;
    void move() override;
};


#endif //BUGSLIFE_ANT_H
