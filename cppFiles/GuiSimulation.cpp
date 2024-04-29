//
// Created by petrs on 27.04.2024.
//

#include <iostream>
#include "../headerFiles/GuiSimulation.h"

GuiSimulation::GuiSimulation(Board* bugBoard) {
    window = nullptr;
    board = bugBoard;
    aliveBugs = 0;
    startTime = 0;
    iterations = 0;
    simulationOver = false;

    font.loadFromFile("../Assets/arial.ttf");
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
    aliveBugs = board->getAliveAmount();
    startTime = 0;
    iterations = 0;
    simulationOver = false;

    while (window->isOpen())
    {
        handleEvents();
        handleSimulation();
        drawGui();
    }

    delete window;
}

void GuiSimulation::handleEvents() {
    Event event{};
    while (window->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window->close();
        }
        else if(event.type == Event::KeyReleased)
        {
            if(simulationOver)
            {
                continue;
            }
            switch(event.key.code)
            {
                case Keyboard::Up:
                    board->moveSuperBug(Bug::NORTH);
                    break;
                case Keyboard::Down:
                    board->moveSuperBug(Bug::SOUTH);
                    break;
                case Keyboard::Left:
                    board->moveSuperBug(Bug::WEST);
                    break;
                case Keyboard::Right:
                    board->moveSuperBug(Bug::EAST);
                    break;
                case Keyboard::Escape:
                    window->close();
                    break;
                default:
                    break;
            }
        }
    }
}

void GuiSimulation::handleSimulation() {
    if(1000 < (_pthread_time_in_ms() - startTime) && !simulationOver)
    {
        startTime = _pthread_time_in_ms();
        board->tapBoard();
        aliveBugs = board->getAliveAmount();
        iterations++;
        if(iterations > 100 || aliveBugs <= 1)
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

    auto bugs = board->getAliveBugShapes();
    for(auto &bug : bugs)
    {
        drawBug(bug);
    }

    if(simulationOver)
    {
        drawRectangle(300,100,150,250,Color::White);
        drawText("Simulation over",300,280,32);
        drawText("You may close the window",300,320,20);
    }

    window->display();
}

void GuiSimulation::drawBug(const BugShape &bugShape) {
    Sprite bug;
    bug.setTexture(bugShape.texture);
    bug.setPosition(50 + bugShape.position.first * 50,50 + bugShape.position.second * 50);
    switch(bugShape.dir)
    {
        case Bug::NORTH:
            bug.setRotation(0);
            break;
        case Bug::SOUTH:
            bug.setRotation(180);
            bug.move(50,50);
            break;
        case Bug::EAST:
            bug.setRotation(90);
            bug.move(50,0);
            break;
        case Bug::WEST:
            bug.setRotation(270);
            bug.move(0,50);
            break;
    }
    window->draw(bug);
    drawText(to_string(bugShape.size), 55 + bugShape.position.first * 50, 55 + bugShape.position.second * 50, 12);
}

void GuiSimulation::drawText(string text, int x, int y, int size)
{
    Text textObject;
    textObject.setString(text);
    textObject.setFont(font);
    textObject.setCharacterSize(size);
    textObject.setStyle(Text::Bold);
    textObject.setFillColor(Color::Black);
    textObject.setPosition(x - textObject.getLocalBounds().width/2, y - textObject.getLocalBounds().height/2);
    window->draw(textObject);
}

void GuiSimulation::drawRectangle(int sizeX, int sizeY, int posX, int posY, Color color)
{
    RectangleShape panel(Vector2f(sizeX,sizeY));
    panel.setFillColor(color);
    panel.setPosition(posX,posY);
    panel.setOutlineColor(Color::Black);
    panel.setOutlineThickness(1);
    window->draw(panel);
}

