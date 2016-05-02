//
// Created by Varun Ramakrishnan on 4/3/16.
//

#ifndef SFML_BOX2D_GAME_WALL_H
#define SFML_BOX2D_GAME_WALL_H


#include <SFML/Graphics.hpp>

class Wall
{
public:
    Wall(sf::Keyboard::Key direction, sf::Vector2u window_size);
    sf::RectangleShape wall;
};


#endif //SFML_BOX2D_GAME_WALL_H
