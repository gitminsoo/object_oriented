//
// polymorphism, 다형성 : 어떤 method 를 부를지 그때 그때 달라용
//
// OOP 1. : information hiding (정보은닉) :
//		-- access specifier : private, public, protected
// OOP 2. : inheritance
//		-- reuserability (코드 재사용성)
//		-- parent's protected : child's public, outer's private
// 
// method(function) oveloading 
// method overriding : 부모메서드와 똑같이 생겼을 때 ,,,
// 
// binding : static, dynamic
// 어떤 함수를 부를지 고르는걸 바인딩 한다고 한다.
// static binding : 
//
// upcasting : 자식 객체들을 부모 클래스 포인터로 가리킬 때 
// (합법)
// 
// downcasting : 부모 객체를 자식 클래스 포인터로 가리킬 때
// (합법 - 근데 굉장히 위험함)
//
//
// Dynamic binding : virtual (method 앞에 붙는다)
// 

#if  0

#include <iostream>

using namespace std;

class A {
public:
	virtual void showMe(){
		cout << "A's showMe()" << endl;
	}
};

class B : public A {
public:
	void showMe(){
		cout << "B's showMe()" << endl;
	}
};

int main1() {

	B* pb = new B();
	A* pa = nullptr;
	pa = pb;
	// upcasting
	pa->showMe();
	// 부모의 showme
	// 메서드 앞에 virtual 붙이면 
	// 자신의 오버라이딩 된 함수를 찾아가서 그거 부름
	// virtual 이 붙어야만 dynamic binding
	pb->showMe();
	// 자식의 showme
	// 메서드 오버라이딩으로 자식거만 취급




	return 0;
}

#endif //  0

//=========================================================================


#include <iostream>

using namespace std;

// 12.5 순수 가상 함수
//			pure virtual method (func)
// 순수 가상 함수를 가진 클래스의 객체를 만들 수 있을까?
// 정의가 되지 않은 함수에 대해 콜을 할때 문제가 생기기 때문에
// 만들 수 없다.
//

// pure virtual method 를 가진 클래스를 특별히 
// abstract class (추상클래스)라고 한다.
// abstract class로 부터는 객체를 만들지 못한다.
// 
// 어따써??
// 
// 
//

//class A {
//public:
//	virtual void showMe() = 0;
//	// 순수 가상 함수!!
//};
//
//class B : public A {
//public:
//	void showMe() {
//		cout << "B's showMe()" << endl;
//	}
//};
//
//class C : public A {
//public: 
//	void showMe() {
//		cout << "C's showMe" << endl;
//	}
//};

//
// 자바의 인터페이스 개념
// C++ 은 abstract class (virtual function) 을 이용해서 interface 구현
// 
// interface : 클래스가 반드시 구현해야 할 메소드들의 목록

#if 0

class Shape {
public:
	virtual double getArea() = 0;
};

class Triangle :public Shape{
private:
	int width, height;
public:
	Triangle(int _w,int _h):width(_w),height(_h) {}
	double getArea() {
		return (double)(0.5 * width * height);
	}
};

class Circle :public Shape {
private:
	double r;
public:
	Circle(double _r) : r(_r) {}
	double getArea() {
		return (double)(3.14 * r*r);
	}
};

class Rect :public Shape {
private:
	int width, height;
public:
	Rect(int _w,int _h) : width(_w),height(_h) {}
	double getArea() {
		return (double)(width * height);
	}
};

int main2() {

	Triangle t(10,10);


	Circle c(10.0);
	// Circle 에 만들어져 있는
	// 메서드 중 가상클래스 안에 있는
	// 메서드의 이름과 같은 애가 없으면 에러가 난다.

	Rect r(10, 10);

	Shape* s[3];
	// 객체는 못 만들지만 포인터형 접근은 가능

	s[0] = &t;
	s[1] = &c;
	s[2] = &r;

	for (int i = 0; i < 3; i++)
	{
		s[i]->getArea();
		cout << s[i]->getArea() << endl;
		// 이렇게 연결된 모든 클래스에 대해 만들 수 있음 
	}


	return 0;
}

#endif // 0

//
// p. 519
// 
// 파일 입출력
// 
// stream : 외부에 있는 데이터를 읽고 쓰는 통로
// 
// input stream
// output stream  <-- 자바에도 있는 경우
// 
// 파일의 2가지 종류 : text, binary
// text : ASCII code 값으로 저장 --> 0 : 48(10진수), 0x30
// binary : 값 그대로 --> 0 : 0
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	//ofstream os("test.txt");
	//// close 안해줘도 됨 
	//// 객체의 소멸자에 이미 존재

	//for (int i = 0; i < 100; i++)
	//{
	//	os << i << " ";
	//	// cout 도 console out 이라는 뜻의 객체
	//}
	// 프로젝트 파일에 만들어져 있음

	ifstream is("test.txt");

	int number;
	/*while (is >> number)
	{
		cout << number << " ";
	}*/

	char c;
	while (!is.eof())
	{
		is.get(c);
		cout << c;
		// 캐릭터 형으로 받아서 공백문자도 알아서 받음 

	}

	return 0;
}