//
// 오늘 수업까지 시험범위
// 다음주 월요일 시험
// p. 383까지 시험범위
//

// 
// 
// 

#include <iostream>

using namespace std;

// p.359
// call by value
// call by reference
// object -> value 로 넘어간다는 함정이 있음
// 
// p.360 예제
//

class Pizza{
private:
	int radius;
public:
	Pizza(int r=0):radius(r){
		cout << "pizza constructor was invoked" << endl;
	}
	Pizza(const Pizza& p) {
		// default 형태는 밑의 출력 메시지를 뺀 함수
		// 복사 생성자
		cout << "이게 바로 복사 생성자 입니다." << endl;
	}
	void setRadius(int r)
	{
		this->radius = r;
	}
	void showRadius() {
		cout << "pizza radius : " << this->radius << endl;
	}
	~Pizza() {
		cout << "destructor called" << endl;
	}
};

void doubleSize(Pizza p)
{
	p.setRadius(20);
}
void doubleSize(Pizza* p)
{
	p->setRadius(20);
}
void doubleSize_re(Pizza& p)
{
	// 얘는 위에 객체랑 다르지만 오버로딩이 안됨
	// 일반 객체처럼 사용함
	// 주소연산 당연히 불가능
	p.setRadius(30);
}

// p.363
// 함수가 객체 반환하기 
// 함수의 실행 도중 객체를 만들고
// 반환값으로 그 객체를 반환할 때
//

Pizza createPizza(int r)
{
	Pizza p(r);
	return p;
	// 리턴을 하며 복사가 일어남
	// p가 사라지는 p인데 어떻게 넘어가죠??

	// 함수가 객체를 넘길때는 복사본을 만들어서 넘겨준다
	// p의 복사본을 만들어서 넘겨주는데
	// 복사본은 생성자를 안부르고 만들어지는 것인가?
	// 왜 안불러? 다만 복사 생성자를 부를 뿐이다
	// 위에서 만든것은 정통 생성자
	// 복사 할떄는 위에 있는 것처럼 다른 생성자가 만들어짐
	// 
	//  p.372 복사 생성자 (copy constructor)
	//
}

class Myarray {
public:
	int size;
	int* data;

	Myarray(int _size) {
		this->size = _size;
		data = new int[this->size];
		// 받은 거를 삭제할 수가 없음
		// 소멸자에서 삭제 필요
	}
	Myarray(Myarray& p)
	{
		this->size = p.size;
		this->data = new int[this->size];

		//this->data = p.data;
		// 디폴트가 하는 일
		// shallow copy

		for (int i = 0; i < p.size; i++)
		{
			this->data[i] = p.data[i];
		}
		// 이렇게 직접 만들어줘야 함
		// deep copy
	}
	~Myarray() {
		delete[] data;
		// 내 쓰레기는 알아서 처리
	}


};

// p. 381
// 클래스 안에 객체 포함하기
//

class A {
	int a;
};
class B {
	float d;
};
class D {
	B* b;
	A k;
	// 다른 클래스 안의 변수형으로 쓸 수 있다
};

// p.384 정적 변수 
// class 안의 count 는 
// 객체 외부의 하나늬의 공간에 존재
//

class Lemon {
public:
	int x, y;
	static int count;
};

int Lemon::count = 30;
// 초기화 방법은 이렇게 해줘야 함
// 초기화 안하면 안돌아 가는 듯?

int main() {
	Lemon l1;
	l1.x = 20;

	Lemon l2;
	l2.x = 40;

	l1.count = 40;
	l2.count = 50;

	cout << Lemon::count << endl;

	cout << l1.x << " " << l2.x << endl;
	cout << l1.count << " " << l2.count << endl;
}

int main5() {

	//
	// p.378 
	// 복사 생성자와 대입 연산자
	//

	Pizza p1(10);
	Pizza p2(20);
	p2 = p1;
	// 생성자 끼리 만들어진 애들은
	// 같은 필드끼리 복사해서 이용
	// 복사 생성자 호출 안함

	Pizza p3 = p1;
	// 생성자와 아직 안만들어진 애는
	// p1의 복사 생성자를 불러서 
	// p3 와 복사
	Pizza p4(p1);
	// 위와 같음
	
	// 즉 , 자기 집이 있는 객체와 아닌 객체의
	// 차이가 크다.

	return 0;
}

