//
// Created by zenif on 01/04/2021.
//

#ifndef MAGE2_ENEMY_H
#define MAGE2_ENEMY_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <GameObject.h>
#include "ColliderObject.h"


class Enemy : public ColliderObject {

public:
    Enemy(sf::Vector2f position);

    bool isAlive() const;

    void draw(sf::RenderWindow &window) override;

    void headTowards(float dt, sf::Vector2f targetPosition);

    bool toBeRemoved() override;

    void onCollision(ColliderObject &object) override;

private:
    const float velocity = 75;
    sf::CircleShape shape{radius};
    bool alive = true;
};


#endif //MAGE2_ENEMY_H
