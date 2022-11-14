// p.302

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

//
// 우리는 5시간 내에 만드는걸로 할 예정
// 오후 5시에서 12시정도면 하나 만들 수 있음 
// ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
// 
//

class LunarLander {
private:
	double x, y;
	// y축이 거꾸로 임
	// 현재 위치
	double velocity;
	// 속도
	double fuel;
	// 남아있는 연료 양
	string status;
	Texture t1, t2;
	Sprite spaceship, burst;
	// 움직이는 조각 
	Font font;
	// 글자 폰트
	Text text;
	// 글 찍어주는거

public:
	LunarLander(double h, double v, double f);
	void update(double rate);
	void draw(RenderWindow& window);
};

int main()
{
	// 우주선이 하강 하는데 
	// 키보드 화살표 키를 이용해 올라가는 프로그램

	


	return 0;
}