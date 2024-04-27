//
// Created by petrs on 27.04.2024.
//

#ifndef BUGSLIFE_GUISIMULATION_H
#define BUGSLIFE_GUISIMULATION_H

#include <SFML/Graphics.hpp>
#include "Board.h"

using namespace sf;

class GuiSimulation {
private:
    RenderWindow* window;
    Board* board;
    void initBackground();
    void handleEvents();
    void handleSimulation();
    void drawGui();
    void drawBug(string &name, pair<int, int> &position);

    int aliveBugs;
    unsigned long long startTime;
    int iterations;
    bool simulationOver;

    vector<RectangleShape> background;

public:
    explicit GuiSimulation(Board* board);
    ~GuiSimulation();
    void start();
};


#endif //BUGSLIFE_GUISIMULATION_H
