//
// Created by petrs on 10.04.2024.
//

#include "../headerFiles/Crawler.h"

void Crawler::move() {

}

string Crawler::getOutputString() const
{
    return to_string(getId()) + " C " + getPosition() + " " + to_string(getSize()) +
           " " + to_string(getDirection()) + " " + getStatus();
}