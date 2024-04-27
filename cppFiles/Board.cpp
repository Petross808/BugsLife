//
// Created by petrs on 10.04.2024.
//

#include "../headerFiles/Board.h"
#include "../headerFiles/BugFactory.h"
#include "fstream"
#include "iostream"
#include "algorithm"

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
    evaluateFights();
}

void Board::displayHistoryAll() const {
    for(Bug* bug : this->bugs)
    {
        cout << bug->getHistory() << endl;
    }
}

void Board::endSimulation() {
    ofstream out("../bugs_life_history_date_time.out");
    for(Bug* bug : this->bugs)
    {
        out << bug->getHistory() << endl;
    }
    out.flush();
    out.close();
}

void Board::evaluateFights() {
    std::sort(bugs.begin(), bugs.end(),Bug::bugCompare);

    Bug* currentAlpha;
    pair<int,int> currentPos = {-1,-1};

    for(Bug* bug : this->bugs)
    {
        if(!bug->getStatus())
            continue;

        if(currentPos != bug->getPosition())
        {
            currentAlpha = bug;
            currentPos = bug->getPosition();
        }
        else
        {
            currentAlpha->killBug(*bug);
        }
    }
}

void Board::displayAllCells() {
    std::sort(bugs.begin(), bugs.end(), Bug::bugCompare);
    auto nextBug = bugs.begin();
    pair<int, int> currentPos = {-1,-1};
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            cout << "(" << x << ", " << y << "):";
            currentPos = {x,y};
            while(nextBug != bugs.end() && (*nextBug)->getPosition() == currentPos)
            {
                cout << " (" << (*nextBug)->getId() << " " << (*nextBug)->getType() << ")";
                nextBug++;
            }
            cout << endl;
        }
    }
}

void Board::runSimulation() {}
