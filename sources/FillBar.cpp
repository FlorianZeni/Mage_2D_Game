//
// Created by zenif on 31/07/2021.
//

#include <iostream>
#include "FillBar.h"

FillBar::FillBar(sf::Vector2f position, sf::Vector2f size, float* maxValue, float* currentValue) :
    GameObject(), position(position), size(size), maxValue(maxValue), currentValue(currentValue) {
    backShape.setPosition(position);
    frontShape.setPosition(position);
    frontShape.setScale(*currentValue / *maxValue, 1);
    backShape.setFillColor(sf::Color::Red);
    frontShape.setFillColor(sf::Color::Green);
}

void FillBar::draw(sf::RenderWindow &window) {
    updateBar();
    window.draw(backShape);
    window.draw(frontShape);
}

void FillBar::updateBar() {
    frontShape.setScale(*currentValue / *maxValue, 1);
    // std::cout << *currentValue / *maxValue << std::endl;
}

bool FillBar::toBeRemoved() {
    return false;
}
