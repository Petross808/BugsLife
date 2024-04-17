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

void Board::placeBugs()
{
    for(Bug* bug : this->bugs)
    {
        grid[bug->getPosition().second][bug->getPosition().first].push_back(bug);
    }
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

void Board::displayAllCells() const {
    for(int y = 0; y < 10; y++)
    {
        for(int x = 0; x < 10; x++)
        {
            cout << "(" << x << ", " << y << "): ";
            size_t amount = grid[y][x].size();
            if(amount > 0)
            {
                bool first = true;
                for(Bug* bug : grid[y][x])
                {
                    cout << (first ? "" : ", ") << bug->getType() << " " << bug->getId();
                    first = false;
                }
            }
            else
            {
                cout << "empty";
            }
            cout << endl;
        }
    }
}

