#include <iostream>
#include "../headerFiles/Board.h"

int main() {
    Board board;
    board.loadBugs("../bugs.txt");
    board.displayBugs();
    board.displayHistoryAll();
}
