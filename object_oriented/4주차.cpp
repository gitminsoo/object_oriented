// 0926

//
// 헤더차일 못찾으면 파일 위치를 연결해줘야 함 
// 솔루션 안에 프로젝트가 있다
// 각각의 프로젝트는 따로일 수도 아닐 수도 있다.
// 예를 들어 헤더 못찾으면 프로젝트 우클릭 설정에서
// 영어 버전으로 까는게 낫다.
// vs installer 에서 수정으로 가서 언어팩
// 영어 선택 가능 영어 깔고 
// 설정에서 바꿀 수 있음 
// tools option international setting -> 영어로 
// 한글이름은 억지로 번역해서 이상한게 많음 
// 구글링도 영어로 나옴
// 프로젝트 우클릭 c/c++ 일반 - 맨위 - 경로 추가
//

//
// p.196 - 객체지향 프로그램의 개념들
// 
// 1. Encapsulation (캡슐화)
// -> 캡슐은 클래스를 뜻한다. -> 캡슐안에 데이터와 메소드가 같이 있다.
// 코드 재사용성이 올라간다
// 
// 2. information hiding (정보은닉) : p.198
// public 은 클래스 밖에서도 모든 정보 접근 가능
// private 로 바꾸면 밖에서 있는지 조차 모르는 안전한 상태가 됨 
// 접근제어자를 이용하여 멤버변수를 보호하는 것
// 보안을 위해 한다.
// 
// 3. inheritance(상속) : p.199
// 부모 클래스와 자식 클래스 사이의 멤버 상속
// 오류가 적은 코드 재사용성이 강점
// 
// 4. Polymorphism (다형성) : p.200
// 이견이 있음 -> 객체의 특성이냐 아니냐 에 대한 견해차이
// 교수님은 아니라고 생각 함
// overloaded function 이 큰 예시
// overloaded func, method 등등 
// 
//

//
// p.205 UML
//       Unified Modeling Language
// 100프로 그래픽 
// c언어에 순서도가 있으면 c++엔 UML 이 있다
// 생긴건 구글에 쳐보기^^
// class간의 관계 , 구조 등등을 그림으로 표현 
// --> UML 풀이 쓰는 문제 하나는 낼거^^
// 


//#include <iostream>
//
//using namespace std;

//int my_add(int a,int b) {
//	return a + b;
//}
//float my_add(float a, float b) {
//	return a + b;
//}
//
//class Circle {
//public:
//	// 접근제어자
//	// 3종류 중 protected 는 
//	// 외부에서는 접근이 안되지만 자식에게는 상속을 해줘야 할때
//	// 밖에서 볼때는 private 자식이 볼때는 public
//	//
//	int x;
//	int y;
//	int r;
//
//public:
//	void increase_radius(int d)
//	{
//		r = r + d;
//	}
//};
//
//class ColoredCircle : public Circle{
//	// 원래는 위의것 복붙해야하지만 
//	// 코드가 너무 길어짐 --> 상속을 하자
//	// 위처럼 표현하면 대부분 물려받음 중요한건
//	// 
//	// 위의것은 다 가지고 있고 아래거 추가
//	//
//private: 
//	string color;
//};
//
//int main(){
//
//	Circle c;
//	c.x = 10;
//	c.y = 10;
//	c.r = 30;
//	c.increase_radius(20);
//
//}

// p. 219 
// 생성자 (constructor)
// 객체 멤버의 초기값을 넣어주는 함수
// 다형성도 지원
// 
// 0. 객체가 생성될 때 최초 딱 한번만 호출된다.
// -> 다시 호출은 객체를 새로 만드는 방법밖에 없다
// 1. 이것은 함수이다
// 
// 2. 모든 class 는 constructor를 갖는다,
// -> 안만들어 놓아도 default constructor 인
// Circle(){
// }
// 형태의 constructor를 자동으로 만들어 둔다
// 
// 그럼 하나만 만들면 default를 포함해서 2개인가??
// constructor를 하나라도 만들면 컴파일러가 default constructor를 안만든다.
// 즉 1개
// 
// default 만드는 법은 Circle cd;
// Circle cd(); -> 이렇게 치면 함수를 정의하게 되는거지
// 디폴트를 부르는게 아님 
// 기억하기
// 
// 
// 3. polymorphism 을 지원한다
// 4. default argument를 지원한다
// -> 함수에 기본 default 값을 지정
//


//class Circle {
//public:
//	// 접근제어자
//	// 3종류 중 protected 는 
//	// 외부에서는 접근이 안되지만 자식에게는 상속을 해줘야 할때
//	// 밖에서 볼때는 private 자식이 볼때는 public
//	//
//	int x;
//	int y;
//	int r;
//
//	// constructor
//	// 함수의 이름도 정해져있다.
//	// 반환값이 없는게 가장 큰 특징
//	// 호출 안해도 불려짐
//	// polymorphism 도 지원
//	Circle(int _x, int _y, int _r) {
//		x = _x;
//		y = _y;
//		r = _r;
//	}
//
//	Circle(int  _r) {
//		r = _r;
//	}
//
//	Circle() {
//		x = y = r = 0;
//	}
//
//	void showinfo() {
//		cout << x << " " << y << " " << r << endl;
//	}
//};
//
//
//
//int main(){
//
//	// constructor 를 통한 초기화
//	Circle c(10, 10, 5);
//	c.showinfo();
//
//}


