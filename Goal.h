//
// Created by Varun Ramakrishnan on 4/4/16.
//

#ifndef SFML_BOX2D_GAME_GOAL_H
#define SFML_BOX2D_GAME_GOAL_H


#include <SFML/Graphics.hpp>

class Goal
{
public:
    Goal(int player_num, sf::Vector2u window_size);
    sf::RectangleShape goal;
};


#endif //SFML_BOX2D_GAME_GOAL_H
