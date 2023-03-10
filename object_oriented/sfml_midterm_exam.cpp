#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

int main() {
	srand(time(NULL));
	//=============================================

	RenderWindow window(VideoMode(640, 480), "Pong Game");
	window.setFramerateLimit(60);
	//===============================================
	RectangleShape bar(Vector2f(640, 20));
	bar.setPosition(0, 100);
	bar.setFillColor(Color::Cyan);

	//===============================================

	RectangleShape st_btn(Vector2f(60, 30));
	st_btn.setPosition(290, 40);


	Texture st_btn_tex;
	st_btn_tex.loadFromFile("images/START.png");

	st_btn.setTexture(&st_btn_tex);

	//=================================================

	RectangleShape play_bar(Vector2f(20, 80));
	play_bar.setPosition(30, 240);
	play_bar.setFillColor(Color::Blue);

	//==================================================
	RectangleShape npc_bar(Vector2f(20, 80));
	npc_bar.setPosition(580, 240);
	npc_bar.setFillColor(Color::Red);

	//=================================================

	Font font;
	font.loadFromFile("images/OpenSans-Bold.ttf");

	//=================================================

	unsigned int play_num = 0;

	Text play_t;
	play_t.setFont(font);
	play_t.setCharacterSize(50);
	play_t.setFillColor(Color::Blue);
	play_t.setPosition(120, 20);
	play_t.setString(to_string(play_num));

	//=================================================

	unsigned int npc_num = 0;

	Text npc_t;
	npc_t.setFont(font);
	npc_t.setCharacterSize(50);
	npc_t.setFillColor(Color::Red);
	npc_t.setPosition(450, 20);


	//=================================================


	CircleShape ball(10);
	ball.setFillColor(Color::Green);
	ball.setPosition(320 - ball.getRadius(), 300 - ball.getRadius());

	Vector2i ball_init;
	ball_init.x = 320 - ball.getRadius();
	ball_init.y = 300 - ball.getRadius();

	Vector2i ball_offset;
	ball_offset.x = -4;
	ball_offset.y = -4;



	//=================================================

	char st_flag = 0;

	//=================================================
	int npc_offset = 5;

	RectangleShape end_w(Vector2f(300, 200));
	end_w.setPosition(170, 140);

	Texture win;
	win.loadFromFile("images/WIN.png");
	end_w.setTexture(&win);

	RectangleShape end_l(Vector2f(300, 200));
	end_l.setPosition(170, 140);

	Texture loose;
	loose.loadFromFile("images/LOSE.png");
	end_l.setTexture(&loose);

	//==========================================


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
				if (st_btn.getPosition().x <= Mouse::getPosition(window).x &&
					st_btn.getPosition().x + st_btn.getSize().x >= Mouse::getPosition(window).x)
				{
					if (st_btn.getPosition().y < Mouse::getPosition(window).y &&
						st_btn.getPosition().x + st_btn.getSize().x >= Mouse::getPosition(window).x)
					{
						st_flag = 1;
					}

				}
			}
			else
			{
				break;
			}
		}

		//===========================================

		if (st_flag == 1)
		{
			ball.move(ball_offset.x, ball_offset.y);
			st_flag = 2;
		}
		if (st_flag == 2)
		{
			ball.move(ball_offset.x, ball_offset.y);
		}

		//===========================================


		if (ball.getPosition().x <= 0)
		{
			npc_num++;
			ball.setPosition(ball_init.x, ball_init.y);
			st_flag = 0;
		}
		if (ball.getPosition().x + ball.getRadius() >= 640)
		{
			play_num++;
			ball.setPosition(ball_init.x, ball_init.y);
			st_flag = 0;
		}

		if (ball.getPosition().y <= bar.getPosition().y + bar.getSize().y)
		{

			if (ball_offset.y < 0)
			{
				ball_offset.y = -ball_offset.y;
			}

		}

		if (ball.getPosition().y >= 480 - ball.getRadius() * 2) {

			if (ball_offset.y > 0)
			{
				ball_offset.y = -ball_offset.y;
			}
		}
		//=========================================

		if (ball.getPosition().x <= play_bar.getPosition().x + play_bar.getSize().x &&
			ball.getPosition().x >= play_bar.getPosition().x)
		{
			if (ball.getPosition().y >= play_bar.getPosition().y &&
				ball.getPosition().y + ball.getRadius() * 2 <= play_bar.getPosition().y + play_bar.getSize().y)
			{
				if (ball_offset.x < 0)
				{
					ball_offset.x = -ball_offset.x;
				}
			}
		}

		if (ball.getPosition().x + ball.getRadius() * 2 <= npc_bar.getPosition().x + npc_bar.getSize().x &&
			ball.getPosition().x + ball.getRadius() * 2 >= npc_bar.getPosition().x)
		{
			if (ball.getPosition().y >= npc_bar.getPosition().y &&
				ball.getPosition().y + ball.getRadius() * 2 <= npc_bar.getPosition().y + npc_bar.getSize().y)
			{
				if (ball_offset.x > 0)
				{
					ball_offset.x = -ball_offset.x;
				}
			}
		}
		//====================================================

		Vector2i mouse_pos = Mouse::getPosition(window);
		if (mouse_pos.y <= 160)
		{
			mouse_pos.y = 160;
		}
		if (mouse_pos.y >= 440)
		{
			mouse_pos.y = 450;
		}
		if (st_flag == 1 || st_flag == 2)
		{
			Vector2f play_bar_pos = play_bar.getPosition();
			play_bar.setPosition(play_bar_pos.x, mouse_pos.y - play_bar.getSize().y / 2);
		}


		if (st_flag == 1 || st_flag == 2)
		{
			npc_bar.move(0, npc_offset);
			if (npc_bar.getPosition().y <= 120)
			{
				npc_offset = -npc_offset;
			}
			if (npc_bar.getPosition().y >= 400)
			{
				npc_offset = -npc_offset;
			}
		}



		//===========================================

		npc_t.setString(to_string(npc_num));
		play_t.setString(to_string(play_num));

		//===========================================


		window.clear();

		window.draw(bar);
		window.draw(st_btn);
		window.draw(play_bar);
		window.draw(npc_bar);
		window.draw(ball);
		window.draw(play_t);
		window.draw(npc_t);


		window.display();


		if (npc_num >= 3 || play_num >= 3)
		{
			break;
		}

	}
	//================================




	//================================

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

		window.clear();

		if (npc_num >= 3)
		{
			window.draw(end_l);

		}
		else
		{
			window.draw(end_w);

		}





		window.display();

	}





}