//
// p.226  소멸자 : destructor <---> constructor
// 객체가 사라질 떄 자동으로 불리는 함수
// 따로 안불러줘도 됨
// 모든 클래스에 존재 
// 안만들면 default 가 생김
// 하는 이유
// 예를 들어 constructor에 malloc 을 써놓으면 
// 잃어버린 메모리가 생김
// 이런거 free 할때 쓰기위해 만들어둠 
// 객체가 생성, 사용 중 메모리 할당등을 풀어주기 위해 
// 존재
// 객체 생성 소멸에 대한 디버깅도 가능
//

// p.232 접근제어 access control 
// 
// private, public, protected
// 보통 클래스 member variable 은 private로 해두는게 정석임
// 클래스가 하나만 사용하는게 아니라서 다른 애들이 고친거에
// 다른 코드가 상태 변화를 일으킬 수 있다.
// 읽고 쓰는 method 제공이 필수적
// 읽는 메소드 -> getter
// 쓰는 메소드 -> setter
// 고급언어는 알아서 만들어 주는 언어도 있음
// c++은 만들어야 함
// 
//

// p.240
// 객체와 함수
// class 는 call by value로 넘어간다...
// -> 메모리가 너무 많아지지 않나요?
// 그래서 refernce 참조자로 넘긴다.
// 
// 왜 value 로 넘겼을까
// 복사본 넘기는게 쉬운일이 아니다
// 객체 안에 객체가 들어있는 경우가 있는데
// 그거 복사하기가 어려워사,,
// 


//class Circle2 {
//private:
//	// 접근제어자
//	// 3종류 중 protected 는 
//	// 외부에서는 접근이 안되지만 자식에게는 상속을 해줘야 할때
//	// 밖에서 볼때는 private 자식이 볼때는 public
//	//
//	int x;
//	int y;
//	int r;
//	
//public:
//
//	void setX(int _x)
//	{
//		x = _x;
//	}
//	int getX()
//	{
//		return x;
//	}
//
//	// constructor
//	// 함수의 이름도 정해져있다.
//	// 반환값이 없는게 가장 큰 특징
//	// 호출 안해도 불려짐
//	// polymorphism 도 지원
//	Circle2(int _x, int _y, int _r) : x(_x), y(_y), r(_r) {
//	} // 이렇게 만드는 문법도 있음 세줄로 쓰는것과 같은 의미
//
//	~Circle2() {
//		// destructor
//		cout << "destructor is called " << endl;
//		// 리턴하면서 알아서 불려짐
//	}
//
//	void showinfo() {
//		cout << x << " " << y << " " << r << endl;
//	}
//};
//
//
//class Circle {
//public:
//	// 접근제어자
//	// 3종류 중 protected 는 
//	// 외부에서는 접근이 안되지만 자식에게는 상속을 해줘야 할때
//	// 밖에서 볼때는 private 자식이 볼때는 public
//	//
//	int x;
//	int y;
//	int r;
//
//	// constructor
//	// 함수의 이름도 정해져있다.
//	// 반환값이 없는게 가장 큰 특징
//	// 호출 안해도 불려짐
//	// polymorphism 도 지원
//	Circle(int _x, int _y, int _r) : x(_x),y(_y),r(_r) {
//	} // 이렇게 만드는 문법도 있음 세줄로 쓰는것과 같은 의미
//
//	~Circle() {
//		// destructor
//		cout << "destructor is called " << endl;
//		// 리턴하면서 알아서 불려짐
//	}
//
//	void showinfo() {
//		cout << x << " " << y << " " << r << endl;
//	}
//};
//
//bool compare_circle(Circle2& c, Circle2& d)
//{
//	if (c.getX() == d.getX()) {
//		return true;
//	}
//	return false;
//}
//
//
//
//
//int main(){
//
//	Circle c(10, 10, 30);
//	c.showinfo();
//	return 0;
//}


// 0928 

#include <iostream>

using namespace std;

// p. 253
// 객체배열
// 
// class 로 부터 만들어지는 instance
// 
// 크기변화가 불가능 하다는 단점이 존재
// 인덱싱이 바로 가능 하다는 장점
// 메모리 효율성이 조금 떨어 진다.
// 
// 그래서 나온게 링크드 리스트
// 
// 짜야돼...??
// 이미 다 있어~
// 
// c++ 은 링크드 리스트를 많이 씀
//


#include <vector> // linked list  


class Circle {
public:
	int x, y;
	int radius;

	Circle() : x(0), y(0), radius(0) {
		cout << "Circle constructor was involved\n" << endl;
	}

	Circle(int _x, int _y, int _radius) : x(_x), y(_y), radius(_radius) {
		cout << "Circle constructor was involved\n" << endl;
	}
	void showCircleInfo()
	{
		cout << x << " " << y << " " << radius << endl;
	}
};

