//
// simple fast multimedia library
// sfml
// 

#include <SFML/Graphics.hpp>
#include <vector>
#include "NPC.h"
#include "NPC_SET.h"
#include "GUN.h"

using namespace std;
using namespace sf;


int main() {
	RenderWindow window(VideoMode(640, 480), "Hello SFML");
	window.setFramerateLimit(60);
	// �ʴ� ����̶� Ŭ���� ����

	NPC_SET npcs(5);

	GUN gun;

	while (window.isOpen()) // ���������� 1 ����
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
					window.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Left) == true)
				{
					gun.moveLeft();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right) == true)
				{
					gun.moveRight();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Space) == true)
				{
					
					gun.fireBullet();
				}
				break;

			default:
				break;
			}
		
		} // �̺�Ʈ �߻� ���ϸ� �� while �� �ǳ� ��


		gun.update(npcs);
		npcs.update();

		window.clear();

		npcs.draw(window);
		gun.draw(window);
		
		window.display();
	}
	
	return 0;
}

