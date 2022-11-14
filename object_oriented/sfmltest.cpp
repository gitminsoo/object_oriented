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
	// 초당 몇번이라 클수록 빠름

	NPC_SET npcs(5);

	GUN gun;

	while (window.isOpen()) // 열려있으면 1 리턴
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
		
		} // 이벤트 발생 안하면 이 while 문 건너 뜀


		gun.update(npcs);
		npcs.update();

		window.clear();

		npcs.draw(window);
		gun.draw(window);
		
		window.display();
	}
	
	return 0;
}

