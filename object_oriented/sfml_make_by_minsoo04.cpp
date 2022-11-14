// 비 피하기

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>

#define RAIN_NUM 5

using namespace sf;
using namespace std;

int main() {
	srand(time(NULL));
	//=====================================
	char end_flag = 0;
	//=====================================
	RenderWindow window(VideoMode(640, 420), "rain drop");
	window.setFramerateLimit(60);
	//=====================================

	RectangleShape ground(Vector2f(640, 50));
	ground.setFillColor(Color::Green);
	ground.setPosition(0, 400);

	//=====================================

	RectangleShape swipper(Vector2f(30, 30));
	swipper.setFillColor(Color::Cyan);
	swipper.setPosition(320 - swipper.getSize().x / 2, 400 - swipper.getSize().y);

	//=====================================

	vector <CircleShape> left_rain;
	vector <CircleShape> right_rain;

	for (auto i = 0; i < RAIN_NUM; i++)
	{
		CircleShape rain(20);
		rain.setFillColor(Color::Blue);

		int ran = rand() % 5;

		rain.setPosition(50 * ran, -300 * i);
		left_rain.push_back(rain);

		ran = rand() % 5;
		rain.setPosition(320 + 50 * ran, -300 * i);
		right_rain.push_back(rain);


	}


	//======================================

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
				swipper.move(-20, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				swipper.move(20, 0);
			}


		}

		for (auto& i : left_rain)
		{
			i.move(0, 5);
			if (i.getPosition().y >= 420)
			{
				Vector2f rain_pos = i.getPosition();
				i.setPosition(rain_pos.x, rain_pos.y - 300 * RAIN_NUM);
			}
		}

		for (auto& i : right_rain)
		{
			i.move(0, 5);
			if (i.getPosition().y >= 420)
			{
				Vector2f rain_pos = i.getPosition();
				i.setPosition(rain_pos.x, rain_pos.y - 300 * RAIN_NUM);
			}
		}

		FloatRect swipper_area = swipper.getGlobalBounds();

		for (int i = 0; i < RAIN_NUM; i++)
		{
			FloatRect left_area = left_rain[i].getGlobalBounds();
			FloatRect right_area = right_rain[i].getGlobalBounds();

			if (swipper_area.intersects(left_area) || swipper_area.intersects(right_area))
			{
				end_flag = 1;
			}
		}



		window.clear();

		window.draw(ground);
		window.draw(swipper);

		for (auto i : left_rain)
		{
			window.draw(i);
		}
		for (auto i : right_rain)
		{
			window.draw(i);
		}

		window.display();
		if (end_flag == 1)
		{
			sleep(milliseconds(100));
			break;
		}
	}


	cout << "game over" << endl;

}