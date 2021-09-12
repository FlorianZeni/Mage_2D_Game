//
// Created by zenif on 10/03/2021.
//

#include "GameScene.h"
#include "Constants.h"
#include <SFML/Window/Event.hpp>
#include <cmath>
#include <random>
#include <iostream>
#include <Utils.h>

GameScene::GameScene(sf::RenderWindow *window_ptr) : Scene(window_ptr) {
    addObject(&player);
    addCollider(&player);
    spawnEnemies(200);
    addObject(&healthBar);
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
    totalPlayTime += deltaTime;
    int enemyAmount = (int) (200 + 10 * totalPlayTime);
    enemyAmount = std::max(enemyAmount, 600);
    spawnEnemies(enemyAmount);
    sf::Vector2f playerPosition = player.getPosition();
    for (Enemy *enemy_ptr : enemy_ptrs) {
        if(enemy_ptr->isAlive())
            enemy_ptr->headTowards(deltaTime, playerPosition);
    }

    detectCollisions();
    updateLivingEnemies();

    timeSinceLastCleanup += deltaTime;
    if (timeSinceLastCleanup >= timeBetweenCleanups){
        cleanContainers();
        timeSinceLastCleanup = 0;
    }
}

void GameScene::updateGraphics(float deltaTime, sf::RenderWindow &window) {
    for (GameObject *object : objects) {
        object->draw(window);
    }
}

void GameScene::spawnEnemies(int amount) {
    int xPos;
    int yPos;
    for (int i(0); i < amount - aliveEnemiesAmount; i++) {
        if(std::rand() % 2 == 0){
            xPos = std::rand() % Constants::gameWidth;
            yPos = std::rand() % 600 - 300;
            yPos = yPos < 0 ? yPos : yPos + Constants::gameHeight;
        }
        else{
            yPos = std::rand() % Constants::gameHeight;
            xPos = std::rand() % 600 - 300;
            xPos = xPos < 0 ? xPos : xPos + Constants::gameWidth;
        }
        sf::Vector2f pos = sf::Vector2f{(float) (xPos), (float) (yPos)};
        //std::cout << pos.x << " " << pos.y << std::endl;
        auto *new_enemy = new Enemy(pos, 10.0f);
        enemy_ptrs.push_back(new_enemy);
        addObject(new_enemy);
        addCollider(new_enemy);
    }
    aliveEnemiesAmount = amount;
}

void GameScene::detectCollisions() const{
    for (int i = 0; i < colliders.size(); i++) {
        for (int j = i + 1; j < colliders.size(); j++) {
            auto first = colliders[i];
            auto second = colliders[j];
            if (first->isEnabled() && second->isEnabled()){
                // std::cout << "Distance " << Utils::Distance(colliders[i]->position, colliders[j]->position) << std::endl;
                // std::cout << "Rayons " << colliders[i]->radius + colliders[j]->radius << std::endl;
                //if (Constants::mayCollide(first->getTag(), second->getTag())) { // More costly than computing the distance
                if (first->collides(*second)) {
                    first->onCollision(*second);
                    second->onCollision(*first);
                }
            }
        }
    }
}

void GameScene::updateLivingEnemies(){
    aliveEnemiesAmount = 0;
    for(auto & enemy_ptr : enemy_ptrs){
        if(enemy_ptr->isAlive()){
            aliveEnemiesAmount ++;
        }
    }
}

void GameScene::cleanContainers() {

    objects.erase(std::remove_if(objects.begin(), objects.end(), [](GameObject* ptr){return ptr->toBeRemoved();}), objects.end());
    colliders.erase(std::remove_if(colliders.begin(), colliders.end(),  [](ColliderObject* ptr){return ptr->toBeRemoved();}), colliders.end());

    std::vector<Enemy *> to_be_deleted;
    for(auto & enemy_ptr : enemy_ptrs){
        if(enemy_ptr->toBeRemoved()) {
            to_be_deleted.push_back(enemy_ptr);
        }
    }

    enemy_ptrs.erase(std::remove_if(enemy_ptrs.begin(), enemy_ptrs.end(),  [](Enemy* ptr){return ptr->toBeRemoved();}), enemy_ptrs.end());
    for(auto b : to_be_deleted){
        delete b;
    }

    std::cout << objects.size() << "  " << colliders.size() << " " << enemy_ptrs.size() << std::endl;
}




