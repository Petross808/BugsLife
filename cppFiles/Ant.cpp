//
// Created by petrs on 27.04.2024.
//

#include "../headerFiles/Ant.h"

void Ant::move() {
    auto pos_over = calculateNewPosition(1);
    while(pos_over.second != 0)
    {
        this->direction = Direction((this->direction + 1 + (rand() % 3)) % 4);
        pos_over = calculateNewPosition(1);
    }
    this->position = pos_over.first;

    if(rand()%4)
    {
        this->direction = Direction((this->direction + 1 + (rand() % 3)) % 4);
    }
}