int main4() {
	//==========================================
	// 왜 복사 생성자(copy constructor)를 알아야 하는가
	// 
	// -----> 컴퓨터 전공하는 사람들의 강점
	// 
	// 복사 생성자는 평소에는 무시해도 됨 
	// 
	// 그러나 객체 안에서 "동적 메모리 할당"을 할때는 주의를 기울여
	// 필요한 메모리를 다시 할당 받아야 한다.
	// 
	// shallow copy
	// // default가 해주는 카피
	// deep copy
	// // 우리가 지금 복사 생성자를 바꾸어
	// // 실제로 한 복사법
	// 
	// shallow 카피가 나쁜거는 아니다
	// 딥카피를 많이 하면 메모리 사용이 많아지므로
	// 좋고 나쁨의 문제가 아니라
	// 어느 상황에 사용해야 하는가에 대한 문제
	// 
	// =========================================
	//

	Myarray a(10);
	a.data[5] = 123456;
	cout << "value : " << a.data[5] << endl;
	// 문제 없이 실행이 됨

	{
		Myarray b = a;
	}
	// 중간을 괄호로 묶어 놓음

	cout << "value : " << a.data[5] << endl;
	// 안됨 에러남
	// 위의 괄호때문에 문제가 됨
	// 복사 생성자의 개념을 모르면 머리 아픔
	// b라는 라는 객체를 만드는데 a를 본떠서
	// 위의 코드를 실행하면 
	// b에 있는 모든것들이 복사 되는데
	// 주소가 그대로 넘어가게 되어서
	// a의 원본을 가르키게 된다
	// 10개의 할당 받은 공간은 하나 밖에 없음
	// 근데 블락안에서만 존재하는 b가 블락이 끝나며
	// 소멸자를 부르기 때문에 a의 원본 10개의 자리를 
	// delete 해버린다
	// a는 벙찐 상황
	// a는 값이 사라진 상황
	// 그래서 할당 되지 않은 공간을 사용한다고 에러가 나옴
	// 
	// 그래서  b는 복사 생성자는 알아서 10개의 값을 알아서 
	// 직접 복사하는 과정이 필요
	// 디폴트 생성자는 하나 만들어지면 
	// 디폴트가 사라지므로
	// 사이즈에 대한 부분 등을 모두 알아서 처리 해줘야 함
	// 
	// c++은
	// all or nothing
	// 중요
	// 

	return 0;
}






int main3() {
	//
	// 쓰이는 경우 
	// 3. 다른 객체를 복사해서 내 객체를 만들떄
	// 
	Pizza p1(20);
	Pizza p2(p1);
	// 처음보는 문법이지만
	// 위의 복사 생성자를 본다면 당연한거
	// 똑같이 생긴 애를 만들고 싶으면 이렇게 하면 됨
	//
	return 0;
}

int main2() {
	//Pizza p1 = createPizza(10);
	// 피자를 만들어서 저장한다.
	// 생성자가 호출되는 것은 위의 함수에서 일어나는 일
	//

	// 1. 함수의 반환겂으로 넘어옴
	/*Pizza p1;
	p1 = createPizza(10);*/
	// 순서대로 하면 
	// p1으로 하면 하나 만들어지고
	// 뒤의 함수에서 복사본을 만들고 
	// 함수에서 만들어진 애를 복사 함
	//

	// 2. 함수의 인자로 넘김
	/*Pizza p1(20);
	doubleSize(p1);*/
	// p1의 복사본을 넘기기 때문에
	// 복사 생성자 호출됨

	//
	// 복사 생성자가 쓰이는 경우
	// 
	// 함수의 인자로 넘겨줄 떄
	// 함수의 리턴값으로 넘어올때
	//

	return 0;
}


int main1() {

	Pizza p(10);
	p.showRadius();

	doubleSize(p);
	p.showRadius();
	// 이렇게 해도 10이 출력
	// 콜바이 밸류이기 때문에
	// 객체는 콜바이 밸류임을 잊지 말기

	doubleSize(&p);
	p.showRadius();
	// 콜바이 레퍼런스 하는법 
	// 문제점 : c언어에서의 방식이라 주소를 직접 건들기 때문에 위험
	// p를 잘못 조작하면 주변부의 값을 읽을 수 있어 위험

	doubleSize_re(p);
	p.showRadius();
	// 레퍼런스는 넘길때도 포인터 아닌거처럼 넘긴다.
	// 위험성이 없다
	// c++ 에서 주로 사용
	
	//
	// 생성자는 두번 destructor 는 세번이 호출됨
	// 복사본의 소멸자인데
	// 그거의 생성자는?
	// 
	//


	return 0;
}