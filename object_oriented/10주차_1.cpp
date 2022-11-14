////
//// 오늘은 이어서
//// 10.9 friend function and friend class
//// p. 419 
//// p. 424 ===> "경고" 프렌드 함수는 꼭 필요할때만 사용 -> 근데 사용경우 없음
////
//
//#include <iostream>
//
//using namespace std;
//
//// private : access specifier, 접근 지정자
//// ==> OOP의 중요한 개념인 information hiding (정보은닉)
//// 정보은닉 : 객체 내부의 private은 객체 내부의 함수를 통헤서만 접근
////				==> 코드 security & safety 를 위해서 중요
//// 
//// 이걸 깨는 일을 할거야
//// 
////
//
//class A {
//private:
//	int a;
//public:
//	friend void showA(A _a);
//	friend int main1();
//	//
//	// 함수의 헤더만 추가 하고 
//	// 프렌드 선언을 했다.
//	// 친구 함수이기 때문에 private까지 접근 가능
//	// 클래스 내부에서 선언을 해야 함
//	// 사실 되게 안좋은 거임
//	// 클래스 안에 함수를 넣어주는게 나음
//	// 프렌드를 안만드는게 맞음
//	// 있다는거를 알면 됨
//	// 
//
//	friend class B;
//	// B가 A의 안을 볼 수 있음 
//	//
//
//	A(int _a) :a(_a) {}
//	void setA(int _a)
//	{
//		if (_a < 0)
//		{
//			a = 0;
//		}
//		else {
//			a = _a;
//		}
//	}
//};
//
//class B {
//public:
//	B() {
//	
//	}
//	void showA(A _a) {
//		cout << _a.a << endl;
//		// information hiding 의 규칙을 벗어남이 가능
//		// 그래서 말이 안됨
//	}
//};
//
//void showA(A _a) {
//	_a.a = -666;
//	cout << _a.a << endl;
//}
//
//int main1() {
//
//	A obj(20);
//
//	cout << obj.a << endl;
//
//	return 0;
//}
//
//// p.425
//// ===> <<,>> 연산자의 중복
//
//class Point {
//private:
//	int x, y;
//public:
//	friend ostream& operator<<(ostream& os, Point& p);
//	friend istream& operator>>(istream& in, Point& p);
//	Point(int _x,int _y):x(_x),y(_y){}
//	void showPoint()
//	{
//		cout << x << ", " << y << endl;
//	}
//};
//// 프렌드 안쓰고 만드는 것에 대해 생각해보기
//
//ostream& operator<<(ostream& os, Point& p)
//{
//	// 얘는 자기 자신이 없어서 자기 자신이 앞 나머지가 뒤
//	// 오-> 아웃풋 
//	// 스트림 -> 띄울곳 
//	//
//
//	os << p.x << ", " << p.y << endl;
//	// 프라이빗이라 안되는데
//	// 책에서는 이거를 프렌드로 지정
//	// 이거할라고 프렌드 만드는거는 이해가 안됨
//	return os;
//	// 두개를 연속으로 cout 해주는 경우를 위해
//	// ostream& 형으로 반환해준다.
//}
//
//istream& operator>>(istream& in, Point& p)
//{
//	in >> p.x >> p.y;
//	return in;
//}
//
//int main2() {
//	Point p(10,20);
//	cout << p<<p;
//
//	cin >> p;
//	cout << p << p;
//
//
//	return 0;
//}
//
//// p. 429
//// operator overloading은 기존 연산자를 재 정의 하는 것임
//// 새로운 연산자를 만들 수는 없음!!  !!! ?!! ?* -> 이런거는 안된다
//// 기존의 것만 사용 가능
////
//
////==================================================================================


// p. 439
// 상속,, inheritance
// 
// 정보은닉!!!
// 상속 ==> 생산성을 위한 필수 개념
//

// public 은 무조건 상속됨 
// private은 넘겨주지 않음
// 주의 !!! 상속이 안됨
// 프라이빗은 아무에게도 상속되지 않음
//

// 자식에게는 상속을 해주고 
// 밖에서 접근은 안되는 애가
// protected
// 이다.
// --> 상속에는 public , 외부에서는 privarte
//

// p.445 접근지정자 , public, private, protected  의 상속 정보에 대해 아는것

// p.449 생성자와 소멸자
//

#include <iostream>
using namespace std;

class A {
public:
	int a, b;
	A() {
		cout << "부모 생성자" << endl;
		a = 10;
		b = 20;
	}

	A(int _a,int _b):a(_a),b(_b){
		cout << "부모 생성자 2" << endl;
	}

	void showAB() {
		
		cout << a << ", " << b << endl;
	}
	~A() {
		cout << "부모 소멸자" << endl;
	}
};

class AA :public A {
protected:
	// AA는 아무런 데이터가 없더라도 A로 부터 상속받은 a,b가 있다.
	// 뒤는 상속받을 클래스 이름
	// 뒤의 퍼블릭은 상속받아 어떻게 쓸거냐
	// 나는 저거를 받아와서 퍼블릭으로 만들 수 있다.
	// 
	int c;
public:

	/*AA() {
		cout << "자식 생성자" << endl;
		c = 10;
	}*/
	AA() : A(21, 31) {
		cout << "자식 생성자 2" << endl;
	}
	void showABsum() {
		cout << (this->a + this->b) << endl;
	}
	~AA() {
		cout << "자식 소멸자" << endl;
		c = 10;
	}
};

class AAA : public AA {

};

int main() {
	AA aa;
	aa.showAB();
	aa.showABsum();
	// 부모 생성자가 만들어지고 자식이 만들어지는게 맞음
	// 소멸자는 반대로 자식부터 소멸
	// 메모리가 부모부터 잡히는것이므로 이렇게 생각
}

int main3()
{
	AA aa;
	cout << aa.a << ", " << aa.b << endl;
	aa.showAB();

	aa.showABsum();

	AAA aaa;
	aaa.showAB();
	aaa.showABsum();
	//aaa.c = 10;
	// AA::c 를 프로텍티드로 해놔서 오류가 남
	aaa.a = 10;
	aaa.b = 10;


	return 0;
}