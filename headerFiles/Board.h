//
// Created by petrs on 10.04.2024.
//

#ifndef BUGSLIFE_BOARD_H
#define BUGSLIFE_BOARD_H

#include "vector"
#include "Bug.h"
#include "string";

class Board {
private:
    vector<Bug*> bugs;
    vector<Bug*> grid[10][10];

public:
    void loadBugs(const std::string &filePath);
    void placeBugs();
    void displayBugs() const;
    void findBug(int id) const;
    void tapBoard();
    void displayHistoryAll() const;
    void endSimulation();
    void displayAllCells() const;
};


#endif //BUGSLIFE_BOARD_H
