
#include "NPC.h"

NPC::NPC(float _x, float _y, float _speed, Color _c) : x(_x), y(_y), speed(_speed), c(_c), offset_x(_speed)
{
	rectShape = RectangleShape(Vector2f(30.0f, 10.0f));
	rectShape.setFillColor(_c);
	rectShape.setPosition(x, y);
}
void NPC::draw(RenderWindow& _window)
{
	if (destroyed == true)
	{
		return;
	}
	_window.draw(rectShape);
}
void NPC::update()
{
	if (destroyed == true)
	{
		return;
	}
	Vector2f pos = rectShape.getPosition();
	if (pos.x > 600.f)
	{
		offset_x = -speed;
	}
	else if (pos.x < 30.0f)
	{
		offset_x = speed;
	}
	rectShape.move(offset_x, 0.0f);
}
FloatRect NPC::getArea()
{
	return rectShape.getGlobalBounds();
	// 사각형 영역을 넘겨준다.
}