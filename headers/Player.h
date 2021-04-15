//
// Created by zenif on 11/03/2021.
//

#ifndef MAGE2_PLAYER_H
#define MAGE2_PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "GameObject.h"
#include "ColliderObject.h"


class Player : public ColliderObject {

public:

    explicit Player();

    explicit Player(sf::Vector2f position);

    void draw(sf::RenderWindow &window) override;

    void updatePosition(float dt, sf::Vector2f direction);

    void onCollision(ColliderObject &object) override;

private:
    const float velocity = 200;
    sf::CircleShape shape{radius};

    int maxHealth = 100;
    int currentHealth = 100;

};


#endif //MAGE2_PLAYER_H
