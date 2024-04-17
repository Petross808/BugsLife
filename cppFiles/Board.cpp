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

void Board::displayBugs() const {
    cout << "Bugs:" << endl;
    for(Bug* bug : this->bugs)
    {
        cout << *bug << endl;
    }
}

void Board::findBug(int id) const {
    for(Bug* bug : this->bugs)
    {
        if(bug->getId() == id)
        {
            cout << *bug << endl;
            return;
        }
    }
    cout << "Bug " + to_string(id) + " not found" <<  endl;
}

void Board::tapBoard() {
    for(Bug* bug : this->bugs)
    {
        bug->move();
    }
}

void Board::displayHistoryAll() const {
    for(Bug* bug : this->bugs)
    {
        bug->displayHistory();
    }
}

