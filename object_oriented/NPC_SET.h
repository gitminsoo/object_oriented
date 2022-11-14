#pragma once 

#include <SFML/Graphics.hpp>
#include <vector>
#include "NPC.h"
using namespace std;
using namespace sf;


class NPC_SET
{
private:
	vector<NPC> npcs;
public:
	NPC_SET(int num);
	void update();
	void draw(RenderWindow& _window);
	void sheckHit(FloatRect _rect);
};