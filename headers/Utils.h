//
// Created by zenif on 01/04/2021.
//

#ifndef MAGE2_UTILS_H
#define MAGE2_UTILS_H

#include <SFML/System.hpp>
#include <cmath>


class Utils {
public:
    static sf::Vector2f Normalize(sf::Vector2f vec) {
        if (vec != sf::Vector2f{0, 0}) {
            vec /= (float) std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
        }
        return vec;
    }

    static double Distance(sf::Vector2f pos1, sf::Vector2f pos2) {
        return std::sqrt(std::pow(pos1.x - pos2.x, 2) + std::pow(pos1.y - pos2.y, 2));
    }

};

#endif //MAGE2_UTILS_H
