#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class ENEMY
{
public:
	RectangleShape rect;
	float offset_x;
	bool enemy_alive;

	ENEMY();
	void draw(RenderWindow& _window);
	void update();
};
ENEMY::ENEMY()
{
	enemy_alive = true;

	rect = RectangleShape(Vector2f(80.0f, 20.0f));
	rect.setFillColor(Color::Magenta);
	rect.setPosition(30, 30);

	offset_x = 2.0f;


}
void ENEMY::draw(RenderWindow& _window)
{
	if (enemy_alive == false) {
		return;
	}
	_window.draw(rect);
}
void ENEMY::update()
{
	if (enemy_alive == false) {
		return;
	}
	// rect ��ü�� ȭ���� ��/���� �����ڸ��� �����ϸ� offset_x����
	// ��ȣ�� �ݴ�� ���ش�.
	
	// 1. rect ��ü�� ��ġ������ ���.
	Vector2f rect_pos = rect.getPosition();

	// 2. ȭ�� �����ڸ��� �����ߴ��� �Ǵ�.
	if (rect_pos.x <= 0) { // ȭ���� ���� �����ڸ� ����.
		offset_x = 2.0f;
	}
	else if (rect_pos.x + rect.getSize().x >= 640) // ȭ���� ���� �����ڸ� ����.
	{
		offset_x = -2.0f;
	}

	rect.move(offset_x, 0);
}

class GUN
{
public:
	CircleShape body;
	CircleShape bullet;
	bool bullet_alive;

	GUN();

	void update(RenderWindow& _window);
	void draw(RenderWindow& _window);
	void fire();
};
GUN::GUN()
{
	body = CircleShape(50);
	body.setFillColor(Color::Green);
	body.setPosition(640 / 2 - body.getRadius(), 480 - body.getRadius()); // ȭ���� �ϴܺ� �߽�.

	bullet = CircleShape(10, 3);
	bullet.setFillColor(Color::White);
	bullet.setPosition(999, 999); // ȭ�� ������ ������.

	bullet_alive = false;
}
void GUN::update(RenderWindow& _window)
{
	// �� ��ü�� ���콺 Ŀ���� ��������� ����.
	Vector2i mouse_pos = Mouse::getPosition(_window);
	body.setPosition(mouse_pos.x - body.getRadius(), body.getPosition().y);

	// �� ��ü�� ȭ�� ���� ����� �ʵ��� ����.
	// 
	// 1. �� ��ü�� ��ġ�� ���
	Vector2f body_pos = body.getPosition();
	// 2. �� ��ġ������ ������� ȭ������� �������� �Ǵ�.
	if (body_pos.x <= 0) { // ȭ�� ���� ħ��.
		body.setPosition(0, body_pos.y);
	}
	else if (body_pos.x + 2 * body.getRadius() >= 640) // ȭ�� ���� ħ��.
	{
		body.setPosition(640 - 2 * body.getRadius(), body_pos.y);
	}
	
	// �Ѿ��� ���� �����̱�
	if (bullet_alive == true) {
		bullet.move(0, -5.0f);
	}

	// �Ѿ��� window�� ���� ��ܺθ� ������� �Ǵ�.
	// �Ѿ� ��ü�� ��ġ
	Vector2f bullet_pos = bullet.getPosition();
	if (bullet_pos.y <= 0) { // �Ѿ��� ȭ���� ��ܺθ� ����� ��.
		bullet_alive = false;
	}
}
void GUN::draw(RenderWindow& _window)
{
	_window.draw(body);
	if (bullet_alive == true) {
		_window.draw(bullet);
	}
}
void GUN::fire()
{
	if (bullet_alive == true) {
		return;
	}

	bullet_alive = true;

	// �Ѿ��� body�� �߾� ��ܺη� ��������.
	Vector2f body_pos = body.getPosition();
	bullet.setPosition(body_pos.x + body.getRadius() - bullet.getRadius(), body_pos.y);
}

class GAME
{
public:
	// �� ��ü
	ENEMY enemy;
	// �� ��ü
	GUN gun;

	void fire();
	void update(RenderWindow& _window);
	void draw(RenderWindow& _window);
};
void GAME::fire()
{
	gun.fire();
}
void GAME::update(RenderWindow& _window)
{
	enemy.update();
	gun.update(_window);
	// enemy.rect
	// gun.bullet
	// �� �� ��ü�� ���� �浹 �ߴ��� �˻�.

	FloatRect enemy_area = enemy.rect.getGlobalBounds();
	FloatRect bullet_area = gun.bullet.getGlobalBounds();
	if (enemy_area.intersects(bullet_area) == true && enemy.enemy_alive == true && gun.bullet_alive == true) { // �浹
		gun.bullet_alive = false;
		enemy.enemy_alive = false;
	}

}
void GAME::draw(RenderWindow& _window)
{
	enemy.draw(_window);
	gun.draw(_window);
}

int main()
{
	RenderWindow window(VideoMode(640, 480), "shoot");
	window.setFramerateLimit(120);

	GAME game;

	while (window.isOpen())
	{
		// ���콺�� ��Ŭ�� event�� ����.

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
				// ���콺�� ��Ŭ������ �Ѿ� �߻�.
				if (Mouse::isButtonPressed(Mouse::Left) == true) {
					// �Ѿ��� �߻�.
					game.fire();
				}

				break;

			default:
				break;
			}
		}

		/* update */
		game.update(window);
		
		/* clear */
		window.clear();

		/* draw */
		game.draw(window);

		/* display */
		window.display();
	}



	return 0;
}