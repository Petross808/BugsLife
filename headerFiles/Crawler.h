//
// Created by petrs on 10.04.2024.
//

#ifndef BUGSLIFE_CRAWLER_H
#define BUGSLIFE_CRAWLER_H


#include "Bug.h"

class Crawler : public Bug {
public:
    using Bug::Bug;
    void move() override;
    virtual string getOutputString() const override;
};


#endif //BUGSLIFE_CRAWLER_H
