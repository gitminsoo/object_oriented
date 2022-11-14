// p.302
// 다른게임 만들어보기

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
	// 패턴 무늬
	// t1 space ship t2 fire
	Sprite spaceship, burst;
	// 움직이는 조각 
	Font font;
	// 글자 폰트
	Text text;
	// 글 찍어주는거
	// 게임 화면상에 출력되는 문자열


public:
	LunarLander(double h, double v, double f);
	void update(double dx,double dy); // 화살표 누름에 따라 변하는 xy위치
	void draw(RenderWindow& window);
	// 화면이 그래픽적으로 그려지는 창
};

LunarLander::LunarLander(double h, double v, double f)
{
	// space ship image to texture
	t1.loadFromFile("images/spaceship.png");
	spaceship.setTexture(t1);
	x = 500.0;
	y = 200.0;
	spaceship.setPosition(x, y);
}

void LunarLander::update(double dx, double dy)
{
	// x & y change shen press up,down,right,left key
	// each value is 10 -10 10 -10
	x += dx;
	y += dy;
	spaceship.setPosition(x, y);
}

void LunarLander::draw(RenderWindow& window)
{
	window.draw(spaceship);
}

int main()
{
	// 우주선이 하강 하는데 
	// 키보드 화살표 키를 이용해 올라가는 프로그램

	// 게임이 나타나는 창 만들기
	RenderWindow window(VideoMode(1025, 475), "Luna Lander");
	window.setFramerateLimit(60);
	// FPS 표시 
	// 중요한 이유 
	// 무한 루츠가 도는 속도를 지정해줌
	// 그래서 초당 60번만 반복문을 돌게 해줌
	// 보통 60이면 충분
	//

	Texture t; // 무늬 패턴 // 스프라이트 위에 그려지는 패턴
	Sprite background; // 실제로 화면에 그려지는 요소

	t.loadFromFile("images/background.png");
	background.setTexture(t);

	// 루프전에 달 착륙선을 만든다 
		// 0,0,0 은 사용하지 않으므로 그냥 아무수나 입력
	LunarLander lander(0.0, 0.0, 0.0);
	LunarLander lander2(0.0, 0.0, 0.0);

	// 윈도우가 열려있는 동안 초당 60번 
	while (window.isOpen())
	{
		Event e;
		// 폴은 이벤트 들어왔는지 확인하는것
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) {
				window.close();
			}
		}


		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			lander.update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			lander.update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			lander.update(-10,0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			lander.update(10,0);

		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			lander2.update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			lander2.update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			lander2.update(-10, 0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			lander2.update(10, 0);

		}

		// 윈도우에 그려진 것이 있으면 지운다
		window.clear();
		// 스프라이트인 백그라운드를 그린다. 
		window.draw(background);

		lander.draw(window);
		lander2.draw(window);

		window.display();

		Sleep(100); 
		//100ms. delay
	}



	return 0;
}