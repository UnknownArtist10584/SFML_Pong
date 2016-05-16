//
// Created by Varun Ramakrishnan on 4/2/16.
//

#ifndef SFML_BOX2D_GAME_BALL_H
#define SFML_BOX2D_GAME_BALL_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <boost/random.hpp>
#include "Player.h"
#include "Wall.h"

class Ball
{
public:
    Ball(sf::Vector2u window_size);
    sf::RectangleShape ball;
    sf::Vector2f position;
    void Move();
    bool DidCollide(Player player);
    bool DidCollide(Wall wall);
    void SetBallAngle(float angle);
    float velocity = 10;
    double ballAngle;

    enum horizontal_direction{left, right};
    enum vertical_direction{up, down};
    horizontal_direction horizontalDirection = right;
    vertical_direction verticalDirection = down;
};


#endif //SFML_BOX2D_GAME_BALL_H
