//
// Created by zenif on 10/03/2021.
//

#include "GameScene.h"
#include <SFML/Window/Event.hpp>
#include <cmath>
#include <random>
#include <iostream>
#include <Utils.h>

GameScene::GameScene(sf::RenderWindow *window_ptr) : Scene(window_ptr) {
    addObject(&player);
    addCollider(&player);
    spawnEnnemies(200);
}

void GameScene::updateInputs(float deltaTime) {
    sf::Event event{};

    while (window_ptr->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window_ptr->close();
    }

    direction = {0.0f, 0.0f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        direction.x += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        direction.y += 1;

    direction = Utils::Normalize(direction);

}

void GameScene::updateLogic(float deltaTime) {
    player.updatePosition(deltaTime, direction);
    sf::Vector2f playerPosition = player.getPosition();
    for (Enemy *enemy_ptr : enemy_ptrs) {
        enemy_ptr->headTowards(deltaTime, playerPosition);
    }

    detectCollisions();

}

void GameScene::updateGraphics(float deltaTime, sf::RenderWindow &window) {
    for (GameObject *object : objects) {
        object->draw(window);
    }
}

void GameScene::spawnEnnemies(int amount) {
    for (int i(0); i < amount; i++) {
        sf::Vector2f pos = sf::Vector2f{(float) (std::rand() % 1000), (float) (std::rand() % 500)};
        //std::cout << pos.x << " " << pos.y << std::endl;
        enemy_ptrs.push_back(new Enemy(pos));
        addObject(enemy_ptrs[i]);
        addCollider(enemy_ptrs[i]);
    }
}

void GameScene::detectCollisions() {
    for (int i = 0; i < colliders.size(); i++) {
        for (int j = i + 1; j < colliders.size(); j++) {
            // std::cout << "Distance " << Utils::Distance(colliders[i]->position, colliders[j]->position) << std::endl;
            // std::cout << "Rayons " << colliders[i]->radius + colliders[j]->radius << std::endl;
            if (colliders[i]->collides(*colliders[j])) {
                //if(Utils::Distance(colliders[i]->position, colliders[j]->position) < colliders[i]->radius + colliders[j]->radius){
                colliders[i]->onCollision(*colliders[j]);
                colliders[j]->onCollision(*colliders[i]);
            }
        }
    }
}




