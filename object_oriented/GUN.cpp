#include <SFML/Graphics.hpp>
#include "GUN.h"

GUN::GUN() {
	gun = CircleShape(50.0f);
	// 클래스 정보는 sfml 사이트에 learn 에 api documentation 이 있음
	// 뒤에 숫자 10을 주면 10각형으로 변함
	// 컴퓨터는 원을 만들기 힘들어서 삼각형을 이어서 만들기 때문
	// CircleShape shape(100.0f, 10);

	gun.setFillColor(Color::Cyan);
	gun.setPosition(320.0f - 50.0f, 480.0f - 50.0f);
	// 원을 감싸는 사각형의 좌상단 점을 기준으로 그리므로
	// 640/2-50(원의 크기) , 480/2-50

	showBullet = false;

	bullet = CircleShape(5.0f);
	bullet.setFillColor(Color::Red);
}
void GUN::moveLeft()
{
	gun.move(-10.0f, 0.0f);
}
void GUN::moveRight()
{
	gun.move(10.0f, 0.0f);
}
void GUN::fireBullet()
{
	if (showBullet == false)
	{
		Vector2f pos = gun.getPosition();
		bullet.setPosition(pos.x + 50.0f, pos.y);
		showBullet = true;
	}
}
void GUN::update(NPC_SET& npcs)
{
	if (showBullet == true)
	{
		bullet.move(0.0f, -8.0f);
		if (bullet.getPosition().y < 0.0f)
		{
			showBullet = false;
		}
		else
		{
			// bullet's FloatRect 
			// NPC_SET obj's checkHit() call
			npcs.sheckHit(bullet.getGlobalBounds());
		}
	}
}
void GUN::draw(RenderWindow& _window)
{
	_window.draw(gun);
	if (showBullet == true)
	{
		_window.draw(bullet);
	}
}