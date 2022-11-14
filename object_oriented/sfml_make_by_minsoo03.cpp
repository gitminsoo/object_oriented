// 키보드를 이용한 점프로 피하기

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

#define BLOCK_NUM 20

using namespace std;
using namespace sf;

int main() {

	srand(time(NULL));
	//=============================
	char is_start = 0;
	char is_end = 0;
	char break_flag = 0;
	//==============================
	RenderWindow window(VideoMode(640, 420), "jump");
	window.setFramerateLimit(60);

	//===================================
	RectangleShape ground(Vector2f(640, 50));
	ground.setFillColor(Color::Green);
	ground.setPosition(0, 400);
	//===================================
	RectangleShape jumper(Vector2f(20, 20));
	jumper.setFillColor(Color::Cyan);
	jumper.setPosition(50, 200 - jumper.getSize().y);
	//==================================

	vector<RectangleShape> blocks;
	for (auto i = 0; i < BLOCK_NUM; i++)
	{
		int ran = rand() % 7;
		RectangleShape block(Vector2f(20, 20));
		block.setPosition(640 + 200 * i, 380 - 50 * ran);
		block.setFillColor(Color::Red);
		blocks.push_back(block);
	}
	//=====================================

	RectangleShape start_button(Vector2f(150, 70));
	start_button.setPosition(320 - 75, 210 - 35);

	Texture s_t;
	s_t.loadFromFile("images/block.png");

	Texture e_t;
	e_t.loadFromFile("images/paddle.png");

	//=====================================
	char s_e_flag = 0;
	//====================================
	Text alarm;
	Font font;
	font.loadFromFile("images/OpenSans-Bold.ttf");
	alarm.setFont(font);
	alarm.setFillColor(Color::White);
	alarm.setPosition(320 - 70, 100);
	alarm.setCharacterSize(20);

	//====================================

	while (window.isOpen())
	{
		start_button.setTexture(&s_t);

		string message = "click button\nOR push up button";
		alarm.setString(message);

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mouse_pos = Mouse::getPosition(window);
				if (mouse_pos.x > 320 - 75 && mouse_pos.x < 320 + 75)
				{
					if (mouse_pos.y > 210 - 35 && mouse_pos.y < 210 + 35);
					{
						s_e_flag = 1;
						break;
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				s_e_flag = 1;
				break;
			}
		}
		if (s_e_flag == 1)
		{
			break;
		}

		window.clear();
		window.draw(start_button);
		window.draw(alarm);
		window.display();

	}

	//================================================================

	while (window.isOpen())
	{
		string message = "press up key is jump\npress down is move-down\navoid red block\nif you touch sky or ground\nthis game is over\ngood luck";
		alarm.setString(message);
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				jumper.move(0, -90);
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (jumper.getPosition().y <= 400 - jumper.getSize().y)
				{
					jumper.move(0, 30);
				}
			}
		}



		if (jumper.getPosition().y < 380)
		{
			jumper.move(0, 3);
		}
		if (jumper.getPosition().y > 380)
		{
			jumper.setPosition(50, 400 - jumper.getSize().y);
		}

		for (auto& i : blocks)
		{
			i.move(-5, 0);
		}




		for (int i = 0; i < BLOCK_NUM; i++)
		{
			if (blocks[i].getPosition().x <= -(blocks[i].getSize().x))
			{
				Vector2f block_point = blocks[i].getPosition();
				blocks[i].setPosition(block_point.x + 200 * BLOCK_NUM, block_point.y);
			}
		}

		if (jumper.getPosition().y <= -30 || jumper.getPosition().y >= ground.getPosition().y - jumper.getSize().y)
		{
			if (jumper.getPosition().y <= 0)
			{
				Vector2f jumper_pos = jumper.getPosition();
				jumper.setPosition(jumper_pos.x, 0);
			}
			break_flag = 1;


		}

		FloatRect jumper_area = jumper.getGlobalBounds();

		for (auto i = 0; i < BLOCK_NUM; i++)
		{
			FloatRect block_area = blocks[i].getGlobalBounds();
			if (jumper_area.intersects(block_area))
			{
				break_flag = 1;
			}
		}


		window.clear();

		window.draw(alarm);

		window.draw(jumper);
		window.draw(ground);

		for (auto i = 0; i < BLOCK_NUM; i++)
		{
			window.draw(blocks[i]);
		}

		window.display();

		if (break_flag == 1)
		{
			sleep(milliseconds(1000));
			break;
		}

	}


	//=====================================================================================
	while (window.isOpen())
	{
		string message = "GAME OVER";
		alarm.setString(message);
		alarm.setCharacterSize(30);

		start_button.setTexture(&e_t);
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mouse_pos = Mouse::getPosition(window);
				if (mouse_pos.x > 320 - 75 && mouse_pos.x < 320 + 75)
				{
					if (mouse_pos.y > 210 - 35 && mouse_pos.y < 210 + 35);
					{
						s_e_flag = 0;
						break;
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				s_e_flag = 0;
				break;
			}
		}
		if (s_e_flag == 0)
		{
			break;
		}

		window.clear();
		window.draw(start_button);
		window.draw(alarm);
		window.display();

	}


}