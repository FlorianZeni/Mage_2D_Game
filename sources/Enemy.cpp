//
// Created by zenif on 01/04/2021.
//

#include <Utils.h>
#include <iostream>
#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position) : ColliderObject(position, 10.0f, &alive, "Foe") {
    shape.setFillColor(sf::Color::White);
    shape.setPosition(position);
}

void Enemy::draw(sf::RenderWindow &window) {
    if (alive)
        window.draw(shape);
}

void Enemy::headTowards(float dt, sf::Vector2f targetPosition) {
    position += velocity * dt * (Utils::Normalize(targetPosition - position - sf::Vector2f{2, 2}));
    shape.setPosition(position - sf::Vector2f{radius, radius});
}

void Enemy::onCollision(ColliderObject &object) {
    // std::cout << "Ennemy Died" << std::endl;
    if(object.getTag() == "Player")
        alive = false;
}

bool Enemy::isAlive() const {
    return alive;
}

bool Enemy::toBeRemoved() {
    return !isAlive();
}
