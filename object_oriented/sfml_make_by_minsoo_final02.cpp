#if 0


#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>

using namespace std;
using namespace sf;

#define VIDEO_SIZE_X 1080
#define VIDEO_SIZE_Y 720

#define DIV_NUM 10

int main() {

	srand(time(NULL));

	//=============================================================================


	RenderWindow window(VideoMode(VIDEO_SIZE_X, VIDEO_SIZE_Y), "what game");
	window.setFramerateLimit(60);

	//=============================================================================

	CircleShape mover(5);
	mover.setFillColor(Color::Transparent);
	mover.setOutlineColor(Color::White);
	mover.setOutlineThickness(5);
	mover.setPosition(VIDEO_SIZE_X / 2 - mover.getRadius(), VIDEO_SIZE_Y / 2 - mover.getRadius());

	//=============================================================================

	char end_flag = 0;

	//=============================================================================

	vector<CircleShape> vc;

	//=============================================================================

	Clock clock;
	Clock ai_timer;
	float interval = 0, delay = 1.0;

	Time ai_time = seconds(1);

	//=============================================================================

	char ball_flag = 0;

	//=============================================================================

	vector<Vector2i> bul_pos_array;
	vector<Vector2f> bul_mov_array;

	vector<int> bul_open;

	//=============================================================================

	for (int i = 0; i < DIV_NUM; i++)
	{
		Vector2i tmp(i * VIDEO_SIZE_X / DIV_NUM, -10);
		bul_pos_array.push_back(tmp);
	}

	for (int i = 0; i < DIV_NUM; i++)
	{
		Vector2i tmp(VIDEO_SIZE_X + 10, i * VIDEO_SIZE_Y / DIV_NUM);
		bul_pos_array.push_back(tmp);
	}

	for (int i = 0; i < DIV_NUM; i++)
	{
		Vector2i tmp(i * VIDEO_SIZE_X / DIV_NUM, VIDEO_SIZE_Y + 10);
		bul_pos_array.push_back(tmp);
	}

	for (int i = 0; i < DIV_NUM; i++)
	{
		Vector2i tmp(-10, i * VIDEO_SIZE_Y / DIV_NUM);
		bul_pos_array.push_back(tmp);
	}


	//=============================================================================





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
		//=============================================================================

		Vector2i mouse_pos(Mouse::getPosition(window));
		mouse_pos.x = mouse_pos.x - mover.getRadius();
		mouse_pos.y = mouse_pos.y - mover.getRadius();

		mover.setPosition(mouse_pos.x, mouse_pos.y);

		//=============================================================================

		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();

		interval = interval + time;

		if (ai_timer.getElapsedTime() >= ai_time)
		{
			ball_flag = 1;
			ai_timer.restart();
			cout << interval << endl;
		}


		//=============================================================================

		if (ball_flag == 1)
		{
			CircleShape bul(5);
			bul.setFillColor(Color::Red);

			int rr = rand() % 40;
			int rrr = rand() % 5 + 3;

			bul.setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

			int i = 0;
			bul_open.push_back(i);

			vc.push_back(bul);

			int target_pos_x = rand() % (int)mover.getRadius() + mover.getPosition().x;
			int target_pos_y = rand() % (int)mover.getRadius() + mover.getPosition().y;

			float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + pow((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
			Vector2f move_v((target_pos_x - (int)bul.getPosition().x) / dist * rrr, (target_pos_y - (int)bul.getPosition().y) / dist * rrr);
			bul_mov_array.push_back(move_v);

			ball_flag = 0;
		}

		for (auto i = 0; i < vc.size(); i++)
		{
			if (vc[i].getPosition().x >= 0 && vc[i].getPosition().x <= VIDEO_SIZE_X - vc[i].getRadius() * 2)
			{
				if (vc[i].getPosition().y >= 0 && vc[i].getPosition().y <= VIDEO_SIZE_Y - vc[i].getRadius() * 2)
				{
					bul_open[i] = 1;
				}
			}
		}

		for (auto i = 0; i < vc.size(); i++)
		{
			vc[i].move(bul_mov_array[i].x, bul_mov_array[i].y);

			if (bul_open[i] == 1)
			{
				if (vc[i].getPosition().x < 0 || vc[i].getPosition().x > VIDEO_SIZE_X - vc[i].getRadius())
				{
					bul_mov_array[i].x = -bul_mov_array[i].x;
				}
				if (vc[i].getPosition().y < 0 || vc[i].getPosition().y > VIDEO_SIZE_Y - vc[i].getRadius())
				{
					bul_mov_array[i].y = -bul_mov_array[i].y;
				}
			}

		}





		//=============================================================================

		for (auto i : vc)
		{
			if (i.getGlobalBounds().intersects(mover.getGlobalBounds()))
			{
				end_flag = 1;
			}
		}


		//=============================================================================



		window.clear();

		for (auto i : vc)
		{
			window.draw(i);
		}

		window.draw(mover);

		window.display();

		if (end_flag == 1)
		{
			break;
		}

	}

	cout << "game set" << endl;


	return 0;
}

#endif