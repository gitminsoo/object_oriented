#include "NPC_SET.h"

NPC_SET::NPC_SET(int num)
{

	int inc = 0;

	Color colors[3] = { Color::Red,Color::Cyan,Color::Magenta };

	for (int i = 0; i < num; i++)
	{
		NPC npc(30.0f + inc, 30.0f + inc, (i + 1) * 2, colors[i % 3]);
		npcs.push_back(npc);
		// 끝에 멤버추가
		inc += 20;
	}
}
void NPC_SET::update() {
	for (auto& e : npcs)
	{
		// class private에 저장된 npcs를 사용

		// refernce 기호 꼭 넣기
		e.update();
	}
}
void NPC_SET::draw(RenderWindow& _window)
{
	for (auto& e : npcs)
	{
		e.draw(_window);
		// 그림 그리기
	}

}
void NPC_SET::sheckHit(FloatRect _rect)
{
	for (auto& _e : npcs)
	{
		if (_rect.intersects(_e.getArea()) == true)
		{
			_e.destroyed = true;
		}
	}
}