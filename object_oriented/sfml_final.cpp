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

	//=======================================================================================


	RenderWindow window(VideoMode(VIDEO_SIZE_X, VIDEO_SIZE_Y), "what game");
	window.setFramerateLimit(60);

	//=======================================================================================

	RectangleShape mover(Vector2f(10, 10));
	mover.setFillColor(Color::Blue);
	mover.setPosition(VIDEO_SIZE_X / 2 - mover.getSize().x, VIDEO_SIZE_Y / 2 - mover.getSize().y / 2);

	//========================================================================================

	Texture st_texture;
	st_texture.loadFromFile("images/START.png");

	//========================================================================================

	RectangleShape st_btn(Vector2f(100, 50));
	st_btn.setPosition(VIDEO_SIZE_X / 2 - st_btn.getSize().x / 2, 50);
	st_btn.setTexture(&st_texture);

	//========================================================================================

	char st_flag = 0;
	char end_flag = 0;

	char time_flag = 0;

	//========================================================================================


	Clock clock;
	Clock ai_timer;
	float interval = 0, delay = 1.0;

	Time ai_time = seconds(2);

	Clock clock2;
	Clock ai_timer2;
	float interval2 = 0, delay2 = 1.0;

	Time ai_time2 = seconds(5);


	Clock clock3;
	Clock ai_timer3;
	float interval3 = 0, delay3 = 1.0;

	Time ai_time3 = seconds(10);

	Clock clock4;
	Clock ai_timer4;
	float interval4 = 0, delay4 = 1.0;

	Time ai_time4 = seconds(3);

	//========================================================================================
	float slow = 1;
	vector<CircleShape> vc;

	char ball_flag = 0;

	//========================================================================================

	vector<Vector2i> bul_pos_array;
	vector<Vector2f> bul_mov_array;

	vector<int> bul_open;
	char first_five_ball = 0;

	vector<RectangleShape> heal_v;
	int heal_cnt = 0;

	vector<RectangleShape> del_v;
	int del_cnt = 0;

	//========================================================================================

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


	//========================================================================================

	int life = 3;

	int ball = 0;

	//========================================================================================

	Font font;
	font.loadFromFile("images/OpenSans-Bold.ttf");

	//========================================================================================

	Text life_t;
	life_t.setFont(font);
	life_t.setCharacterSize(50);
	life_t.setPosition(100, 650);


	Text ball_num_t;
	ball_num_t.setFont(font);
	ball_num_t.setCharacterSize(50);
	ball_num_t.setPosition(400, 650);


	Text time_tt;
	time_tt.setFont(font);
	time_tt.setCharacterSize(50);
	time_tt.setPosition(800, 650);

	Text end_tt;
	end_tt.setFont(font);
	end_tt.setCharacterSize(50);


	//========================================================================================

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
					Vector2i mouse_pos(Mouse::getPosition(window));
					if (st_btn.getPosition().x <= mouse_pos.x && st_btn.getPosition().x + st_btn.getSize().x >= mouse_pos.x)
					{
						if (st_btn.getPosition().y <= mouse_pos.y && st_btn.getPosition().y + st_btn.getSize().y >= mouse_pos.y)
						{
							st_flag = 1;
							clock.restart();
							ai_timer.restart();
							interval = 0;

							clock2.restart();
							ai_timer2.restart();
							interval2 = 0;
							break;
						}
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				int bp = 1;
				if (bp == 1)
				{
					bp = 0;
				}
				bp = 1;
			}
			else
			{
				break;
			}
		}




		//========================================================================================


		if (st_flag == 1)
		{

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				mover.move(0, -3);
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				mover.move(0, 3);
			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				mover.move(-3, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				mover.move(3, 0);
			}
			if (mover.getPosition().x <= 0)
			{
				mover.setPosition(0, mover.getPosition().y);
			}
			if (mover.getPosition().x + mover.getSize().x >= VIDEO_SIZE_X)
			{
				mover.setPosition(VIDEO_SIZE_X - mover.getSize().x, mover.getPosition().y);
			}
			if (mover.getPosition().y <= 0)
			{
				mover.setPosition(mover.getPosition().x, 0);
			}
			if (mover.getPosition().y + mover.getSize().y >= VIDEO_SIZE_Y)
			{
				mover.setPosition(mover.getPosition().x, VIDEO_SIZE_Y - mover.getSize().y);
			}

			float time = clock.getElapsedTime().asMilliseconds();
			clock.restart();

			interval = interval + time;

			if (ai_timer.getElapsedTime() >= ai_time)
			{

				ai_timer.restart();

				ball_flag = 1;
			}

			float time2 = clock2.getElapsedTime().asMilliseconds();
			clock2.restart();

			interval2 = interval2 + time2;

			if (ai_timer2.getElapsedTime() >= ai_time2)
			{
				heal_cnt = 1;
				ai_timer2.restart();


			}

			float time3 = clock3.getElapsedTime().asMilliseconds();
			clock3.restart();

			interval3 = interval3 + time3;

			if (ai_timer3.getElapsedTime() >= ai_time3)
			{
				del_cnt = 1;
				ai_timer3.restart();
			}

			float time4 = clock4.getElapsedTime().asMilliseconds();
			clock4.restart();

			interval4 = interval4 + time4;

			if (ai_timer4.getElapsedTime() >= ai_time4)
			{
				time_flag = 0;
				slow = 1;
				ai_timer4.restart();
			}

			//========================================================================================


			for (auto i = 0; i < 5; i++)
			{
				CircleShape bul(3);
			}

			if (time_flag == 1)
			{
				float time3 = clock3.getElapsedTime().asMilliseconds();
				clock3.restart();

				interval3 = interval3 + time3;
			}

			//========================================================================================

			if (heal_cnt == 1)
			{
				RectangleShape heal(Vector2f(10, 10));
				heal.setPosition(rand() % 900 + 100, rand() % 400 + 100);
				heal.setFillColor(Color::Magenta);
				heal_v.push_back(heal);
				heal_cnt = 0;
			}
			if (del_cnt == 1)
			{
				RectangleShape del(Vector2f(10, 10));
				del.setPosition(rand() % 900 + 100, rand() % 400 + 100);
				del.setFillColor(Color::Cyan);
				del_v.push_back(del);
				del_cnt = 0;
			}

			//========================================================================================



			if (first_five_ball == 0)
			{
				for (auto i = 0; i < 5; i++)
				{
					CircleShape bul(3);
					bul.setFillColor(Color::White);
					int rr = rand() % 40;

					bul.setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

					int l = 0;
					bul_open.push_back(l);
					int rrr = 3;

					/*int target_pos_x = rand() % (int)mover.getSize().x;
					int target_pos_y = rand() % (int)mover.getSize().y;*/

					int target_pos_x = 300 + 70 * i;
					int target_pos_y = 300 + 70 * i;

					float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + powf((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
					// -- 

					Vector2f move_v((target_pos_x - bul.getPosition().x) / dist * 3, (target_pos_y - bul.getPosition().y) / dist * 3);
					bul_mov_array.push_back(move_v);

					vc.push_back(bul);

				}

				first_five_ball = 1;
			}

			if (ball_flag == 1)
			{

				if ((vc.size() + 1) % 5 == 0)
				{
					int r_s = rand() % 3 + 3;

					CircleShape bul(3);
					bul.setFillColor(Color::Green);
					int rr = rand() % 40;

					bul.setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

					int l = 0;
					bul_open.push_back(l);
					int rrr = rand() % 3 + 3;

					/*int target_pos_x = rand() % (int)mover.getSize().x;
					int target_pos_y = rand() % (int)mover.getSize().y;*/

					int target_pos_x = rand() % (int)mover.getSize().x + (int)mover.getPosition().x;
					int target_pos_y = rand() % (int)mover.getSize().y + (int)mover.getPosition().y;

					float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + powf((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
					// -- 

					Vector2f move_v((target_pos_x - bul.getPosition().x) / dist * rrr, (target_pos_y - bul.getPosition().y) / dist * rrr);
					bul_mov_array.push_back(move_v);

					vc.push_back(bul);

					ball_flag = 0;
				}

				//========================================================================================

				else
				{
					int r_s = rand() % 3 + 3;

					CircleShape bul(3);
					bul.setFillColor(Color::White);
					int rr = rand() % 40;

					bul.setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

					int l = 0;
					bul_open.push_back(l);
					int rrr = 3;

					/*int target_pos_x = rand() % (int)mover.getSize().x;
					int target_pos_y = rand() % (int)mover.getSize().y;*/

					int target_pos_x = rand() % 300 + 300;
					int target_pos_y = rand() % 300 + 300;

					float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + powf((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
					// -- 

					Vector2f move_v((target_pos_x - bul.getPosition().x) / dist * r_s, (target_pos_y - bul.getPosition().y) / dist * r_s);
					bul_mov_array.push_back(move_v);

					vc.push_back(bul);

					ball_flag = 0;
				}
			}


			for (auto i = 0; i < vc.size(); i++)
			{
				vc[i].move(bul_mov_array[i].x * slow, bul_mov_array[i].y * slow);

				if (vc[i].getPosition().x >= 0 && vc[i].getPosition().x + vc[i].getRadius() * 2 <= VIDEO_SIZE_X)
				{
					if (vc[i].getPosition().y >= 0 && vc[i].getPosition().y + vc[i].getRadius() * 2 <= VIDEO_SIZE_Y)
					{
						bul_open[i] = 1;
					}

				}

				if (bul_open[i] == 1)
				{
					int r_s = rand() % 3 + 3;
					if (vc[i].getPosition().x + vc[i].getRadius() * 2 <= 0 || vc[i].getPosition().x >= VIDEO_SIZE_X)
					{
						if ((i + 1) % 5 == 0)
						{
							int rr = rand() % 40;
							vc[i].setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

							int target_pos_x = mover.getPosition().x;
							int target_pos_y = mover.getPosition().y;

							float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + powf((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
							// -- 

							Vector2f move_v((target_pos_x - vc[i].getPosition().x) / dist * r_s, (target_pos_y - vc[i].getPosition().y) / dist * r_s);
							bul_mov_array[i] = move_v;

							bul_open[i] = 0;
						}
						else
						{
							int rr = rand() % 40;
							vc[i].setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

							int target_pos_x = rand() % 300 + 300;
							int target_pos_y = rand() % 300 + 300;

							float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + powf((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
							// -- 

							Vector2f move_v((target_pos_x - vc[i].getPosition().x) / dist * r_s, (target_pos_y - vc[i].getPosition().y) / dist * r_s);
							bul_mov_array[i] = move_v;

							bul_open[i] = 0;
						}


					}
					if (vc[i].getPosition().y + vc[i].getRadius() * 2 <= 0 || vc[i].getPosition().y >= VIDEO_SIZE_Y)
					{
						if ((i + 1) % 5 == 0)
						{
							int rr = rand() % 40;
							vc[i].setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

							int target_pos_x = mover.getPosition().x;
							int target_pos_y = mover.getPosition().y;

							float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + powf((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
							// -- 

							Vector2f move_v((target_pos_x - vc[i].getPosition().x) / dist * 3, (target_pos_y - vc[i].getPosition().y) / dist * 3);
							bul_mov_array[i] = move_v;

							bul_open[i] = 0;
						}
						else
						{
							int rr = rand() % 40;
							vc[i].setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

							int target_pos_x = rand() % 300 + 300;
							int target_pos_y = rand() % 300 + 300;

							float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + powf((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
							// -- 

							Vector2f move_v((target_pos_x - vc[i].getPosition().x) / dist * 3, (target_pos_y - vc[i].getPosition().y) / dist * 3);
							bul_mov_array[i] = move_v;

							bul_open[i] = 0;
						}
					}
				}
			}


		}
		//========================================================================================

		for (auto i = 0; i < vc.size(); i++)
		{
			if (vc[i].getGlobalBounds().intersects(mover.getGlobalBounds()))
			{
				life = life - 1;
				if ((i + 1) % 5 == 0)
				{
					int rr = rand() % 40;
					vc[i].setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

					int target_pos_x = mover.getPosition().x;
					int target_pos_y = mover.getPosition().y;

					float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + powf((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
					// -- 

					Vector2f move_v((target_pos_x - vc[i].getPosition().x) / dist * 3, (target_pos_y - vc[i].getPosition().y) / dist * 3);
					bul_mov_array[i] = move_v;

					bul_open[i] = 0;
				}
				else
				{
					int rr = rand() % 40;
					vc[i].setPosition(bul_pos_array[rr].x, bul_pos_array[rr].y);

					int target_pos_x = rand() % 300 + 300;
					int target_pos_y = rand() % 300 + 300;

					float dist = sqrt(powf((float)target_pos_x - (float)bul_pos_array[rr].x, 2) + powf((float)target_pos_y - (float)bul_pos_array[rr].y, 2));
					// -- 

					Vector2f move_v((target_pos_x - vc[i].getPosition().x) / dist * 3, (target_pos_y - vc[i].getPosition().y) / dist * 3);
					bul_mov_array[i] = move_v;

					bul_open[i] = 0;
				}
				continue;
			}
		}


		//========================================================================================

		for (int i = 0; i < heal_v.size(); i++)
		{
			if (heal_v[i].getGlobalBounds().intersects(mover.getGlobalBounds()))
			{
				heal_v[i].setPosition(-2000, -2000);
				life++;
			}
		}
		for (int i = 0; i < del_v.size(); i++)
		{
			if (del_v[i].getGlobalBounds().intersects(mover.getGlobalBounds()))
			{
				del_v[i].setPosition(-2000, -2000);
				time_flag = 1;
				slow = 0.2;
				ai_timer4.restart();
			}
		}

		//========================================================================================


		life_t.setString("life : " + to_string(life));
		ball_num_t.setString("ball : " + to_string(vc.size()));

		int sec = interval / 1000;
		int milli = (int)interval % 1000 / 10;

		time_tt.setString(to_string(sec) + " : " + to_string(milli));

		//========================================================================================

		if (life == 0)
		{
			end_flag = 1;
		}

		window.clear();

		if (st_flag == 0)
		{
			window.draw(st_btn);
		}
		if (st_flag == 1)
		{
			window.draw(life_t);
			window.draw(ball_num_t);
			window.draw(time_tt);

		}

		for (auto i : heal_v)
		{
			window.draw(i);
		}
		for (auto i : del_v)
		{
			window.draw(i);
		}

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

	end_tt.setPosition(400, 100);
	time_tt.setPosition(400, 300);
	time_tt.setCharacterSize(50);
	end_tt.setString("GAME OVER");
	ball_num_t.setPosition(400, 200);
	ball_num_t.setCharacterSize(50);
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

		window.clear();

		window.draw(end_tt);

		ball_num_t.setString("ball : " + vc.size());

		life_t.setString("life : " + to_string(life));
		ball_num_t.setString("ball : " + to_string(vc.size()));

		int sec = interval / 1000;
		int milli = (int)interval % 1000 / 10;

		time_tt.setString("record : " + to_string(sec) + " : " + to_string(milli));

		window.draw(ball_num_t);
		window.draw(time_tt);

		window.display();
	}




	return 0;
}