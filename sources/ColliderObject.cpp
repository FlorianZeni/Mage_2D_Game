//
// Created by zenif on 15/04/2021.
//

#include "ColliderObject.h"

bool ColliderObject::collides(ColliderObject &object) {
    return Utils::Distance(position, object.getPosition()) < radius + object.getRadius();
}

const float &ColliderObject::getRadius() const {
    return radius;
}

const sf::Vector2f &ColliderObject::getPosition() const {
    return position;
}

std::string ColliderObject::getTag() const{
    return tag;
}

bool ColliderObject::isEnabled() {
    return *enabled_ptr;
}

bool ColliderObject::toBeRemoved() {
    return !isEnabled();
}




