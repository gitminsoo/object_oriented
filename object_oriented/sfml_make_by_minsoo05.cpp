// 미완성
// 무제한 샷 블락 꺠기 10반복

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <array>

using namespace std;
using namespace sf;

int main() {
	srand(time(NULL));
	//=====================================================

	char end_flag = 0;
	//========================================



	//====================================
	unsigned int break_cnt = 0;

	unsigned int line_cnt = 0;

	//=====================================================

	RenderWindow window(VideoMode(640, 480), "enjoy game");
	window.setFramerateLimit(60);
	//====================================================

	CircleShape fly(30, 3);
	fly.setFillColor(Color::Cyan);
	fly.setPosition(320 - fly.getRadius(), 400);

	//====================================================

	vector<vector<RectangleShape>> blocks;


	int y_pos = 30;

	for (auto i = 0; i < 10; i++)
	{
		int x_pos = 50 - rand() % 4 * 10;
		vector <RectangleShape> b_r;
		for (auto j = 0; j < 5; j++)
		{
			RectangleShape block(Vector2f(60, 20));
			block.setFillColor(Color::Blue);
			block.setPosition(x_pos, y_pos);
			x_pos = x_pos + 100 + rand() % 5 * 10;

			b_r.push_back(block);

		}
		y_pos = y_pos - 350;
		blocks.push_back(b_r);
	}

	int blocks_num[10][5];

	for (auto i = 0; i < 10; i++)
	{
		for (auto j = 0; j < 5; j++)
		{
			blocks_num[i][j] = rand() % 10 + 1;
		}
	}

	//=================================================

	vector<CircleShape> buls;
	unsigned int m_count = 0;


	//====================================================

	Text text[10][5];
	Font font;
	font.loadFromFile("images/OpenSans-Bold.ttf");

	for (auto i = 0; i < 10; i++)
	{
		for (auto j = 0; j < 5; j++)
		{
			text[i][j].setFont(font);
			text[i][j].setCharacterSize(20);
			text[i][j].setFillColor(Color::White);
			text[i][j].setString(to_string(blocks_num[i][j]));

		}
	}

	//=================================================

	Text cnt_break;
	cnt_break.setFont(font);
	cnt_break.setCharacterSize(50);
	cnt_break.setFillColor(Color::White);
	cnt_break.setPosition(200, 200);

	//==================================================
	Text line_t;
	line_t.setFont(font);
	line_t.setCharacterSize(40);
	line_t.setFillColor(Color::White);
	line_t.setPosition(230, 300);

	//===================================================


	while (window.isOpen())
	{



		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				fly.move(0, -10);
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				fly.move(0, 10);
			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				fly.move(-10, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				fly.move(10, 0);
			}

		}



		for (auto i = 0; i < 10; i++)
		{
			for (auto j = 0; j < 5; j++)
			{
				blocks[i][j].move(0, 2);

				if (blocks[i][j].getPosition().y >= 480 && blocks[i][j].getPosition().x > 0)
				{

					Vector2f block_pos = blocks[i][j].getPosition();
					blocks[i][j].setPosition(block_pos.x, block_pos.y - 300 * 10);
				}
			}
		}


		//==================================================

		m_count++;
		if (m_count >= 20)
		{
			CircleShape bul(10);
			bul.setFillColor(Color::Red);
			bul.setPosition(fly.getPosition().x + fly.getRadius() - bul.getRadius(), fly.getPosition().y);

			buls.push_back(bul);
			m_count = 0;
		}

		for (auto& i : buls)
		{
			i.move(0, -3);
		}


		for (auto i = 0; i < 10; i++)
		{
			for (auto j = 0; j < 5; j++)
			{
				FloatRect block_area = blocks[i][j].getGlobalBounds();

				for (auto& k : buls)
				{
					if (k.getPosition().y >= 0)
					{
						FloatRect bul_area = k.getGlobalBounds();

						if (bul_area.intersects(block_area) && blocks[i][j].getPosition().y >= 0)
						{
							blocks_num[i][j] --;
							k.setPosition(-1000, -1000);
							text[i][j].setString(to_string(blocks_num[i][j]));
							if (blocks_num[i][j] == 0)
							{
								break_cnt++;
								blocks[i][j].setPosition(1000, 1000);
							}


						}

					}
				}
			}
		}

		//==================================================

		for (auto i = 0; i < 10; i++)
		{
			for (auto j = 0; j < 5; j++)
			{
				FloatRect fly_area = fly.getGlobalBounds();
				FloatRect block_area = blocks[i][j].getGlobalBounds();
				if (fly_area.intersects(block_area))
				{
					end_flag = 1;
					sleep(milliseconds(100));
				}
			}
		}

		//====================================================

		for (auto i = 0; i < 10; i++)
		{
			for (auto j = 0; j < 5; j++)
			{
				if (blocks[i][j].getPosition().y >= 420)
				{
					line_cnt++;
				}
			}
		}



		//===================================================

		cnt_break.setString("break : " + to_string(break_cnt));
		line_t.setString("phase : " + to_string(line_cnt));

		window.clear();

		window.draw(cnt_break);
		//window.draw(line_t);

		window.draw(fly);

		for (auto i : blocks)
		{
			for (auto j : i)
			{
				window.draw(j);
			}
		}

		for (auto i = 0; i < 10; i++)
		{
			for (auto j = 0; j < 5; j++)
			{
				text[i][j].setPosition(blocks[i][j].getPosition().x + 20, blocks[i][j].getPosition().y - 2);
				window.draw(text[i][j]);
			}
		}

		for (auto i : buls)
		{
			window.draw(i);
		}





		window.display();

		if (end_flag == 1)
		{
			break;
		}

	}

	cout << "game_over" << endl;
}