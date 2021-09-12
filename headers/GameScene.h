//
// Created by zenif on 10/03/2021.
//

#ifndef MAGE2_GAMESCENE_H
#define MAGE2_GAMESCENE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <chrono>
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "FillBar.h"

class GameScene : public Scene {

public:

    explicit GameScene(sf::RenderWindow *window);

    void updateInputs(float deltaTime) override;

    void updateLogic(float deltaTime) override;

    void updateGraphics(float deltaTime, sf::RenderWindow &window) override;

    void detectCollisions() const override;

    void spawnEnemies(int amount = 0);

private:
    Player player;
    sf::Vector2f direction;
    std::vector<Enemy *> enemy_ptrs;
    FillBar healthBar {{20, 20}, {50, 20}, player.getMaxHealth(), player.getCurrentHealth()};
    float timeSinceLastCleanup = 0;
    float totalPlayTime = 0;
    const float timeBetweenCleanups = 2; // in seconds
    int aliveEnemiesAmount = 0;
    void cleanContainers();

    void updateLivingEnemies();
};


#endif //MAGE2_GAMESCENE_H
