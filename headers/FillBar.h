//
// Created by zenif on 31/07/2021.
//

#ifndef MAGE_FILLBAR_H
#define MAGE_FILLBAR_H

#include "GameObject.h"
#include <SFML/Graphics/RectangleShape.hpp>


class FillBar : public GameObject{
public:
    virtual ~FillBar() = default;

    FillBar(sf::Vector2f position, sf::Vector2f size, float* maxValue, float* currentValue);

    void draw(sf::RenderWindow &window) override;

     bool toBeRemoved() override;

    void updateBar();

protected:
    sf::Vector2f position;
    sf::Vector2f size;
    float* maxValue;
    float* currentValue;
    sf::RectangleShape backShape {size};
    sf::RectangleShape frontShape {size};
};


#endif //MAGE_FILLBAR_H
