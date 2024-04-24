//
// Created by petrs on 10.04.2024.
//

#ifndef BUGSLIFE_BOARD_H
#define BUGSLIFE_BOARD_H

#include "Bug.h"
#include "string"
#include "vector"

class Board {
private:
    vector<Bug*> bugs;
public:
    void loadBugs(const std::string &filePath);
    void displayBugs() const;
    void findBug(int id) const;
    void tapBoard();
    void evaluateFights();
    void displayHistoryAll() const;
    void runSimulation();
    void endSimulation();
    void displayAllCells() const;
};


#endif //BUGSLIFE_BOARD_H
