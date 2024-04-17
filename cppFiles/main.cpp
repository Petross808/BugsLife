#include <iostream>
#include "../headerFiles/Board.h"

int main() {
    Board board;
    board.loadBugs("../bugs.txt");
    board.placeBugs();
    board.displayBugs();
    board.findBug(104);
    board.displayHistoryAll();
    board.displayAllCells();
    board.tapBoard();
    board.endSimulation();
}
