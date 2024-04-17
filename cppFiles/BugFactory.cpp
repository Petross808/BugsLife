//
// Created by petrs on 10.04.2024.
//

#include <sstream>
#include "../headerFiles/BugFactory.h"
#include "vector"
#include "iostream"

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


}