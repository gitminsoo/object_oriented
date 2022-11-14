#include <SFML/Graphics.hpp>
#include "GUN.h"

GUN::GUN() {
	gun = CircleShape(50.0f);
	// Ŭ���� ������ sfml ����Ʈ�� learn �� api documentation �� ����
	// �ڿ� ���� 10�� �ָ� 10�������� ����
	// ��ǻ�ʹ� ���� ����� ���� �ﰢ���� �̾ ����� ����
	// CircleShape shape(100.0f, 10);

	gun.setFillColor(Color::Cyan);
	gun.setPosition(320.0f - 50.0f, 480.0f - 50.0f);
	// ���� ���δ� �簢���� �»�� ���� �������� �׸��Ƿ�
	// 640/2-50(���� ũ��) , 480/2-50

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