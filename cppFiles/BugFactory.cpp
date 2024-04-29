//
// Created by petrs on 10.04.2024.
//

#include <sstream>
#include <vector>
#include "../headerFiles/BugFactory.h"
#include "../headerFiles/Crawler.h"
#include "../headerFiles/Hopper.h"
#include "../headerFiles/Ant.h"
#include "../headerFiles/SuperBug.h"

Bug* BugFactory::createBug(std::string &bugRecord) {
    stringstream splitter (bugRecord);
    vector<string> splitString;
    string next;
    while(getline(splitter, next, ';'))
        splitString.push_back(next);

    int id = stoi(splitString[1]);
    int x = stoi(splitString[2]);
    int y = stoi(splitString[3]);
    int dir = stoi(splitString[4]);
    int size = stoi(splitString[5]);

    if(splitString[0] == "C")
    {
        return new Crawler("Crawler", id, x, y, Bug::Direction(dir - 1), size);
    }
    else if (splitString[0] == "H") {
        int hopLength = stoi(splitString[6]);
        return new Hopper("Hopper", id, x, y, Bug::Direction(dir - 1), size, hopLength);
    }
    else if(splitString[0] == "A")
    {
        return new Ant("Ant", id, x, y, Bug::Direction(dir - 1), size);
    }
    else if(splitString[0] == "S")
    {
        return new SuperBug("Super", id, x, y, Bug::Direction(dir - 1), size);
    }
    else
    {
        return new Crawler("Crawler", id, x, y, Bug::Direction(dir - 1), size);
    }
}