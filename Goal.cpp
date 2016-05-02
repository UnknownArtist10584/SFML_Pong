//
// Created by Varun Ramakrishnan on 4/4/16.
//

#include "Goal.h"

Goal::Goal(int player_num, sf::Vector2u window_size)
{
    sf::RectangleShape goal;
    goal.setOrigin(0, 0);
    goal.setSize(sf::Vector2f(10, window_size.y));

    if (player_num == 1)
    {
        goal.setFillColor(sf::Color::Red);
        goal.setPosition(sf::Vector2f(0, 0));
    }

    if (player_num == 2)
    {
        goal.setFillColor(sf::Color::Blue);
        goal.setPosition(sf::Vector2f(window_size.x, 0));
    }
}