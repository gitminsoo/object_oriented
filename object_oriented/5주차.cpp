//
// include 폴더 : 클래스, function declaration 모음
//                클래스 definition 모음
// 
// lib 폴더 : 클래스, 함수 구현 소스코드의 컴파일 결과를
//            바이너리 코드를 한데 묶어 놓은 것 
//            ---> 내가 작성한 코드와 묶는 과정을 link 
// 
// 방식의 문제점 
// --> 다른 이용자도 sfml 이용시 한 프로그램 안에 
// sfml 중복 -> 메모리 중복 
// 다른 문제 sfml 업그레이드 시 
// 다른 애들을 링크를 다시 해야 하는 문제점 발생
// 
// 이문제들을 해결하고자 나온게 dll 이라는 개념 
// dynamically linked library
// 반대 개념은 statically linked library
// 
// DLL
// 이전에는 모든것을 링크 했지만 
// 이것은 하나의 sfml 만을 이용하며 
// 찾아가는 최소의 정보만 제공
// 업데이트도 sfml 하나만 하면 됨
// 
// 이 dll 들이 bin 에 모여있음
// bin 없는 애들도 있음
// 
// sll 은 다른 폴더에 대한 의존성이 없어서 편하다는 장점
// (버전 문제 등)
// 
//

// p.293
//

#include <SFML/Graphics.hpp>
using namespace sf;

//책
//3개 넣으라고 함
//sfml - graphics
//system
//window
//
//- d 가 붙은게 있음
//- d 붙은거로 하는게 맞음
//디버그 모드
//안붙은건 릴리즈 모드

int main()
{
	RenderWindow window(VideoMode(200, 200), "First Example");
	// 화면 창의 크기 200,200 (가로,세로)
	// renderwindow의 생성자 호출

	CircleShape shape(100.0f);
	shape.setFillColor(Color::Green);

	while (window.isOpen())
	{
		Event e;

		while (window.pollEvent(e)) {
			// poll 은 이벤트 검사 하는거
			// e에 담아서 알려주렴
			if (e.type == Event::Closed) {
				// 건드려서 e 에 값이 넘어가고
				// 이벤트 타입이 창닫침 버튼 누르면 
				window.close();
				// 윈도우 닫아 버림
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	return 0;
}
