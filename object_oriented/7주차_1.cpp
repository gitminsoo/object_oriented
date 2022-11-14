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
	//Sprite* spaceship = nullptr;

	// 스마트 포인터 버전
	unique_ptr <Sprite> spaceship;
	// p.339 'this'pointer
	// 클래스 안에서만 사용하는 포인터
	// 자기 자신을 가리키는 포인터
	// 만들지 않아도 알아서 만들어져 있음
	// 메서드에서 멤버 값을 바꿀 때
	// 
	//

	// p.337
	// 멤버도 동적 생성하기
	// nullptr도 자정 안해줘도 됨

	Sprite burst;
	// 움직이는 조각 
	Font font;
	// 글자 폰트
	Text text;
	// 글 찍어주는거
	// 게임 화면상에 출력되는 문자열


public:
	LunarLander(double h, double v, double f);
	void update(double dx, double dy); // 화살표 누름에 따라 변하는 xy위치
	void draw(RenderWindow& window);
	// 화면이 그래픽적으로 그려지는 창
	~LunarLander();
	// 스페이스 쉽 메모리 해제를 위해 필요
	// 알아서 없애주지 않음

	//void setXY(double _x, double _y)
	//{
	//	x = _x;
	//	y = _y;
	//	// 기본적으로 파라미터가 우선 순위를 갖는다
	//	// local parameter global등의 우선순위를 가진다
	//	// 순서대로 배정이 됨
	//	// 우리가 원하는 뜻으로 하려면
	//	this->x = _x;
	//	this->y = _y;
	//	// 이게 제일 좋은 방법


	//}
};

LunarLander::LunarLander(double h, double v, double f)
{
	// space ship image to texture
	t1.loadFromFile("images/spaceship.png");
	//spaceship = new Sprite(); // new delete type

	// 스마트 포인터는 객체니가 메소드 이용
	spaceship.reset(new Sprite());

	spaceship->setTexture(t1);
	this->x = 500;
	// this pointer의 사용


	y = 200.0;
	spaceship->setPosition(x, y);
}
LunarLander::~LunarLander() {
	//delete spaceship;
}

void LunarLander::update(double dx, double dy)
{
	// x & y change shen press up,down,right,left key
	// each value is 10 -10 10 -10
	x += dx;
	y += dy;
	spaceship->setPosition(x, y);
}

void LunarLander::draw(RenderWindow& window)
{
	window.draw(*spaceship);
	// 스페이스 쉽이 포인터로 바뀌니
	// 디 레퍼런싱을 위해 *을 붙임
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
	LunarLander* lander = new(LunarLander)(0.0, 0.0, 0.0);
	// 생성자 부르는 방식으로 바뀜

	unique_ptr<LunarLander> lander2(new LunarLander(0.0, 0.0, 0.0));
	// 스마트 포인터
	// 코드를 보면 주인이 1명 lander 2
	// 뒤의 생성자로 만들어진것의 주인은 lander2
	// lander2 가 함수가 끝나면 사라질 때 알아서 없애는 코드가 들어있음
	// 짝 맞출 자신 있으면 뉴 딜리트 쓰는게 나음
	//

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
			lander->update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			lander->update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			lander->update(-10, 0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			lander->update(10, 0);

		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			lander2->update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			lander2->update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			lander2->update(-10, 0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			lander2->update(10, 0);

		}

		// 윈도우에 그려진 것이 있으면 지운다
		window.clear();
		// 스프라이트인 백그라운드를 그린다. 
		window.draw(background);

		lander->draw(window);
		lander2->draw(window);

		window.display();

		Sleep(100);
		//100ms. delay
	}

	delete lander;

	return 0;
}