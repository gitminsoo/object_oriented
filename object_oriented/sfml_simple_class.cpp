// p.302
// �ٸ����� ������

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

//
// �츮�� 5�ð� ���� ����°ɷ� �� ����
// ���� 5�ÿ��� 12�������� �ϳ� ���� �� ���� 
// ����������������������������
// 
//

class LunarLander {
private:
	double x, y;
	// y���� �Ųٷ� ��
	// ���� ��ġ
	double velocity;
	// �ӵ�
	double fuel;
	// �����ִ� ���� ��
	string status;
	Texture t1, t2; 
	// ���� ����
	// t1 space ship t2 fire
	Sprite spaceship, burst;
	// �����̴� ���� 
	Font font;
	// ���� ��Ʈ
	Text text;
	// �� ����ִ°�
	// ���� ȭ��� ��µǴ� ���ڿ�


public:
	LunarLander(double h, double v, double f);
	void update(double dx,double dy); // ȭ��ǥ ������ ���� ���ϴ� xy��ġ
	void draw(RenderWindow& window);
	// ȭ���� �׷��������� �׷����� â
};

LunarLander::LunarLander(double h, double v, double f)
{
	// space ship image to texture
	t1.loadFromFile("images/spaceship.png");
	spaceship.setTexture(t1);
	x = 500.0;
	y = 200.0;
	spaceship.setPosition(x, y);
}

void LunarLander::update(double dx, double dy)
{
	// x & y change shen press up,down,right,left key
	// each value is 10 -10 10 -10
	x += dx;
	y += dy;
	spaceship.setPosition(x, y);
}

void LunarLander::draw(RenderWindow& window)
{
	window.draw(spaceship);
}

int main()
{
	// ���ּ��� �ϰ� �ϴµ� 
	// Ű���� ȭ��ǥ Ű�� �̿��� �ö󰡴� ���α׷�

	// ������ ��Ÿ���� â �����
	RenderWindow window(VideoMode(1025, 475), "Luna Lander");
	window.setFramerateLimit(60);
	// FPS ǥ�� 
	// �߿��� ���� 
	// ���� ������ ���� �ӵ��� ��������
	// �׷��� �ʴ� 60���� �ݺ����� ���� ����
	// ���� 60�̸� ���
	//

	Texture t; // ���� ���� // ��������Ʈ ���� �׷����� ����
	Sprite background; // ������ ȭ�鿡 �׷����� ���

	t.loadFromFile("images/background.png");
	background.setTexture(t);

	// �������� �� �������� ����� 
		// 0,0,0 �� ������� �����Ƿ� �׳� �ƹ����� �Է�
	LunarLander lander(0.0, 0.0, 0.0);
	LunarLander lander2(0.0, 0.0, 0.0);

	// �����찡 �����ִ� ���� �ʴ� 60�� 
	while (window.isOpen())
	{
		Event e;
		// ���� �̺�Ʈ ���Դ��� Ȯ���ϴ°�
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) {
				window.close();
			}
		}


		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			lander.update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			lander.update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			lander.update(-10,0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			lander.update(10,0);

		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			lander2.update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			lander2.update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			lander2.update(-10, 0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			lander2.update(10, 0);

		}

		// �����쿡 �׷��� ���� ������ �����
		window.clear();
		// ��������Ʈ�� ��׶��带 �׸���. 
		window.draw(background);

		lander.draw(window);
		lander2.draw(window);

		window.display();

		Sleep(100); 
		//100ms. delay
	}



	return 0;
}