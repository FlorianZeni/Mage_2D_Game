//
// Created by zenif on 14/04/2021.
//

#ifndef MAGE2_COLLIDEROBJECT_H
#define MAGE2_COLLIDEROBJECT_H

#include "GameObject.h"
#include "Utils.h"

class ColliderObject : public GameObject {
public:
    virtual ~ColliderObject() = default;

    ColliderObject(sf::Vector2f position, float radius) : GameObject(), position(position), radius(radius) {};

    bool collides(ColliderObject &object);

    [[nodiscard]] const float &getRadius() const;

    [[nodiscard]] const sf::Vector2f &getPosition() const;

    virtual void onCollision(ColliderObject &object) = 0;

protected:
    sf::Vector2f position;
    float radius;
};


#endif //MAGE2_COLLIDEROBJECT_H
