#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <time.h>

#define BALL_NUM 10
#define BALL_SPEED 10

using namespace std;
using namespace sf;

int main() {

	srand(time(NULL));

	RenderWindow window(VideoMode(640, 480), "make a game");
	window.setFramerateLimit(60);

	//======================================================

	vector <CircleShape> balls;

	for (auto i = 0; i < BALL_NUM; i++)
	{
		CircleShape ball(10);
		ball.setPosition(100, 100);
		ball.setFillColor(Color::Green);
		balls.push_back(ball);
	}

	//======================================================

	Vector2i balls_offset[BALL_NUM];

	for (auto i = 0; i < BALL_NUM; i++)
	{
		balls_offset[i].x = rand() % BALL_SPEED + 1;
		balls_offset[i].y = rand() % BALL_SPEED + 1;

	}


	//======================================================

	Font font;
	font.loadFromFile("images/OpenSans-Bold.ttf");


	Text bound_t;
	bound_t.setFillColor(Color::White);
	bound_t.setCharacterSize(20);
	bound_t.setPosition(300, 30);
	bound_t.setFont(font);

	unsigned int bound_num = 0;


	//======================================================

	RectangleShape lol(Vector2f(20, 480));
	lol.setPosition(50, 0);
	lol.setFillColor(Color::White);

	//======================================================

	RectangleShape keeper(Vector2f(150, 10));
	keeper.setPosition(250, 0);
	keeper.setFillColor(Color::White);

	//======================================================

	Text goal_t;
	goal_t.setFont(font);
	goal_t.setCharacterSize(20);
	goal_t.setFillColor(Color::White);
	goal_t.setPosition(300, 420);

	unsigned int goal_num = 0;


	//====================================================




	while (window.isOpen())
	{
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}

		}

		for (auto i = 0; i < BALL_NUM; i++)
		{
			balls[i].move(balls_offset[i].x, balls_offset[i].y);


			if (balls[i].getPosition().x <= lol.getPosition().x + lol.getSize().x)
			{
				if (balls[i].getPosition().y < 600)
				{
					bound_num++;
				}

				if (balls_offset[i].x <= 0)
				{
					balls_offset[i].x = -balls_offset[i].x;
				}
			}
			if (balls[i].getPosition().x >= 640 - balls[i].getRadius() * 2)
			{
				if (balls[i].getPosition().y < 600)
				{
					bound_num++;
				}

				if (balls_offset[i].x >= 0)
				{
					balls_offset[i].x = -balls_offset[i].x;
				}
			}
			if (balls[i].getPosition().y <= keeper.getPosition().y + keeper.getSize().y)
			{
				if (balls[i].getPosition().x >= keeper.getPosition().x && balls[i].getPosition().x <= keeper.getPosition().x + keeper.getSize().x)
				{
					if (balls[i].getPosition().y < 600)
					{
						bound_num++;
					}

					if (balls_offset[i].y <= 0)
					{
						balls_offset[i].y = -balls_offset[i].y;
					}
				}
				else if (balls[i].getPosition().y < -balls[i].getRadius() * 2)
				{
					balls[i].setPosition(1000, 1000);
					balls_offset[i].x = balls_offset[i].y = 0;
					goal_num++;
				}

			}
			if (balls[i].getPosition().y >= 480 - balls[i].getRadius() * 2)
			{
				if (balls[i].getPosition().y < 600)
				{
					bound_num++;
				}
				if (balls_offset[i].y >= 0)
				{

					balls_offset[i].y = -balls_offset[i].y;
				}
			}

		}

		//================================================

		Vector2i mouse_pos = Mouse::getPosition(window);
		keeper.setPosition(mouse_pos.x - keeper.getSize().x / 2, 0);


		//================================================

		bound_t.setString(to_string(bound_num));
		goal_t.setString(to_string(goal_num));

		//================================================



		window.clear();
		window.draw(bound_t);
		window.draw(goal_t);
		window.draw(lol);
		window.draw(keeper);
		for (auto i : balls)
		{
			window.draw(i);
		}

		window.display();

	}



	return 0;
}
