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
	//Sprite* spaceship = nullptr;

	// ����Ʈ ������ ����
	unique_ptr <Sprite> spaceship;
	// p.339 'this'pointer
	// Ŭ���� �ȿ����� ����ϴ� ������
	// �ڱ� �ڽ��� ����Ű�� ������
	// ������ �ʾƵ� �˾Ƽ� ������� ����
	// �޼��忡�� ��� ���� �ٲ� ��
	// 
	//

	// p.337
	// ����� ���� �����ϱ�
	// nullptr�� ���� �����൵ ��

	Sprite burst;
	// �����̴� ���� 
	Font font;
	// ���� ��Ʈ
	Text text;
	// �� ����ִ°�
	// ���� ȭ��� ��µǴ� ���ڿ�


public:
	LunarLander(double h, double v, double f);
	void update(double dx, double dy); // ȭ��ǥ ������ ���� ���ϴ� xy��ġ
	void draw(RenderWindow& window);
	// ȭ���� �׷��������� �׷����� â
	~LunarLander();
	// �����̽� �� �޸� ������ ���� �ʿ�
	// �˾Ƽ� �������� ����

	//void setXY(double _x, double _y)
	//{
	//	x = _x;
	//	y = _y;
	//	// �⺻������ �Ķ���Ͱ� �켱 ������ ���´�
	//	// local parameter global���� �켱������ ������
	//	// ������� ������ ��
	//	// �츮�� ���ϴ� ������ �Ϸ���
	//	this->x = _x;
	//	this->y = _y;
	//	// �̰� ���� ���� ���


	//}
};

LunarLander::LunarLander(double h, double v, double f)
{
	// space ship image to texture
	t1.loadFromFile("images/spaceship.png");
	//spaceship = new Sprite(); // new delete type

	// ����Ʈ �����ʹ� ��ü�ϰ� �޼ҵ� �̿�
	spaceship.reset(new Sprite());

	spaceship->setTexture(t1);
	this->x = 500;
	// this pointer�� ���


	y = 200.0;
	spaceship->setPosition(x, y);
}
LunarLander::~LunarLander() {
	//delete spaceship;
}

void LunarLander::update(double dx, double dy)
{
	// x & y change shen press up,down,right,left key
	// each value is 10 -10 10 -10
	x += dx;
	y += dy;
	spaceship->setPosition(x, y);
}

void LunarLander::draw(RenderWindow& window)
{
	window.draw(*spaceship);
	// �����̽� ���� �����ͷ� �ٲ��
	// �� ���۷����� ���� *�� ����
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
	LunarLander* lander = new(LunarLander)(0.0, 0.0, 0.0);
	// ������ �θ��� ������� �ٲ�

	unique_ptr<LunarLander> lander2(new LunarLander(0.0, 0.0, 0.0));
	// ����Ʈ ������
	// �ڵ带 ���� ������ 1�� lander 2
	// ���� �����ڷ� ����������� ������ lander2
	// lander2 �� �Լ��� ������ ����� �� �˾Ƽ� ���ִ� �ڵ尡 �������
	// ¦ ���� �ڽ� ������ �� ����Ʈ ���°� ����
	//

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
			lander->update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			lander->update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			lander->update(-10, 0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			lander->update(10, 0);

		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			lander2->update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			lander2->update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			lander2->update(-10, 0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			lander2->update(10, 0);

		}

		// �����쿡 �׷��� ���� ������ �����
		window.clear();
		// ��������Ʈ�� ��׶��带 �׸���. 
		window.draw(background);

		lander->draw(window);
		lander2->draw(window);

		window.display();

		Sleep(100);
		//100ms. delay
	}

	delete lander;

	return 0;
}