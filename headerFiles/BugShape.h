//
// Created by petrs on 29.04.2024.
//

#ifndef BUGSLIFE_BUGSHAPE_H
#define BUGSLIFE_BUGSHAPE_H

#include "Bug.h"
#include <SFML/Graphics.hpp>

struct BugShape
{
    sf::Texture texture;
    Bug::Direction dir;
    int size;
    pair<int, int> position;

    void setTexture(const string &type)
    {
        if(type == "Crawler")
        {
            texture.loadFromFile("../Assets/Crawler.png");
        }
        else if(type == "Hopper")
        {
            texture.loadFromFile("../Assets/Hopper.png");
        }
        else if(type == "Ant")
        {
            texture.loadFromFile("../Assets/Ant.png");
        }
        else if(type == "Super")
        {
            texture.loadFromFile("../Assets/Super.png");
        }
    }
};


#endif //BUGSLIFE_BUGSHAPE_H
