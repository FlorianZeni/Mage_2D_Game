//
// Created by zenif on 11/03/2021.
//

#ifndef MAGE2_GAMEOBJECT_H
#define MAGE2_GAMEOBJECT_H

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject {

public:
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual bool toBeRemoved() = 0;
};

#endif //MAGE2_GAMEOBJECT_H
