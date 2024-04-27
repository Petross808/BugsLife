#include <iostream>
#include <algorithm>
#include "../headerFiles/Board.h"
#include "../headerFiles/GuiSimulation.h"

int parseInt(const string& str);

int main() {
    srand(time(nullptr));
    Board board;
    GuiSimulation guiSimulation(&board);
    string cache;
    bool running = true;
    while(running)
    {
        cout << "\nMenu\n"
                "1. Initialize Bug Board (load data from file)\n"
                "2. Display all Bugs\n"
                "3. Find a Bug (given an id)\n"
                "4. Tap the Bug Board (causes move all, then fight/eat)\n"
                "5. Display Life History of all Bugs (path taken)\n"
                "6. Display all Cells listing their Bugs\n"
                "7. Run simulation (generates a Tap every second)\n"
                "8. Run simulation with GuiSimulation (generates a Tap every second)\n"
                "9. Exit (write Life History of all Bugs to file)\n"
                "Input:";

        cin >> cache;
        cout << endl;


        switch(parseInt(cache))
        {
            case 1:
                board.loadBugs("../bugs.txt");
                cout << "Bugs loaded" << endl;
                break;
            case 2:
                board.displayBugs();
                break;
            case 3:
                cout << "ID: ";
                cin >> cache;
                board.findBug(parseInt(cache));
                break;
            case 4:
                board.tapBoard();
                cout << "Board Tapped\n";
                break;
            case 5:
                board.displayHistoryAll();
                break;
            case 6:
                board.displayAllCells();
                break;
            case 7:
                board.runSimulation();
                break;
            case 8:
                guiSimulation.start();
                break;
            case 9:
                running = false;
                board.endSimulation();
                cout << "Bug history saved to a file...\nGoodbye!" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
}

int parseInt(const string& str)
{
    int out;
    try
    {
        out = stoi(str);
    }
    catch (invalid_argument& e)
    {
        out = -1;
    }
    return out;
}
