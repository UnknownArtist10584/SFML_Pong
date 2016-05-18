//
// Created by Varun Ramakrishnan on 4/2/16.
//

#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::Vector2u window_size, int player_num) : goal(player_num, window_size)
{
    paddle.setSize( sf::Vector2f(20, 150) );
    paddle.setOrigin(sf::Vector2f(paddle.getGlobalBounds().width/2, paddle.getGlobalBounds().height/2));

    if (player_num == 1)
    {
        up_control = sf::Keyboard::W;
        down_control = sf::Keyboard::S;
        paddle.setPosition (sf::Vector2f(10 + paddle.getGlobalBounds().width/2 , window_size.y/2 ) );
        paddle.setFillColor(sf::Color::Blue);
    }

    if (player_num == 2)
    {
        up_control = sf::Keyboard::Up;
        down_control = sf::Keyboard::Down;
        paddle.setPosition (sf::Vector2f(window_size.x - 20, window_size.y/2) );
        paddle.setFillColor(sf::Color::Red);
    }
}

void Player::MovePaddle(sf::Keyboard::Key direction, sf::Vector2u window_size)
{
    if (direction == up_control)
    {
        if (paddle.getPosition().y - paddle.getSize().y/2 > 0)
        {
            paddle.move(0, -10);
        }
    }

    if (direction == down_control)
    {
        if (paddle.getPosition().y + paddle.getSize().y/2 < window_size.y)
        {
            paddle.move(0, 10);
        }
    }
}
