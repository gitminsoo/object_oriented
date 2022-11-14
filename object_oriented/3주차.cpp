//
//  p.106 2차원 배열
//	
//

//#include <iostream>
//
//using namespace std;

//int main()
//{
//	int a[3][3] = {
//		{1,2,3},
//		{4,5,6},
//		{7,8,9}
//	};
//
//	for (auto& v : a) {
//		for (auto v2 : v)
//		{
//			cout << v2 <<' ';
//		}
//	}
//	//
//	// a에 있는거 하나씩을 뽑아 온다 
//	// v에는 1 2 3 큰 덩어리가 들어가고
//	// v2 는 그 안의 것을 하나씩 뽑아준다
//	// 
//	// range - based for loop
//	// 
//	// & 기호를 빼면 에러가 남 
//	// 그 이유는??
//	// &을 안붙이면 작은 첫 배열의 주소가 나온다 
//	// 그래서 reference 를 붙이면 v는 int* a 처럼 처리됨
//	// -- > int& a  이거 붙이므로 배열로서의 컨트롤이 가능 해짐
//	// 
//	//
//
//}

//int main()
//{
//	string names[] = { "james","john","tom" };
//
//	for (auto v : names)
//	{
//		cout << v << endl;
//	}
//	//
//	// 스트링의 배열도 원래는 2차원 배열
//	//
//
//	for (auto v : names)
//		// & 안붙이는 거라고 하는데 붙여도 나오네
//	{
//		for (auto v2 : v)
//		{
//			cout << v2 << " ";
//		}
//		cout << endl;
//	}
//}

////
//// p.123 함수원형
//// 
//// 함수는 위에 써주는게 맞지만 코드가 너무 더러워짐
//// 그래서  
////
//
//int fun1(int a);
//// function prototype
//// 혹은 function header 
//
//
//int main()
//{
//	int k = fun1(10);
//	cout << k << endl;
//}
//
//int fun1(int a) {
//	return a;
//}// prototype 없이 이거 밑으로 내리면 에러가 남 

//
// p. 130 함수호출시 인수전달 방법
// call by value 
// call by reference
// 
// value 
// 복사 후 넘겨주는 것
// 원본이 안전하다 
// 하지만 시간이 오래 걸리고 메모리를 더 쓴다
// 그래서 데이터타입이 간단한거만 쓴다 
// 
// reference 
// 원본의 주소를 넘기는 방식 
// 빠르고 원본을 건드릴 수 있음
// 대용량은 reference로 넘기는게 맞다
// array는 reference로 넘어간다
//

//int my_func(int a, int b)
//{
//	return a + b;
//}
//
//int my_func2(int* a, int* b)
//{
//	*a = 100;
//	*b = 200;
//
//	return *a + *b;
//}
//
//int main()
//{
//	int x = 10, y = 20;
//
//	int v = my_func(x,y);
//
//	cout << v << endl;
//
//	cout << "x is " << x << " y is " << y << endl;
//
//	int v2 = my_func2(&x, &y);
//	cout << v2 << endl;
//
//	cout << "x is " << x << " y is " << y << endl;
//
//}

//int x = 10;
//int y = 20;
//int w = 30;
//
//void my_swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//
//	// b + 1 = 666;
//	// 
//	// reference variable 쓰는게 낫다
//	// 이런 코드에 오류를 내준다.
//	// 
//	// 포인터로 받아서 하려고
//	// 코드를 실수로 쓴다면 
//	// 다른 애들의 값에 영향을 줄 수 있다
//	// 전역변수라 애들끼리 붙어있음 
//	// 
//	// 이런위험성떄문에 나온게
//	// reference variable
//	//
//}
//
//int main()
//{
//	cout << x << " " << y << " "<< w << endl;
//	my_swap(x, y);
//	cout << x << " " << y << " " << w << endl;
//
//	//
//	// 값이 바뀌어 나온다
//	// 
//	//
//}

//
// p. 135 중복함수
// overloaded func
// 
// argument type 과 숫자, 순서에 따라
// 다른 함수로 인식한다.
// 
// return 타입을 제외한 prototype 이 다르면 
// 다른 함수이다
// 
// 왜 필요??
// 함수를 직관적으로 만들 수 있다.
//

