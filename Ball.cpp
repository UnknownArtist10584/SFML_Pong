//
// Created by Varun Ramakrishnan on 4/2/16.
//

#include "Ball.h"
#include <iostream>

#define PI 3.14159265359

float deltaTime;

Ball::Ball(sf::Vector2u window_size)
{
    ball.setRadius(25);
    ball.setOrigin(ball.getGlobalBounds().width/2, ball.getGlobalBounds().height/2);
    ball.setPosition(window_size.x/2,  window_size.y/2);

    ballAngle = 60;

    // TODO: Make the ballAngle random and also make sure it isn't too steep

    vertical_direction = 1;
    horizontal_direction = 1;

    // TODO: Randomize vertical and horizontal direction variables


}

void Ball::Move()
{
    /*
    position = ball.getPosition();
    position.x += std::cos(ballAngle * PI/180) * velocity;
    position.y += std::sin(ballAngle * PI/180) * velocity;
    ball.setPosition(position);
     */

    position = ball.getPosition();

    if (horizontal_direction == 1)
    {
        if (vertical_direction == 1)
        {
            position.x += std::cos(ballAngle * PI/180) * velocity;
            position.y -= std::sin(ballAngle * PI/180) * velocity;
        }

        if (vertical_direction == -1)
        {
            position.x += std::cos(ballAngle * PI/180) * velocity;
            position.y += std::sin(ballAngle * PI/180) * velocity;
        }
    }

    if (horizontal_direction == -1)
    {
        if (vertical_direction == 1)
        {
            position.x -= std::cos(ballAngle * PI/180) * velocity;
            position.y -= std::sin(ballAngle * PI/180) * velocity;
        }

        if (vertical_direction == -1)
        {
            position.x -= std::cos(ballAngle * PI/180) * velocity;
            position.y += std::sin(ballAngle * PI/180) * velocity;
        }

    }

    ball.setPosition(position);

}

bool Ball::DidCollide(Player player)
{
    if (player.paddle.getGlobalBounds().intersects(ball.getGlobalBounds()))
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
   if (wall.wall.getGlobalBounds().intersects(ball.getGlobalBounds()))
   {
       return true;
   }

   else
   {
       return false;
   }
}


void Ball::SetBallAngle(float angle)
{
    ballAngle = angle;
}

void Ball::ResetBall(sf::Vector2u window_size)
{
    ball.setPosition(window_size.x/2, window_size.y/2);
    // TODO: Generate random direction for ball
}





