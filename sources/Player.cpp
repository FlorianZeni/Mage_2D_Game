//
// Created by zenif on 11/03/2021.
//

#include "Player.h"

Player::Player() : Player({500, 300}) {

}

Player::Player(sf::Vector2f position) : ColliderObject(position, 15.0f) {
    shape.setFillColor(sf::Color::Green);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

void Player::updatePosition(float dt, sf::Vector2f direction) {
    position += velocity * dt * direction;
    shape.setPosition(position - sf::Vector2f{radius, radius});
}

void Player::onCollision(ColliderObject &object) {

}