//int funcA()
//{
//	return 0;
//}
//
//int fundA(int a)
//{
//	return a;
//}
//
//int funcA(int a, double b)
//{
//	return 0;
//}
//
//int my_add(int a, int b)
//{
//	return 0;
//}
//
//float my_add(float a, float b)
//{
//	return 0.0;
//}
//
//// 이처럼 정수 float 합쳐서
//// 직관적으로 만들 수 있다.


//
// p.140 
// default parameter 
// 대부분의 파라미터가 동일할때 쓰며
// 가끔 바꿔줄 때 쓰는거다
// 바뀌는 값이 안들어 오면 default 가 들어가고 
// 값이 들어오면 들어온 값으로 쓴다
// 
// 섣부르게 사용하면 안됨
// 기본 인수가 앞에 있으면 안됨
// 
// 디폴트는 뒤에서부터 채워나간다 --> 중요
//
//
//int my_func(int a, float b = 3.14)
//{
//	return 0;
//}
//
//
//int main()
//{
//	my_func(10);
//	my_func(20, 5.16);
//	return 0;
//}

//
// p. 145
// inline function
// 
// 함수 호출 시 함수로 갔다가 오는게 기본
// 돌아올 주소를 생각하고 있어야 한다는 문제
// argument 를 가져간다
// 결과값을 저장해두고 return 값을 저장해놓은 주소를 가지고
// main으로 돌아가고 그 주소를 가지고 다시 그 값을 데려온다
// 오버헤드가 많다!!!
// 
// 그래서 함수는 사실 좋지 않은 방법
// 근데 그러기엔 너무 좋은걸...
// 
// 인라인을 쓰면 그 코드를 복사해서 함수 호출하는 부분에
// 갖다 붙인다 그래서 부르는 만큼의 시간을 줄인다
// 근데 코드 크기가 크긴 함 
// 시간을 조금이라도 줄이기 위해서는 쓰는데게 좋음
//
//
//inline int my_func(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	my_func(10, 20);
//	return 0;
//}

////
//// p.146 Srting
////
////
//
//int main()
//{
//	string s1 = "hello";
//	string s2 = "world!";
//
//	string s3 = s1 + s2;
//
//	//s1 += s2;
//	//if (s1 == s2)
//	//{
//
//	//}
//	//if (s1 != s2)
//	//{
//
//	//}
//	//if (s1 < s2)
//	//{
//	//	// 사전 순서 비교
//	//}
//
//	// p.151 string member function
//	// s1[0]
//	cout << boolalpha;
//	cout << s1.empty() << endl;
//	// s1 비어있는지 확인
//
//	cout << s1.insert(2, s2) << endl;
//	cout << s1.find("llo") << endl;
//
//}

//
// p.167
// 
// object oriented programming , oop
// 객체지향 프로그래밍
// 
// class 의 모체는 structure
// 그 안에 코드를 넣은 것이 class 
//

//class node {
//	int data;
//	float r;
//
//	void showdata()
//	{
//		cout << data << endl;
//	}
//};


//___________________________
// 9월 21 일
//___________________________

#include <iostream>

using namespace std;

//
// p.168 절차지향 프로그래밍
// procedural programming
// procedure == function
// 
// c : data 와 function이 분리 
// 
// p.170 
// 1960년대 SIMULA
// 
// p.172
// 객체는 무엇으로 이루어 지는가
// 2가지 
// member variable == member field
// member function == method
// 
// p.174
// 클래스는 객체의 설계도
//

// p.176

//class Circle {
//	// member variable
//public : 
//	// 퍼블릭은 외부에서 접근 가능
//	// 클래스의 내부는 class a {(여기)}
//	// private 으로 바꾸면 외부접근이 불가
//	//
//	
//
//	int radius;
//	string color;
//
//	// method
//	void showAttribute() {
//		cout << radius << " " << color << endl;
//	}
//
//}; 
// class
// 일반적으로 class 앞은 대문자로 쓴다

