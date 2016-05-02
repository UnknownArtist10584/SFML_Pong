//
// Created by Varun Ramakrishnan on 4/2/16.
//

#ifndef SFML_BOX2D_GAME_PADDLE_H
#define SFML_BOX2D_GAME_PADDLE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Goal.h"

class Player
{
public:
    Player(sf::Vector2u window_size, int player_num);
    void MovePaddle(sf::Keyboard::Key direction, sf::Vector2u window_size);
    sf::RectangleShape paddle;
    sf::Keyboard::Key  up_control;
    sf::Keyboard::Key  down_control;
    int score;
    Goal goal;
};


#endif //SFML_BOX2D_GAME_PADDLE_H
