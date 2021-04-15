//
// Created by zenif on 11/03/2021.
//

#ifndef MAGE2_GAMEOBJECT_H
#define MAGE2_GAMEOBJECT_H

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject {

public:
    virtual void draw(sf::RenderWindow &window) {};
};

#endif //MAGE2_GAMEOBJECT_H