//int main()
//{
//	// p.261
//
//	// template 
//	// c++, 자바등도 지원
//	// 형식 다 되어있고 내용만 비어있다.
//
//	// vector 같은걸 
//	// standard template library (STL) --> vector
//	// 큐 스택 등등 다 제공
//	//
//
//	//
//	// chap 15. STL 과 람다식
//	//
//
//	//
//	// vector 도 클래스 
//	// 지원하는게 많아~
//	//
//
//	vector<int> first(5);
//	// 벡터의 생성 법
//	// first는 이름 10개 짜리를 만듦
//	// int 형의 변수가 들어가는 10개 짜리 리스트
//	//
//
//	// 배열처럼 사용 가능
//
//	/*for (auto v : first)
//	{
//		cout << v << endl;
//	}*/
//
//	//cout << first[5] << endl;
//	// array indexing ok
//	//cout << first.at(5) << endl;
//	// 위의 두개는 같은 내용
//	// at이 메소드니까 vector는 클래스다
//
//
//	first.push_back(100);
//	first.push_back(200);
//
//	// 값이 추가되며 뒤에 붙음
//
//	//cout << first.front() << " " << first.back() << endl;
//	// 맨 앞 맨 뒤거 알 수 있음
//	// 이런거 그냥 cplusplus reference 사이트에서 찾을 수 있음
//
//	// begin , end
//	// begin은 head의 주소
//	// end 는 벡터가 끝났는지를 확인하는 특수 문법
//	// 마지막이 아닌 그 다음이 가르키는 곳의 주소 즉 NULL 을 알려줌
//	// end()-1 해야 마지막 인수
//	//
//
//	cout << "___________" << endl;
//	
//	for (auto p = first.begin(); p != first.end(); p++)
//	{
//		cout << *p << endl;
//		//printf("%p : %d\n", p, *p);
//	}
//
//	auto p = first.begin();
//	cout << *(p+5) << endl;
//	// 실제로 5개 연속 붙어 있는것은 아니니 조심
//
//
//	first.pop_back();
//	// 뒤에서부터 없애는 거
//	// 200 날림
//	// 반환값 리턴은 안해줌
//
//	vector<int> b;
//	b = first;
//
//	if (first == b)
//	{
//		cout << "thet same" << endl;
//	}
//	// 비교 , 대입 다 간단히 가능
//
//	// insert
//
//	first.insert(first.begin(), 999);
//	cout << first.at(0) << endl;
//	// 위치를 주소로 지정 그래서 비긴으로 만들어 주는 거
//	// first.begin() + 1;
//	// 이런식으로
//
//
//	// assign
//	// 인수 두개를 받아 앞의 것에다가 뒤에거 넣는다?
//	// 이미 만들어진 배열을 넣는 느낌
//	// 찾아서 해보기
//
//
//	// clear
//	first.clear();
//	cout << first.size() << endl;
//
//
//	for (auto v : first)
//	{
//		//cout << v << endl;
//	}
//
//
//
//	vector<Circle> second(10);
//	// 와 미쳤다 무대를 뒤집어 놓으셨다
//
//
//
//	return 0;
//}

#include <algorithm>
// 소팅 등이 포함

#include <array>

bool compare(int a, int b)
{
	return a < b;
}

//bool compare(Circle a, Circle b)
//{
//	if ((a.x + a.y) < (b.x + b.y))
//	{
//		return true;
//	}
//	return false;
//}

int main()
{
	// p.270  algorithm
	

	vector<int> first{ 5,4,3,2,1 };
	
	//for (auto v : first)
	//{
	//	cout << v << endl;
	//}

	//
	//sort(first.begin(), first.end(),compare);
	//// 마지막 인수로 asc desc 선택
	//// c++ 은 퀵소트

	//for (auto v : first)
	//{
	//	cout << v << endl;
	//}

	// 2차원 벡터
	//vector<vector<int>>a;
	//// 벡터 안에 벡터

	//for (auto i = 0; i < 3; i++)
	//{
	//	vector<int> row;
	//	for (int j = 0; j < 5; j++)
	//	{
	//		row.push_back(i * j);
	//	}
	//	a.push_back(row);
	//	// 이거 js에서 table 만들던거랑 비슷한거 같은데
	//	// 많이 씁니다.

	//	// 벡터 안의 벡터가 크기가 달라도 된다는 장점 
	//}

	// array
	// #include <array> 이거 사용
	// 진짜 어레이랑 똑같음
	// 쓰는 이유는 클래스라 메소드들이 많아서 사용
	//

	array<int, 3> my_array;
	// 사이즈 3 지정
	my_array[0] = 10;
	for (auto v : my_array)
	{
		cout << v << endl;
	}
	//
	// size 
	// 어레이 크기 반환
	// fill
	// 같은 숫자로 채운다
	// empty
	// 비어있는지 확인
	// at
	// 
	// front
	// 앞주소
	// back
	// 뒷주소
	// 
	// 교수님은 개인적으로 안쓰시긴 함
	//

	// p.286
	// SFML : simple and fast multimedia library
	// 남이짜는거 가져와서 만드는게 목표
	// 라이브러리 깔아야 됨
	//
	

}