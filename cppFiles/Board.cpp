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
        if(!bugRecord.empty())
        {
            Bug* newBug = BugFactory::createBug(bugRecord);
            this->bugs.push_back(newBug);
        }
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
        bug->letBugDoBugThing();
    }
    evaluateFights();
}

void Board::displayHistoryAll() const {
    for(Bug* bug : this->bugs)
    {
        cout << bug->getHistory() << endl;
    }
    cout << endl;
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
            if(currentAlpha->getSize() == bug->getSize() && rand()%2)
            {
                bug->killBug(*currentAlpha);
                currentAlpha = bug;
            }
            else
            {
                currentAlpha->killBug(*bug);
            }
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

void Board::runSimulation()
{
    int alive;
    unsigned long long startTime;
    int iterations = 0;
    do {
        alive = getAliveAmount();
        startTime = _pthread_time_in_ms();

        while(_pthread_time_in_ms() - startTime < 1000);

        tapBoard();
        displayHistoryAll();

    } while(alive > 1 && ++iterations < 100);

    endSimulation();
    cout << "Simulation over, results saved" << endl;
}

int Board::getAliveAmount() const
{
    int alive = 0;
    for (Bug *bug: bugs)
    {
        if (bug->getStatus())
            alive++;
    }
    return alive;
}

list<pair<string, pair<int, int>>> Board::getAliveBugPositions() const
{
    list<pair<string, pair<int, int>>> out;
    for(Bug* bug : bugs)
    {
        if(bug->getStatus())
            out.emplace_back(bug->getType(),bug->getPosition());
    }
    return out;
}