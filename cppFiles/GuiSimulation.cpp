//
// Created by petrs on 27.04.2024.
//

#include <iostream>
#include "../headerFiles/GuiSimulation.h"

GuiSimulation::GuiSimulation(Board* bugBoard) {
    window = nullptr;
    board = bugBoard;
    aliveBugs = board->getAliveAmount();
    startTime = 0;
    iterations = 0;
    simulationOver = false;
    initBackground();
}

GuiSimulation::~GuiSimulation() {
    delete window;
}

void GuiSimulation::initBackground()
{
    for(int y = 0; y < 10; y++)
    {
        for(int x = 0; x < 10; x++)
        {
            RectangleShape tile(Vector2f(50,50));
            tile.setFillColor(Color::White);
            tile.setPosition(50 + x * 50,50 + y * 50);
            tile.setOutlineColor(Color::Black);
            tile.setOutlineThickness(1);
            background.push_back(tile);
        }
    }
}

void GuiSimulation::start() {
    window = new RenderWindow(VideoMode(600,600), "Bug's Life");
    window->setFramerateLimit(30);

    while (window->isOpen())
    {
        handleEvents();
        handleSimulation();
        drawGui();
    }
}

void GuiSimulation::handleEvents() {
    Event event{};
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void GuiSimulation::handleSimulation() {
    if(1000 < (_pthread_time_in_ms() - startTime) && !simulationOver)
    {
        startTime = _pthread_time_in_ms();
        board->tapBoard();
        aliveBugs = board->getAliveAmount();
        iterations++;
        if(iterations > 100)
        {
            simulationOver = true;
        }
    }
}

void GuiSimulation::drawGui() {
    window->clear();

    for(auto &tile : background)
    {
        window->draw(tile);
    }

    auto bugs = board->getAliveBugPositions();
    for(auto &bug : bugs)
    {
        drawBug(bug.first, bug.second);
    }

    window->display();
}

void GuiSimulation::drawBug(std::string &name, pair<int, int> &position) {
    CircleShape bug(20);
    if(name == "Crawler")
    {
        bug.setFillColor(Color::Yellow);
    }
    else if(name == "Hopper")
    {
        bug.setFillColor(Color::Red);
    }
    else if(name == "Ant")
    {
        bug.setFillColor(Color::Green);
    }
    bug.setPosition(55 + position.first * 50,55 + position.second * 50);
    bug.setOutlineColor(Color::Black);
    bug.setOutlineThickness(1);
    window->draw(bug);
}

