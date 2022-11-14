// p.458 
// 11.6 멤버 함수의 재정의

#include <iostream>

using namespace std;

/*
	function overloading
	- 함수 이름이 같아도, parameter 갯수, type, 순서가 다르면 다른 함수로 인식

	method overloading
	- 클래스 정의에 적용된 functuon overloading 

	overloading : 한개의 이름에 여러개의 함수를 부착해서, 힘들게(overloading) 한다는 의미

	method overriding
	- 클래스에만 적용 : OOP
	- 상속 관계에서만 발생
	- 자식 클래스에서 정의한 method가 동일한 signature(함수 이름, 파라미터)를 가진 
		부모클래스의 method를 가려버리는 현상

*/
#ifdef DEBUG

class Parent {
public:
	void whoareyou() {
		cout << "Parent" << endl;
	}
};

// parent 로부터 상속 받아서 child 클래스 생성

// p.462
// pubkic:  public -> public   protected -> protected   private -> 원래 못받음
// protected : public -> protected   protected -> protected 
// private : public, protected -> private
// 

class Child : public Parent {
public:
	void whoareyou() {
		Parent::whoareyou();
		// 부모 클래스의 함수를 부르는 경우
		cout << "Child" << endl;
	}
	// 상속을 받았는데
	// 똑같은 이름의 함수가 정의 되어 있다면
	// 당연히 해당에 있는 child 가 찍힘을 알 수 있다
	// 
	// 이론적으로 분석을 해보면
	// 클래스 안에 부모가 차지하는 영역이 있고
	// 자식 영역이 있는데
	// 함수 이름이 같으면 자식의 클래스 안에 있는 메소드가
	// 부모의 메소드를 가린다 
	// 올라 탄다 (overriding) 
	// 
	//
};

int main1() {

	Child c;
	c.whoareyou();
	c.Parent::whoareyou();

	Parent p;
	p.whoareyou();

	return 0;
}


// p.466
// 다중 상속
// 
// multiple inheritance
// 소프트웨어 학적으로는 안쓰는게 맞음
// 자바는 이거는 사용안함 -> 비슷한 인터페이스가 존재
// 
// c++은 사용할 수 밖에 없는 경우가 존제
//

class A {
public:
	int x;
};

class B {
public:
	int x;
};

class C : public A, public B {

};

int main2() {
	C cc;
	cc.A::x = 10;
	cc.B::x = 20;
	// 이렇게 각자 지정해줘야 함
	// 소프트웨어 공학에서는 아주 안좋은 예시

	return 0;
}

#endif // DEBUG

/*
	p.481, 다형성, polymorphism
	==> 객체 지향에서 최고급 개념
	디형성 : 변신하는 사람
	==> 어떤 멤버 함수를 부를지 상황에 따라 달라진다!!

	정적 polymorphism -> method overriding
	-> 왜 그러냐면 위의 예시를 보면
		whoareyou()가 어느 클래스의 함수가 불리는지 이미 알 수 있음
		코드 분석을 통해 알 수 있음

	동적 polymorphism : dynamic binding <-- 극강 난이도 (교수님이 좋아하심)


*/
#if 0

class Parent {
public:
	int x;
	virtual void showme() {
		// 이 함수를 막으면 
		// 다이나믹 캐스트에 오류남
	}
};

class Child : public Parent {
public:
	int y;
};

int main() {
	// upcasting : 부모클래스 타입의 포인터로
	// 자식 클래스의 객체를 가리키는 일
	// 
  	// 합법임 굉장히 많이 씀
	// 
	// 부모 클래스면 부모 클래스의 멤버만 사용해야 한다.
	// 부모 포인터로 자식 멤버를 건들 수 없음 <--  컴파일 에러
	//
	/*Parent* p = new Child();
	p->x = 10;*/
	//p->y = 10;
	// parent 의 공간에 y 가 없어서 에러가 남


	//Child* c = new Parent();
	// 안되게 막아 놓은 이유
	// 타입이 다르기 때문에
	// 더 많이 가진 정보로 부모에 접근하면
	// 빵꾸나는 경우가 있어서 
	// 에러가 남 
	// 문법적으로 오류를 잡아줌 
	//

	// down casting

	Parent* p = new Parent();
	// Child* c = (Child*)p;
	// 원래는 안되지만
	// 타입 캐스팅을 통해 컴파일에 문제가 없도록 함
	// 하지만 y에 대한 공간은 없고
	// 접근은 가능한 상태가 됨
	//
	/*c->x = 50;
	c->y = 999;*/
	// 컴파일러도 못잡아내고
	// 문제가 없다고 생각할 수 있지만
	// 남의 영역에 갖다가 넣는거기 때문에 위험함
	// down casting의 문제점 
	//


	// p.487
	Child* c = dynamic_cast<Child*>(p);
	/*Child* c = (Child*)p;*/
	// 다운 캐스팅 -> 문제 있음
	// 코당에서 거의 안씀 업캐스팅만 자주 씀


	c->x = 50;
	c->y = 999;

	return 0;

}

#endif

/*
	
	polymorphism 
	dynamic binding


*/

class Animal {
public:
	virtual void speak() {
		cout << "Animal" << endl;
	}
};

//	virtual : 나를 밟고 가시오
//				혹시, 상속받은 자식중에 overriding된 것이 있으면 
//				그것을 부르시오 나는 virtual 이다
// 
// dynamic binding : 어느 speak()이 불릴지는 runtime에 가봐야 안다.
// ==> late binding
// 
// 버츄얼과 오버라이딩이 생기면 난이도가 올라감
// 
// 우선순위를 양보? 이런 개념으로 이해해야 하나
//


class Dog : public Animal {
public:
	void speak() {
		cout << "Dog" << endl;
	}
};

int main31() {

	// upcasting
	Animal* a = new Dog();
	a->speak();
	// 부모의 speak을 부름
	// 결과는 animal 이 나옴
	// 부모의 speak에 virtual 을 붙이면 dog가 나옴

	/*Dog* d = new Dog();
	d->speak();*/

	Dog d;
	Animal& aa = d;
	aa.speak();
	// 얘도 역시 dog를 부름

	Dog d2;
	Animal a2 = d2;
	a2.speak();
	// 이건 애니멀을 찍음
	// 다이나믹 바인딩은 객체 타입에는 성립을 안함
	// 포인터에 대해서만 성립함
	//


	return 0;
}

class P2 {
public:
	virtual ~P2() {
		cout << "P2 소멸자" << endl;
	}
};

class C2 : public P2 {
public:
	int* p;
	C2() {
		p = new int[40];
	}
	~C2() {
		delete[] p;
		cout << "C2 소멸자" << endl;
	}
};


int main() {

	C2* c = new C2();

	delete c;
	// 상속 관계라 두개의 소멸자 모두가 나오고
	// 문제가 안생김

	cout << endl;

	P2* p = new C2();
	// 업캐스팅

	delete p;
	// p2 소멸자만 나옴
	// c2 소멸자의 콜이 안되어 
	// 메모리 leak이 생긴다.
	// 
	// 부모의 소멸자에 virtual 을 해주면
	// 두개의 소멸자를 모두 만들어준다.
	// 
	// 업캐스팅의 문제를 해결해준다.
	// 
	// 업캐스팅 아니면 virtual 쓸 이유가 없음
	// 
	// 다른사람이 쓰는 경우를 생각해
	// 소멸자 앞에는 virtual을 써주는게 좋음
	//

	cout << endl;


	C2* cc = new C2();
	delete cc;


	return 0;
}