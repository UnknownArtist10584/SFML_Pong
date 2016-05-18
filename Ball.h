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
    float velocity = 20;
    double ballAngle;

    /*
    enum horizontal_direction{left, right};
    enum vertical_direction{up, down};
    horizontal_direction horizontalDirection;
    vertical_direction verticalDirection;
    */

    int horizontal_direction;           // 1 -> right, -1 -> left
    int vertical_direction;             // 1 -> up, -1 -> down

    void Move();
    bool DidCollide(Player player);
    bool DidCollide(Wall wall);
    void ResetBall(sf::Vector2u window_size);
    void SetBallAngle(float angle);
};


#endif //SFML_BOX2D_GAME_BALL_H
