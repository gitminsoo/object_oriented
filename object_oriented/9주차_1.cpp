//
// 진도 나가야죠
// 일단 복습
//

// p. 384 
// 정적변수
// 정적 함수
// 
// static method (function) 의 제약사항
// 반드시 정적 변수나 정적 함수만 사용할 수 있다.
// 논리적으로 생각하면 당연
// 
// non - static 메서드는 정적 메서드를 부를 수 있을까?
// 당연히 부를 수 있다.
//

//
// c++ 에서는 전역변수등을 포기해야한다
// 전역변수를 둔다면 
// 함수에 대해 전역 변수가 없으면 돌아가지 않는 단점이 있음
// 코드의 재활용성이 많이 떨어짐
// 그래서 객체 에서는 클래스 안에서 다 만드는게 맞음
// 전역 변수 없는게 맞음
// 전역 함수도 필요가 없음
// 전역에 대한것을 없애는것이 맞음
// 객체가 없어도 부를 수 있는 정적 변수, 메서드 사용
//

//
// p. 389
// singleton designe pattern (디자인 패턴)
// 디자인 패턴이란 
// designe patterns GOF - 유명한 책
// 이거는 알아야 중급의 개발자는 될 수 있음
// Gang Of Four
// 4명의 저자를 뜻함
// 코드 재사용성을 극대화 하는 패턴을 모아놓은 책
// 꼭 읽어야 할 책
// 경력직 이직때는 반드시
// 디자인 패턴을 물어보는 문제를 낸다
// 번역본도 있으니까 꼭 읽어보기
// 
// 그 안에 있는 singleton pattern 이 있음
// 엔트리 레벨에도 물어보는 문제이다
// 
// 만드려면 정적 멤버 변수와 메서드가 꼭 필요
// 
// 상황 
// -> 어떤 문제가 있다. 근데 어떻게 짜야 재사용성을 극대화 할 수 있을까
// 싱글톤의 상황 ::: 특정 클래스에서 오직 한개의 객체만 만들어지도록 할 수 있을까
// 게임같은데 보면 보스가 오로지 하나만 존재해야 한다 같은 느낌
// 한개의 객체만 만들어지도록 
// - 2개이상의 클래스가 만들어지지 않도록
// 어떻게??
// 
//

//
// p. 399
// operator overloading 
// 연산자 오버로딩
// 잘쓰면 좋음
// 교수님 생각에 c++ 개념중 제일 어려움
// 무엇이냐~
// function overloading의 개념을 보고 보면 좀 비슷한데 달라
// 
//

#include <iostream>

using namespace std;


class MyVector {
private:
	int x, y;
public:
	MyVector(int _x, int _y) : x(_x), y(_y) {}
	void showXY() {
		cout << "X : " << x << " Y : " << y << endl;
	}
	
	MyVector operator+(MyVector& other) {
		// + 에 대한 함수를 만드는것과 같음
		// 연산자 오버로딩
		cout << "첫번째 더하기 오버로딩" << endl;
		MyVector temp(this->x + other.x, this->y + other.y);
		return temp;
	}

	MyVector* operator+(MyVector* other) {
		cout << "두번째 더하기 오버로딩" << endl;

		MyVector* temp = new MyVector(this->x + other->x, this->y + other->y);
		return temp;
	}

	bool operator==(MyVector& other)
	{
		if (this->x == other.x && this->y == other.y)
		{
			return true;
		}
		return false;
	}


	MyVector addToVectors(MyVector& v)
	{
		MyVector temp(this->x + v.x, this->y + v.y);
		return temp;
	}
};

int main() {
	MyVector* v1 = new MyVector(10, 10);
	MyVector v2(10, 10);

	// MyVector v3 = v1 + v2;
	// 에러남
	// v1이 결국 포인터라 기존의 정의된 함수가 된거다.
	// 연산자 오버로딩은 기본 타입에 대해서는 안됨
	// 객체에 대해서만 먹힌다.
	// 기호 안에 있는 애들은 객체여야만 한다
	// 기본 연산은 안먹힌다.
	//

	return 0;
}

