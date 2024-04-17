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
    int attr1 = stoi(splitString[5]);

    if(splitString[0] == "C")
    {
        return new Crawler(id, x, y, Bug::Direction(dir-1), attr1);
    }
    else if (splitString[0] == "H") {
        int attr2 = stoi(splitString[6]);
        return new Hopper(id, x, y, Bug::Direction(dir - 1), attr2, attr1);
    }

}