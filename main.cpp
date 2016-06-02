#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Player.h"
#include "Wall.h"
#include "Ball.h"
#include <boost/lexical_cast.hpp>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    // Game state variable
    // 0 = Title screen, 1 = Game, 2 = Paused, 3 = Game won
    int game_state = 1;

    sf::RenderWindow window(sf::VideoMode(800 , 600 ), "Title");
    window.setFramerateLimit(60);

    sf::Event event;

    Player player1(window.getSize(), 1);
    Player player2(window.getSize(), 2);
    Ball ball(window.getSize());
    Wall top_wall(sf::Keyboard::Up, window.getSize());
    Wall bottom_wall(sf::Keyboard::Down, window.getSize());

    sf::Text score;
    sf::Font font;
    font.loadFromFile("assets/AmericanTypewriter.ttc");
    score.setFont(font);
    score.setString(boost::lexical_cast<string>(player1.score) + " | " + boost::lexical_cast<string>(player2.score) );
    score.setOrigin(score.getGlobalBounds().width/2, score.getGlobalBounds().width/2);
    score.setPosition(window.getSize().x/2, 100);


    while (window.isOpen() )
    {
        while(window.pollEvent(event))
        {
            if (event.type == event.Closed)                 // Close the SFML Window
            {
                window.close();
            }

            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            if (event.key.code == sf::Keyboard::P)
            {
                // If game is playing, pause it and vice-versa
                
                if (game_state == 1)
                {
                    game_state = 2;
                }

            }

            if (event.key.code == sf::Keyboard::Return)
            {
                game_state = 1;
            }
        }

        if (player1.score == 10)
        {
            game_state = 3;
        }

        if (player2.score == 10)
        {
            game_state = 4;
        }

        if (game_state == 1)
        {
            // Play the game
            // Check for user input and move the paddles accordingly

            if (sf::Keyboard::isKeyPressed(player1.up_control))
            {
                player1.MovePaddle(player1.up_control, window.getSize());
            }

            if (sf::Keyboard::isKeyPressed(player1.down_control))
            {
                player1.MovePaddle(player1.down_control, window.getSize());
            }

            if (sf::Keyboard::isKeyPressed(player2.up_control))
            {
                player2.MovePaddle(player2.up_control, window.getSize());
            }


            if (sf::Keyboard::isKeyPressed(player2.down_control))
            {
                player2.MovePaddle(player2.down_control, window.getSize());
            }

            // Check for collisions with the paddles
            // TODO: Calculate the angle of incidence and reflection for the new ballAngle
            // TODO: Check whether the paddle is moving to add spin
            // TODO: Decide what happens if the ball hits the bottom or top face of the paddle

            if (ball.DidCollide(player1))
            {
                // TODO: Add movement with left and right instead of angles
                // TODO: Find out what "Taking enum type from pointer" means

                ball.horizontal_direction = 1;
            }

            if (ball.DidCollide(player2))
            {
                ball.horizontal_direction = -1;

            }

            // Check for collisions with the walls

            if (ball.DidCollide(top_wall))
            {
                if (ball.vertical_direction == 1)
                {
                    ball.vertical_direction = -1;
                }
                else
                {
                    ball.vertical_direction = 1;
                }
            }

            if (ball.DidCollide(bottom_wall))
            {
                if (ball.vertical_direction == 1)
                {
                    ball.vertical_direction = -1;
                }
                else
                {
                    ball.vertical_direction = 1;
                }
            }


            // Check if the ball is out of bounds ( Goal scored )

            if (ball.ball.getPosition().x < 0)      // Player 2 has scored
            {
                player2.score++;
                ball.ResetBall(window.getSize());
            }

            if (ball.ball.getPosition().x > window.getSize().x)      // Player 1 has scored
            {
                player1.score++;
                ball.ResetBall(window.getSize());
            }

            // Move the ball at each frame
            ball.Move();

            // Update the score
            score.setString(
                    boost::lexical_cast<string>(player1.score) + " | " + boost::lexical_cast<string>(player2.score));

            // Draw all the objects to the screen

            window.clear();
            window.draw(player1.paddle);
            window.draw(player2.paddle);
            window.draw(top_wall.wall);
            window.draw(bottom_wall.wall);
            window.draw(score);
            window.draw(ball.ball);
            window.display();
        }

        if (game_state  == 2)
        {
            // Display pause screen
            sf::Text pause_text;
            pause_text.setFont(font);
            pause_text.setString("PAUSED");
            pause_text.setCharacterSize(30);
            pause_text.setPosition(window.getSize().x/2 - pause_text.getGlobalBounds().width/2,
                                   window.getSize().y/2 - pause_text.getGlobalBounds().height/2);
g
            window.clear();
            window.draw(pause_text);
            window.display();
        }

        if (game_state == 3)
        {
            sf::Text game_won_text;
            game_won_text.setFont(font);
            game_won_text.setCharacterSize(30);
            game_won_text.setString("Player 1 wins");
            game_won_text.setPosition(window.getSize().x/2 - game_won_text.getGlobalBounds().width/2,
                                      window.getSize().y/2 - game_won_text.getGlobalBounds().height/2);
            window.clear();
            window.draw(game_won_text);
            window.display();
        }

        if (game_state == 4)
        {
            sf::Text game_won_text;
            game_won_text.setFont(font);
            game_won_text.setCharacterSize(30);
            game_won_text.setString("Player 2 wins");
            game_won_text.setPosition(window.getSize().x/2 - game_won_text.getGlobalBounds().width/2,
                                      window.getSize().y/2 - game_won_text.getGlobalBounds().height/2);
            window.clear();
            window.draw(game_won_text);
            window.display();
        }
    }
}
