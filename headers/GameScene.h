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

    void detectCollisions() override;

    void spawnEnnemies(int amount = 0);

private:
    Player player;
    sf::Vector2f direction;
    std::vector<Enemy *> enemy_ptrs;
    FillBar healthBar {{20, 20}, {50, 20}, player.getMaxHealth(), player.getCurrentHealth()};
    int counter = 0;
    void cleanContainers();
};


#endif //MAGE2_GAMESCENE_H
