#if 0

#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include <math.h>

using namespace std;
using namespace sf;

#define VIDEO_SIZE_X 1080
#define VIDEO_SIZE_Y 720

#define B1_POS_X 50
#define B1_POS_Y 50

#define B2_POS_X 490
#define B2_POS_Y 330


int main() {

	srand(time(NULL));

	//===================================================================================

	RenderWindow window(VideoMode(VIDEO_SIZE_X, VIDEO_SIZE_Y), "my game");
	window.setFramerateLimit(60);

	//===================================================================================

	vector<CircleShape> vc;

	//===================================================================================

	vector<Vector2f> ball_mov;

	//===================================================================================

	RectangleShape b1(Vector2f(100, 100));
	b1.setPosition(VIDEO_SIZE_X / 2 - b1.getSize().x / 2, VIDEO_SIZE_Y / 2 - b1.getSize().y / 2);
	b1.setFillColor(Color::Red);

	//===================================================================================

	Vector2i b1_mo(rand() % 3 + 3, rand() % 3 + 3);

	//===================================================================================

	RectangleShape b2(Vector2f(50, 50));
	b2.setPosition(100, 100);
	b2.setFillColor(Color::Blue);

	//===================================================================================

	Texture start_trxture;
	start_trxture.loadFromFile("images/START.png");

	//===================================================================================

	RectangleShape b3(Vector2f(100, 50));
	b3.setPosition(800, 50);
	//b3.setFillColor(Color::Blue);
	b3.setTexture(&start_trxture);

	//===================================================================================

	int time_change = 1000;

	Clock clock;
	Clock ai_timer;
	float interval = 0, delay = 1.0;

	Time ai_time = milliseconds(time_change);

	//===================================================================================

	char ball_flag = 0;

	//===================================================================================

	char st_flag = 0;
	char end_flag = 0;

	//===================================================================================

	Font font;
	font.loadFromFile("images/OpenSans-Bold.ttf");

	//===================================================================================

	Text sec_t;
	sec_t.setFont(font);
	sec_t.setCharacterSize(50);
	sec_t.setFillColor(Color::White);
	sec_t.setPosition(400, 50);

	//===================================================================================


	Text interval_t;
	interval_t.setFont(font);
	interval_t.setCharacterSize(50);
	interval_t.setFillColor(Color::White);
	interval_t.setPosition(500, 50);

	//===================================================================================

	Texture back_texture;
	back_texture.loadFromFile("images/background3.png");

	//===================================================================================

	RectangleShape back(Vector2f(VIDEO_SIZE_X, VIDEO_SIZE_Y));
	back.setPosition(0, 0);
	//b3.setFillColor(Color::Blue);
	back.setTexture(&back_texture);

	//===================================================================================



	//===================================================================================


	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (st_flag == 0)
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					Vector2i button_pos(Mouse::getPosition(window));
					if (b3.getPosition().x < button_pos.x && b3.getPosition().x + b3.getSize().x>button_pos.x)
					{
						if (b3.getPosition().y < button_pos.y && b3.getPosition().y + b3.getSize().y>button_pos.y)
						{
							sleep(milliseconds(100));
							st_flag = 1;
							clock.restart();
							ai_timer.restart();
							break;
						}
					}
				}
			}

			else
			{
				break;
			}
		}

		if (st_flag == 1)
		{
			//===================================================================================

			float time = clock.getElapsedTime().asMilliseconds();
			clock.restart();

			interval = interval + time;

			if (ai_timer.getElapsedTime() >= ai_time)
			{
				ball_flag = 1;
				ai_timer.restart();
			}

			//===================================================================================

			Vector2i mous_pos = Mouse::getPosition(window);

			mous_pos.x = mous_pos.x - b2.getSize().x / 2;
			mous_pos.y = mous_pos.y - b2.getSize().y / 2;

			if (mous_pos.x < 0) {
				mous_pos.x = 0;
			}
			if (mous_pos.x + b2.getSize().x > VIDEO_SIZE_X) {
				mous_pos.x = VIDEO_SIZE_X - b2.getSize().x;
			}
			if (mous_pos.y < 0) {
				mous_pos.y = 0;
			}
			if (mous_pos.y + b2.getSize().y > VIDEO_SIZE_Y) {
				mous_pos.y = VIDEO_SIZE_Y - b2.getSize().y;
			}

			b2.setPosition(mous_pos.x, mous_pos.y);

			//===================================================================================

			b1.move(b1_mo.x, b1_mo.y);

			if (b1.getPosition().x < 0)
			{
				b1_mo.x = -b1_mo.x;
			}
			if (b1.getPosition().x + b1.getSize().x > VIDEO_SIZE_X)
			{
				b1_mo.x = -b1_mo.x;
			}
			if (b1.getPosition().y < 0)
			{
				b1_mo.y = -b1_mo.y;
			}
			if (b1.getPosition().y + b1.getSize().y > VIDEO_SIZE_Y)
			{
				b1_mo.y = -b1_mo.y;
			}

			//===================================================================================


			if (ball_flag == 1)
			{
				time_change = time_change - 100;
				if (time_change <= 500)
				{
					time_change = 500;
				}
				ai_time = milliseconds(time_change);

				CircleShape c1(15);

				Vector2i st_pos(rand() % (int)b1.getSize().x + b1.getPosition().x, rand() % (int)b1.getSize().y + b1.getPosition().y);
				Vector2i ed_pos(rand() % (int)b2.getSize().x + b2.getPosition().x, rand() % (int)b2.getSize().y + b2.getPosition().y);

				c1.setPosition(st_pos.x, st_pos.y);

				c1.setOutlineColor(Color::Red);
				c1.setFillColor(Color::Transparent);
				c1.setOutlineThickness(5);

				vc.push_back(c1);

				float div_num = sqrt(powf((ed_pos - st_pos).x, 2) + powf((ed_pos - st_pos).y, 2));

				int rand_spd = rand() % 6 + 5;

				Vector2f rand_move((ed_pos - st_pos).x / div_num * rand_spd, (ed_pos - st_pos).y / div_num * rand_spd);

				ball_mov.push_back(rand_move);

				ball_flag = 0;

			}

			//===================================================================================

			for (auto i = 0; i < vc.size(); i++)
			{
				vc[i].move(ball_mov[i]);
			}

			//===================================================================================

			for (auto i : vc)
			{
				if (i.getGlobalBounds().intersects(b2.getGlobalBounds()) || b1.getGlobalBounds().intersects(b2.getGlobalBounds()))
				{
					end_flag = 1;
				}
			}

			//===================================================================================
		}

		//===================================================================================
		//===================================================================================


		int sec = interval / 1000;
		int milli = (int)interval % 1000 / 10;

		sec_t.setString(to_string(sec) + " : ");
		interval_t.setString(to_string(milli));

		window.clear();

		window.draw(back);

		window.draw(sec_t);
		window.draw(interval_t);

		window.draw(b1);
		window.draw(b2);

		if (st_flag == 0)
		{
			window.draw(b3);
		}

		for (auto i : vc)
		{
			window.draw(i);
		}

		window.display();

		if (end_flag == 1)
		{
			sleep(milliseconds(500));
			break;
		}

	}

	sec_t.setPosition(400, 215);
	interval_t.setPosition(500, 215);

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			else
			{
				break;
			}
		}



		int sec = interval / 1000;
		int mill = (int)interval % 1000 / 10;

		sec_t.setString(to_string(sec) + " : ");
		interval_t.setString(to_string(mill));

		window.clear();

		window.draw(back);


		window.draw(sec_t);
		window.draw(interval_t);


		window.display();
	}


	return 0;
}

#endif