int main5() {
	MyVector v1(10, 10);
	MyVector v2(10, 10);


	// MyVector v3 = v1 + v2;
	// 객체끼리의 합이 정의가 안되어 에러가 난다.

	/*MyVector v3 = v1.addToVectors(v2);
	v3.showXY();*/
	// 그래서 이렇게 메서드를 만드는 방법이 있다.
	// 직관적이지 않고 가독성도 떨어진다.
	// 
	// 
	// 그래서 위처럼 그냥 더하고 싶어서 나온게
	// 연산자오버로딩

	MyVector v3 = v1 + v2;
	// 이제 + 가 가능하다.
	// 객체를 더하고 빼는거 많이 씀
	v3.showXY();

	cout << boolalpha;
	cout << "same? : " << (v1 == v2) << endl;
	// 객체끼리의 연산자를 할 수 있음

	MyVector* p5 = v1 + &v2;
	// 첫번째는 본인이라 그냥 주고 다음은 받는게 주소라서 &붙임
	p5->showXY();

	return 0;
}















// 클래스로부터 오직 1개의 객체만 만들어지도록 하는
// 싱글톤 패턴이 적용된 클래스

class MyOnlyObj {
private:
	int d;
private:
	static MyOnlyObj* instance;
	// 포인터를 프라이빗으로 막아놓음
	// 밑과 맞춰서 static으로 만들어야 함
	MyOnlyObj() {
		d = 100;
	// 외부에서 부를 수 없도록 막아놓는다
	// 생성자를 프라이빗으로 넣었기 때문
	}
public:
	static MyOnlyObj* getInstance() {
		if (instance == nullptr) {
			instance = new MyOnlyObj();
			// 널이면 새로 만들어서 저장한다
			// 값을 읽을 수 있는 이유는 static이라서
			// 딱 하나만 만든다.
			// 실질적으로 하나 만든걸로 돌려서 만든다 
			//
		}
		return instance;
	}
	void showD() {
		cout << "D : " << d << endl;
	}
	void setD(int _k) {
		d = _k;
	}

};

MyOnlyObj* MyOnlyObj::instance = nullptr;

int main4() /* 4 */ {
	MyOnlyObj* p1 = MyOnlyObj::getInstance();
	MyOnlyObj* p2 = MyOnlyObj::getInstance();
	MyOnlyObj* p3 = MyOnlyObj::getInstance();
	// 모두 같은 주소를 가지고 있음
	
	p1->showD();
	p2->setD(300);
	p1->showD();
	// p2를 바꾸니 p1의 값이 바뀜을 볼 수 있다.
	// 스태틱이 아닌 d를 보며 알 수 있다.

	// 하나만 존재하는 캐릭터를 만들때 이렇게 싱글톤으로 만들어 놓으면 됨

	return 0;
}




class MyObj {
private:
	int i;
	float j;
	
public:
	static int k;
	// k공간은 클래스 안에는 없음
	// 스태틱은 계속 남아있는애 
	// 클래스로 만들어지는 모든 객체에 대해서 
	// 오로지 한개의 카피본만 생기고
	// 그것을 공유해서 사용한다 
	// 클래스 안에 한개의 저장공간이 존재한다고 생각하기
	// 개념이 자바에도 그대로 있음
	// 객체가 없어도 존재함
	// 쓰는 이유 -> 오브젝트끼리 상태공유하기 때문에 좋음
	// 객체와는 전혀 상관이 없음
	// 1. 초기화 하는 법도 다름
	// 밑에 보기
	//
	MyObj(int _i, float _j) : i(_i), j(_j){ }
	void showMyContent()
	{
		cout <<"i : " << i << " " << "j : " << j << endl;
		cout << "k : " << k << endl;
	}

	static void showStatics() {
		// static function
		// 객체 안불러도 사용가능
		cout << "I am static function\n" << endl;
		// 제약사항이 있다.
		// 안에 있는 멤버변수를 부를 수 없다.
		// 객체가 있어야만 하는 일을 할 수 없다.
		//
		//cout << i << endl;
		// 에러 나옴
		//

		cout << k << endl;
		// 스태틱변수는 부를 수 있음
	}
};

int MyObj::k = 10;
// static변수의 초기화 방법
// 클래스 밖에서 해주는게 정의
// 클래스 안의 네임스페이스에 있는것임을 나타내줌
//

int main3() {
	MyObj::showStatics();
	// 얘는 객체를 안불러도 사용이 가능하다.
	return 0;
}

int main2() {
	
	MyObj o1(10, 3.14);
	// 클래스는 타입이지
	// 사용하는 것은 객체아다
	// 코드는 공유해서 하는 경우가 많음
	// 이 개념이 static 이다
	//
	// 정적할당
	//

	o1.showMyContent();

	MyObj* o2 = new MyObj(20, 9.999);
	// 동적할당
	o2->k = 777;
	o1.showMyContent();
	// o2를 바꿔도 바뀜을 보아 공유함을 알 수 있다.

	return 0;
}