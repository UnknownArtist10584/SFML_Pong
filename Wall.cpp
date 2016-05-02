//
// Created by Varun Ramakrishnan on 4/3/16.
//

#include "Wall.h"

Wall::Wall(sf::Keyboard::Key  direction, sf::Vector2u window_size)
{
    wall.setSize(sf::Vector2f(window_size.x, 20));
    wall.setFillColor(sf::Color::White);
    wall.setOrigin(wall.getGlobalBounds().width/2, wall.getGlobalBounds().height/2);

    if (direction == sf::Keyboard::Up)
    {
        wall.setPosition(window_size.x/2, 5);
    }

    if (direction == sf::Keyboard::Down)
    {
        wall.setPosition(window_size.x/2, window_size.y - 5);
    }
}