// 마우스를 이용한 블락 깨기

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace sf;


int main() {

	char flag = 0;
	int target_vel = 5;

	char bullet_flag = 0;

	RenderWindow window(VideoMode(640, 480), "first game");
	window.setFramerateLimit(60);

	CircleShape gun(50);
	gun.setFillColor(Color::Green);
	gun.setPosition(320 - gun.getRadius(), 480 - gun.getRadius());

	CircleShape bullet(10);
	bullet.setFillColor(Color::Red);
	bullet.setPosition(1000, 1000);

	RectangleShape target(Vector2f(50.0f, 20.0f));
	target.setFillColor(Color::Blue);
	target.setPosition(100, 100);



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
				if (bullet_flag == 0)
				{
					bullet.setPosition(gun.getPosition().x + gun.getRadius() - bullet.getRadius(), gun.getPosition().y);
					bullet_flag = 1;
				}

			}
		}
		Vector2i mouse_pos = Mouse::getPosition(window);
		if (mouse_pos.x < 0 + gun.getRadius()) mouse_pos.x = gun.getRadius();
		if (mouse_pos.x > 640 - gun.getRadius()) mouse_pos.x = 640 - gun.getRadius();


		gun.setPosition(mouse_pos.x - gun.getRadius(), 480 - gun.getRadius());

		if (bullet.getPosition().y < 0)
		{
			bullet_flag = 0;
		}

		bullet.move(0, -10);

		if (flag == 0)
		{
			target.move(target_vel, 0);
			if (target.getPosition().x >= (640 - target.getSize().x))
			{
				target_vel = -target_vel;
			}
			else if (target.getPosition().x <= 0)
			{
				target_vel = -target_vel;
			}
		}

		if (flag == 1)
		{
			target.setPosition(1000, 1000);
		}




		FloatRect bullet_area = bullet.getGlobalBounds();
		FloatRect target_area = target.getGlobalBounds();

		if (target_area.intersects(bullet_area))
		{
			bullet.setPosition(1000, 1000);
			flag = 1;
			bullet_flag = 0;
		}

		window.clear();


		window.draw(gun);
		window.draw(bullet);
		if (flag == 0)
		{
			window.draw(target);
		}


		window.display();
	}
}