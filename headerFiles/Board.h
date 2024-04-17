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

    void setCell(Bug*);
public:
    void loadBugs(const std::string &filePath);
    void displayBugs() const;
    Bug* readCell() const;
    void findBug(int id) const;
    void tapBoard();
    void displayHistoryAll() const;
};


#endif //BUGSLIFE_BOARD_H
