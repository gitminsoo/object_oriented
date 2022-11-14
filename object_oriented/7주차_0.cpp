//
// 오늘은 진도 나갈거
// p. 323
// 
// 포인터
//

#include <iostream>
#include <string>

using namespace std;


// p.344 const 멤버함수

class Person {
public:
	int age;
	Person() {
		age = 10;
	}
	Person(int _age) :age(_age) {}

	int showAge(int x) const
	{
		age = age * 100;
		// 이런걸 넣는 경우가 생김
		// 그래서 이런걸 막기 위해서 
		// const 멤버 함수
		// 클래스 안에서 멤버 함수를 만들때
		// 함수뒤에 const 를 붙이면 
		// 이 함수 안에서는 멤버변수를 바꾸지 않는다는 뜻
		// 어기먄 컴파일 에러

		return age;
		// read 하는거얌
	}
};

int main() {

	// #define NULL 0
	// -> 포인터가 아무것도 가르키지 않는다.
	// 
	// c++ 에서는 nullptr을 확실히 하기위한 예약어가 생김
	//
	/*int* p = nullptr;
	int a = 10;
	p = &a;*/
	// p. 325
	// 초기화 함
	// 0 or NULL 은 0을 의미
	// 이거야 말로 진짜 null pointer
	// 장점 : 가독성이 좋아진다.
	// auto p에 대한 for를 생각하면
	// 정수형 포인터형 두가지를 리턴 할 수 있는 가능성
	// nullptr은 반환형이 pointer 인것을 확실히 알 수 있음
	//

	// p.328
	// 동적 메모리 할당 : dynamic memory allocation
	// ex : malloc/ free : heap 공유 메모리
	// 정적 메모리 할당 : static memory allocation
	// ex : array
	// 
	// c++ DMA : new --> malloc, delete --> free
	// malloc free 가 하는 역할은 다 하지만 추가적 기능 가능
	// 
	//

	int* a = (int*)malloc(sizeof(int));
	free(a);
	// 둘의 하는 일이 같음
	int* a = new int;
	delete a;

	int* b = (int*)malloc(sizeof(int) * 10);
	free(b);
	// 타입을 10개 받는 경우
	int* b = new int[10];
	delete[] b;
	// 배열처럼 생겼으니 지우는 문법

	string* s = new string[10];
	s[0] = "hello";
	s[1] = "world";
	delete[] s;
	
	// 뉴와 딜리트 왜 만든건가?
	// 그렇게 느끼는 게 맞음
	// 할당 받을때는 잘 안사용 됨
	// 만들어진 이유 클래스
	//

	Person p;
	p.age = 20;
	Person p[20];
	// 정적할당

	// 동적할당
	// 이렇게만 하면 됨

	/*Person* pp = nullptr;
	pp = new Person;
	pp = new Person(21);
	delete pp;*/

	// new 가 생긴 이유
	// clss 로부터 객체를 생성하기 위해서
	// malloc으로 new가 하는 일을 못아는 이유
	// -- malloc으로 객체를 위한 메모리는 할당 받을 수 있지만
	// -- malloc 은 생성자 호출을 못함
	// 
	// 그럼 기본 int 같은거는 왜 쓰냐
	// 어떤떄는 malloc new 구분을 하기 귀찮아서
	// 하나로 합치는 것
	// 
	// delete -- free 가 하는일 + 소멸자 호출
	// 
	// new delete 짝 맞추는거는 꼭 해야 함
	// 그래서 나온게

	// p. 332
	// 스마트 포인터
	// 목적 : 더이상 딜리트를 신경쓰지 않아도 된다

	// delete 안하면 문제가 생긴다
	Person* pp = nullptr;
	pp = new Person;
	pp = new Person(21);
	delete pp;

	// smart pointer, delete의 수고로부터 자유
	unique_ptr<Person> pp1(new Person(21));
	// 이름은 pp1
	// 뒤는 생성자 코드
	// pp1도 사실 객체
	// tamplete 이 Person 인 unique_ptr 이라는 클래스
	// 그래서 사실 진짜 포인터는 아님
	// 그래서 unique_ptr 의 디스트럭터에서 delete 할 수 있게 하는 것
	// 
	// wrapper --> 감쌌다 라는 표현
	// 
	// 진짜 포인터는 * 이거 뿐
	// 스마트 포인터는 wrapper 일뿐
	// 메모리 누수 걱정은 안해도 됨
	//

	pp->age = 30;
	// 포인터로 동적 할당 된거라
	// 화살표로 해야함

	// p.334 const pointer

	//// p가 가리키는 곳의 값을 읽을 수는 있으나 바꿀 수 없음
	//const int* p = 10;
	//// 주소 100을 바꿀 수 없음
	//int* const p = 10;
	//// 둘다 안됨
	//const int* const p = 10;

	// 객체에서도 그대로 이어짐
	const Person* pp = new Person(20);
	Person* const  pp = new Person(20);
	const Person* const pp = new Person(20);
	// 첫번째 두번째거는 사용하기에 따라 좋음
	// 고급개발자들의 스킬

	



	return 0;
}