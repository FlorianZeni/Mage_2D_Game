//
// Created by zenif on 10/03/2021.
//

#ifndef MAGE2_SCENE_H
#define MAGE2_SCENE_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameObject.h"
#include "ColliderObject.h"

class Scene {

public:
    explicit Scene(sf::RenderWindow *window_ptr) : window_ptr(window_ptr) {}

protected:
    // Adds an object
    void addObject(GameObject *object) {
        objects.push_back(object);
    }

    // Adds a collider
    void addCollider(ColliderObject *iCollider) {
        colliders.push_back(iCollider);
    }

    // Detects and calls onCollision methods
    virtual void detectCollisions() = 0;

    // Updates Player Inputs
    virtual void updateInputs(float deltaTime) = 0;

    // Updates Logic
    virtual void updateLogic(float deltaTime) = 0;

    // Renders the game
    virtual void updateGraphics(float deltaTime, sf::RenderWindow &window) = 0;

    sf::RenderWindow *window_ptr;
    std::vector<GameObject *> objects;
    std::vector<ColliderObject *> colliders;
};


#endif //MAGE2_SCENE_H