//class BankAccount {
//
//	// money는 class 내부에서만 건드릴 수 있다.
//	// 이와 같이 데이터를 public: private:을 이용하여
//	// 데이터를 보호하는 것을 정보은닉이라고 한다.
//
//	// 데이터를 건드리는 것은 내가 class 내부에서 선언한
//	// 메서드를 통해서만 건드릴 수 있다.
//	// 그리고 그 메서드 내에 모든 안전장치가 다 구현되어 있다.
//private:
//	int money;
//public:
//	void setMoney(int m) {
//		if (m < 0) {
//			money = 0;
//			return;
//		}
//		money = m;
//	}
//	void showMoney() {
//		cout << "You have " << money << " won." << endl;
//	}
//};
//
//int main()
//{
//	//Circle c;
//	//// instance 객체
//	//c.radius = 10;
//	//c.color = "Yellow";
//	//
//	//cout << c.radius << " " << c.color << endl;
//
//	//c.showAttribute();
//
//	BackAccount a;
//	a.money = 100;
//	a.showMoney();
//	
//}

//
// p.185 예제
//

//#include <windows.h>
//
//class Circle {
//public:
//	int x, y, radius;
//	string color;
//
//	double calcArea() {
//		return 3.14 * radius * radius;
//	}
//	void draw() {
//		HDC hdc = GetWindowDC(GetForegroundWindow());
//		// windows api
//		// application programming interface
//		// 어플리케이션을 프로그래밍 할때 사용할 함수들의 집합
//		// DC -> 도화지같은 느낌 direct context
//		// h기 handler
//		// 
//		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
//		// 타원을 그려주는 함수
//		// 뒤의 네점에 맞는 타원을 그리는 함수임
//		// 근데 함수평면도가 다름
//		// 좌표축의 x는 좌에서 우로 같지만
//		// y축은 위에서 아래인 반대임
//		// 
//	}
//};
//
//int main()
//{
//	Circle c;
//	c.x = 200;
//	c.y = 500;
//	c.radius = 100;
//	c.draw();
//}

//
// p. 185 도전문제
// x좌표를 200 부터 600까지 50씩 증가시키면서
// 원을 그리시오
//

//#include <windows.h>
//
//class Circle {
//public:
//	int x, y, radius;
//	string color;
//
//	double calcArea() {
//		return 3.14 * radius * radius;
//	}
//	void draw() {
//		HDC hdc = GetWindowDC(GetForegroundWindow());
//		// windows api
//		// application programming interface
//		// 어플리케이션을 프로그래밍 할때 사용할 함수들의 집합
//		// DC -> 도화지같은 느낌 direct context
//		// h기 handler
//		// 
//		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
//		// 타원을 그려주는 함수
//		// 뒤의 네점에 맞는 타원을 그리는 함수임
//		// 근데 함수평면도가 다름
//		// 좌표축의 x는 좌에서 우로 같지만
//		// y축은 위에서 아래인 반대임
//		// 
//	}
//};
//
//int main()
//{
//	Circle c;
//	c.x = 200;
//	c.y = 500;
//	c.radius = 100;
//
//	for (auto i = 200; i <= 600; i += 50) {
//		c.x = i;
//		c.draw();
//	}
//
//	c.draw();
//}

// p.188
// 멤버함수 중복
// method overloading
// 
// p.189 
// 클래스 인터페이스와 구현의 분리
// 함수 헤드라이너처럼 구현을 따로 적어서
// 클래스 보기 편하게 함
//

//class Circle {
//public:
//	int x, y;
//	void showme(int x, int y);
//	void showme(float x, float y);
//};
//void Circle::showme(int x, int y)
//{
//	return;
//}
//void Circle::showme(float x, float y)
//{
//	return;
//}

//
// 헤더와 내용을 무조건 구분해서 만드는게 낫다
// 지적 재산권 보호를 위해서가 첫 이유
// 함수를 팔때는 헤더파일을 주는거
// .cpp는 assembly 언어로 넘겨줘서 넘기지 않는다
// 협업을 할때도 헤더파일 정보만 있으면 만들 수 있음
//
#include "Circle.h"

int main()
{
	Circle c;
}