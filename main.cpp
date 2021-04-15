#include <SFML/Graphics.hpp>
#include <Player.h>
#include <iostream>
#include "GameScene.h"

int main() {

    sf::ContextSettings settings(0, 0, 4);

    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!", sf::Style::Default, settings);

    GameScene gameScene(&window);

    auto currentTime = std::chrono::steady_clock::now();

    while (window.isOpen()) {

        float deltaTime;
        {
            const auto newTime = std::chrono::steady_clock::now();
            deltaTime = std::chrono::duration<float>(newTime - currentTime).count();
            currentTime = newTime;
        }

        gameScene.updateInputs(deltaTime);

        gameScene.updateLogic(deltaTime);

        window.clear();

        gameScene.updateGraphics(deltaTime, window);

        window.display();
    }

    return 0;
}