#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>

#define BALL_NUM 10

using namespace std;
using namespace sf;

int main() {
	//==========================================
	srand(time(NULL));
	//==========================================


	RenderWindow window(VideoMode(640, 480), "make a game");
	window.setFramerateLimit(30);

	//====================================================

	Text text;
	Font font;
	font.loadFromFile("images/OpenSans-Bold.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition(300, 50);

	//==============================================

	Text cyan_t;
	cyan_t.setPosition(10, 220);
	cyan_t.setCharacterSize(20);
	cyan_t.setFont(font);

	Text red_t;
	red_t.setPosition(600, 220);
	red_t.setCharacterSize(20);
	red_t.setFont(font);

	//===============================================
	unsigned int cnt = 0;
	//===============================================
	unsigned int cyan_num = 0;
	unsigned int red_num = 0;

	//=========================================

	//==============================================

	RectangleShape lol(Vector2f(30, 480));
	lol.setPosition(50, 0);
	lol.setFillColor(Color::Cyan);

	RectangleShape lor(Vector2f(30, 480));
	lor.setPosition(560, 0);
	lor.setFillColor(Color::Red);


	//===============================================

	vector<CircleShape> balls;
	Vector2i ball_vec[10];

	for (auto i = 0; i < BALL_NUM; i++)
	{
		CircleShape ball(10);
		ball.setFillColor(Color::Green);
		ball.setPosition(100, 100);
		balls.push_back(ball);
	}

	for (auto i = 0; i < BALL_NUM; i++)
	{
		ball_vec[i].x = rand() % 10 + 1;
		ball_vec[i].y = rand() % 10 + 1;
	}


	//====================================================

	RectangleShape goal(Vector2f(150, 10));
	goal.setPosition(260, -5);
	goal.setFillColor(Color::White);


	//===================================
	unsigned int goal_num = 0;

	Text goal_t;
	goal_t.setPosition(600, 350);
	goal_t.setCharacterSize(20);
	goal_t.setFont(font);

	char goalflag[BALL_NUM] = { 0, };

	//====================================


	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				goal.move(-10, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				goal.move(10, 0);
			}
		}

		//==============================================
		Vector2i mouse_pos = Mouse::getPosition(window);
		goal.setPosition(mouse_pos.x - goal.getSize().x / 2, 0);

		//==============================================


		for (auto i = 0; i < BALL_NUM; i++)
		{
			balls[i].move(ball_vec[i].x, ball_vec[i].y);
		}

		for (auto i = 0; i < BALL_NUM; i++)
		{


			if (balls[i].getPosition().x <= lol.getPosition().x + lol.getSize().x)
			{
				ball_vec[i].x = -ball_vec[i].x;
				if (balls[i].getPosition().y < 500)
				{
					cnt++;
				}
				balls[i].setFillColor(Color::Cyan);
			}
			if (balls[i].getPosition().x >= lor.getPosition().x - balls[i].getRadius() * 2)
			{
				ball_vec[i].x = -ball_vec[i].x;
				if (balls[i].getPosition().y < 500)
				{
					cnt++;
				}
				balls[i].setFillColor(Color::Red);


			}
			if (balls[i].getPosition().x >= goal.getPosition().x && balls[i].getPosition().x + balls[i].getRadius() * 2 <= goal.getPosition().x + goal.getSize().x)
			{
				if (balls[i].getPosition().y <= goal.getPosition().y + goal.getSize().y)
				{

					ball_vec[i].y = -ball_vec[i].y;
					if (balls[i].getPosition().y < 500)
					{
						cnt++;
					}
				}
			}

			if (balls[i].getPosition().y <= 0)
			{
				goal_num++;
				balls[i].setPosition(1000, 1000);
				ball_vec[i].x = 0;
				ball_vec[i].y = 0;

			}

			if (balls[i].getPosition().y >= 480 - balls[i].getRadius() * 2)
			{
				ball_vec[i].y = -ball_vec[i].y;
				if (balls[i].getPosition().y < 500)
				{
					cnt++;
				}

				//balls[i].setFillColor(Color::Green);


			}
		}
		//===============================

		text.setString(to_string(cnt));

		//===========================
		cyan_num = 0;
		red_num = 0;

		for (auto i : balls)
		{

			//===============================================

			//================================================
			if (i.getFillColor() == (Color::Cyan))
			{
				cyan_num++;
			}
			if (i.getFillColor() == (Color::Red))
			{
				red_num++;
			}

		}

		cyan_t.setString(to_string(cyan_num));
		red_t.setString(to_string(red_num));
		goal_t.setString(to_string(goal_num));

		//=========================


		window.clear();

		window.draw(goal);
		window.draw(goal_t);
		window.draw(text);
		window.draw(lol);
		window.draw(lor);
		window.draw(cyan_t);
		window.draw(red_t);

		for (auto i : balls)
		{
			window.draw(i);
		}


		window.display();

	}

}