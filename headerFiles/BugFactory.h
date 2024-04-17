//
// Created by petrs on 10.04.2024.
//

#ifndef BUGSLIFE_BUGFACTORY_H
#define BUGSLIFE_BUGFACTORY_H

#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "string"

class BugFactory {
public:
    static Bug* createBug(std::string &bugRecord);
};


#endif //BUGSLIFE_BUGFACTORY_H
