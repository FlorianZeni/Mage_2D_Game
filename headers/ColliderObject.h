//
// Created by zenif on 14/04/2021.
//

#ifndef MAGE2_COLLIDEROBJECT_H
#define MAGE2_COLLIDEROBJECT_H

#include "GameObject.h"
#include "Utils.h"
#include <cstring>
#include <utility>

class ColliderObject : public GameObject {
public:
    virtual ~ColliderObject() = default;

    ColliderObject(sf::Vector2f position, bool* enabled_ptr, float radius) : ColliderObject(position, radius, enabled_ptr, "default") {};

    ColliderObject(sf::Vector2f position, float radius, bool* enabled_ptr, std::string tag) :
        GameObject(), position(position), radius(radius), enabled_ptr(enabled_ptr), tag(tag) {};

    bool collides(ColliderObject &object);

    bool isEnabled();

    [[nodiscard]] std::string getTag() const;

    [[nodiscard]] const float& getRadius() const;

    [[nodiscard]] const sf::Vector2f& getPosition() const;

    bool toBeRemoved() override;

    virtual void onCollision(ColliderObject &object) = 0;

protected:
    sf::Vector2f position;
    float radius;
    bool* enabled_ptr;
    std::string tag;

};


#endif //MAGE2_COLLIDEROBJECT_H
