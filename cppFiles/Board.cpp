//
// Created by petrs on 10.04.2024.
//

#include "../headerFiles/Board.h"
#include "../headerFiles/BugFactory.h"
#include "fstream"
#include "iostream"

void Board::loadBugs(const string& filePath) {
    ifstream in(filePath);
    while(!in.eof())
    {
        string bugRecord;
        getline(in, bugRecord);
        Bug* newBug = BugFactory::createBug(bugRecord);
        this->bugs.push_back(newBug);
    }
    in.close();
}

void Board::displayBugs() {
    cout << "Bugs:" << endl;
    for(Bug* bug : this->bugs)
    {
        cout << *bug << endl;
    }
}