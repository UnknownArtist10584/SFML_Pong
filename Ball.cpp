//
// Created by Varun Ramakrishnan on 4/2/16.
//

#include "Ball.h"
#include <iostream>

#define PI 3.14159265359

float deltaTime;

Ball::Ball(sf::Vector2u window_size)
{
    ball.setSize( sf::Vector2f(50, 50) );
    ball.setOrigin(ball.getGlobalBounds().width/2, ball.getGlobalBounds().height/2);
    ball.setPosition(window_size.x/2,  window_size.y/2);

    ballAngle = 180;

    // TODO: Make the ballAngle random and also make sure it isn't too steep

}

void Ball::Move()
{
    position = ball.getPosition();
    position.x += std::cos(ballAngle * PI/180) * velocity;
    position.y += std::sin(ballAngle * PI/180) * velocity;
    ball.setPosition(position);

}

bool Ball::DidCollide(Player player)
{
    if (true)
    {
        return  true;
    }

    else
    {
        return  false;
    }
}

bool Ball::DidCollide(Wall wall)
{
    return false;
}


void Ball::SetBallAngle(float angle)
{
    if (angle < 0)
    {
        ballAngle = 360 + angle;
    }

    else if (angle > 360)
    {
        ballAngle = 360 - angle;
    }
}



