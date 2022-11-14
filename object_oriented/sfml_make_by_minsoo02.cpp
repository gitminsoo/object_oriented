// 마우스를 이용한 블락깨기

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <time.h>
#include <array>

using namespace std;
using namespace sf;




int main() {
	//================================
	char button_flag = 0;
	//=====================================
	char is_start = 0;
	char bul_flag = 0;
	array<int, 5> move_vel;
	move_vel.fill(5);
	//=====================================
	char end_count = 0;
	char end_flag = 0;
	//===============================
	Text text;
	Font font;
	font.loadFromFile("images/OpenSans-Bold.ttf");
	//===========================
	int shoot = 0;
	int break_tar = 0;
	//========================
	Text num_text;
	num_text.setFont(font);

	//========================


	srand(time(NULL));

	RenderWindow window(VideoMode(640, 480), "make a game");
	window.setFramerateLimit(60);

	//=============================================
	CircleShape gun(50);
	gun.setPosition(320 - gun.getRadius(), 480 - gun.getRadius());
	gun.setFillColor(Color::Cyan);
	//=============================================

	CircleShape bul(10);
	bul.setPosition(1000, -1000);
	bul.setFillColor(Color::Red);

	//===========================================
	vector<RectangleShape> targets;

	for (auto i = 0; i < 5; i++)
	{
		auto ran = rand() % 500;
		RectangleShape target(Vector2f(60, 20));
		target.setFillColor(Color::Yellow);
		target.setPosition(ran, 25 * i);
		targets.push_back(target);
	}

	//============================================
	Texture start_t;
	start_t.loadFromFile("images/block.png");
	Texture end_t;
	end_t.loadFromFile("images/paddle.png");

	//===========================================

	while (window.isOpen())
	{
		Event e;

		RectangleShape title(Vector2f(150, 70));
		title.setPosition(320 - title.getSize().x / 2, 240 - title.getSize().y / 2);
		title.setTexture(&start_t);

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mouse_pos = Mouse::getPosition(window);

				if (mouse_pos.x > title.getPosition().x && mouse_pos.x < title.getPosition().x + title.getSize().x)
				{
					if (mouse_pos.y > title.getPosition().y && mouse_pos.y < title.getPosition().y + title.getSize().y)
					{
						button_flag = 1;
						break;
					}
				}


			}

		}
		if (button_flag == 1)
		{
			break;
		}
		window.clear();

		window.draw(title);

		window.display();
	}

	sleep(milliseconds(100));
	// 바로 볼 안나가게 해줌

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{

				if (bul_flag == 0)
				{
					bul.setPosition(gun.getPosition().x + gun.getRadius(), gun.getPosition().y);
					shoot++;
					bul_flag = 1;
				}

			}


		}

		Vector2i mouse_pos = Mouse::getPosition(window);
		if (mouse_pos.x <= 0 + gun.getRadius()) mouse_pos.x = 0 + gun.getRadius();
		if (mouse_pos.x >= 640 - gun.getRadius()) mouse_pos.x = 640 - gun.getRadius();
		gun.setPosition(mouse_pos.x - gun.getRadius(), 480 - gun.getRadius());


		bul.move(0, -10);
		if (bul.getPosition().y <= 0)
		{
			bul_flag = 0;
		}

		for (auto i = 0; i < 5; i++)
		{
			targets[i].move(move_vel[i], 0);
			if (targets[i].getPosition().x <= 0) move_vel[i] = -move_vel[i];
			if (targets[i].getPosition().x >= 640 - targets[i].getSize().x) move_vel[i] = -move_vel[i];
		}

		FloatRect bul_area = bul.getGlobalBounds();
		FloatRect targets_area[5];
		for (auto i = 0; i < 5; i++)
		{
			targets_area[i] = targets[i].getGlobalBounds();

			if (bul_area.intersects(targets_area[i]))
			{
				targets[i].setPosition(1000, 1000);
				bul.setPosition(1000, -1000);
				end_count++;
				break_tar++;
			}

		}


		if (end_count >= 5)
		{
			break;
		}


		string str = "shoot : " + to_string(shoot) + "\nbreak : " + to_string(break_tar);
		text.setString(str);
		text.setCharacterSize(20);
		text.setPosition(290, 190);
		text.setFillColor(Color::White);
		text.setFont(font);

		string num_str = to_string(5 - break_tar);
		num_text.setString(num_str);
		num_text.setPosition(gun.getPosition().x + gun.getRadius() -10 , gun.getPosition().y + gun.getRadius() - 30);
		num_text.setFillColor(Color::Magenta);
		num_text.setCharacterSize(20);

		window.clear();

		window.draw(text);
		

		window.draw(gun);

		for (auto i : targets)
		{
			window.draw(i);
		}



		window.draw(bul);
		window.draw(num_text);



		window.display();


	}

	while (window.isOpen())
	{
		Event e;

		RectangleShape title(Vector2f(150, 70));
		title.setPosition(320 - title.getSize().x / 2, 240 - title.getSize().y / 2);
		title.setTexture(&end_t);

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mouse_pos = Mouse::getPosition(window);

				if (mouse_pos.x > title.getPosition().x && mouse_pos.x < title.getPosition().x + title.getSize().x)
				{
					if (mouse_pos.y > title.getPosition().y && mouse_pos.y < title.getPosition().y + title.getSize().y)
					{
						end_flag = 1;
						break;
					}
				}


			}

		}
		if (end_flag == 1)
		{
			window.close();
		}
		window.clear();

		window.draw(title);

		window.display();
	}

}