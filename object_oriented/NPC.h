#pragma once 

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class NPC {
private:
	float x, y;
	float speed;
	Color c;
	RectangleShape rectShape;
	float offset_x;
public:
	NPC(float _x, float _y, float _speed, Color _c);
	void update();
	void draw(RenderWindow& _window);
	bool destroyed = false;
	FloatRect getArea();
};