#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "Paddle.h"

int main()
{
	sf::VideoMode VM(1280, 720);
	sf::RenderWindow window(VM, "Pong");
	sf::Clock clock;
	ball myball(1280/2,0);
	sf::Time dt;
	sf::Event event;
	Paddle myPaddle(1280 / 2, 695);

	while (window.isOpen())
	{

		dt = clock.restart();

		if (myball.getPosition().intersects(myPaddle.getPosition()))
		{
			myball.hitBall();
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			myPaddle.moveLeft();

		}
		else
		{
			myPaddle.stopLeft();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			myPaddle.moveRight();
		}
		else
		{
			myPaddle.stopRight();
		}




		if (myball.getPosition().left < 0 or myball.getPosition().left + myball.getPosition().width > 1280)
		{
			myball.bounceSides();

		}

		if (myball.getPosition().top < 0)
		{
			myball.bounceTop();
		}

		if (myball.getPosition().top + myball.getPosition().height > 720)
		{
			myball.missBottom();
		}
		window.clear();

		myball.update(dt);
		myPaddle.update(dt);

		window.draw(myball.getShape());
		window.draw(myPaddle.getShape());

		window.display();

	}
}

