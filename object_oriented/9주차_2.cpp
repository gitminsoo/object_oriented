
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

	bool operator!=(MyVector& other)
	{
		return !(*this == other);
		// 위에거를 이용해서 만든다
		// this가 포인터라서 별표를 붙임
	}


	MyVector addToVectors(MyVector& v)
	{
		MyVector temp(this->x + v.x, this->y + v.y);
		return temp;
	}
};
//==================================================================

// p.407
// ++ : increment operator
//

class MyValue {
private:
	int x;
public:
	MyValue(int _x):x(_x){}

	/*
		 전위연산자 : prefix increment operator
		 왜 레퍼런스인지 후위연산자는 원본인지 등등에 대해
		 이해 꼭 하기
	*/

	MyValue& operator++() {
		this->x = this->x + 1;
		// 복사본이 넘어가는거라 문제가 생김
		// 레퍼런스를 넘겨주면 됨
		return *this;
	}

	/*
		 후위연산자
		 안에 int 를 넣어줌
	*/

	MyValue operator++(int) {
		// 레퍼런스를 안한 이유는 temp가 복사본이라 
		// 사라지고 넘기며 복사본이 또 넘어가기 떄문에
		// 복사본을 또 넘기므로 그렇게 만들지는 않는다.

		MyValue temp = *this;
		// 나를 복사해서 하나를 만든다.
		this->x = this->x + 1;

		return temp;
	}

	/*
		대입연산자
	*/
	MyValue& operator=(const MyValue& other) {
		// const 를 붙인 이유는 굳이 저 값을 바꿀 이유가 없으므로
		 this->x = other.x * 2;
		 return *this;
		 // void 로 해도 동작은 함
		 // 
	}

	/*
		index operator overloading
		 p.414
	*/
	int operator[](int k) {
		if (k < 50) {
			return -999;
		}
		else {
			return 999;
		}
	}





	void showMyValue() {
		cout << "My Value is " << x << endl;
		
	}

};

class MyIntegerPtr {
private:
	int* p;
public:
	MyIntegerPtr(int* _p) : p(_p){
		
	}
	~MyIntegerPtr() { // 스마트 포인터가 되는 핵심
		delete p;
	}

	int operator*() {
		// 값을 부를 수 있게하는 부분
		return *p;
		// 레퍼런스로 해도 좋음
	}


};

int main() {
	while (true)
	{
		MyIntegerPtr p(new int(40));
		// p는 객체
		// 객체는 자기가 생긴 블락을 벗어나면 소멸됨
		// 알아서 소멸자 콜 해서
		// p를 자동 딜리트 해서 누수가 안일어나게 함 
		// 블락을 벗어나면 소멸자를 부르기 위해 객체를 만드는 것
		//
		cout << *p << endl;
		// 이걸하고 싶어서 포인터 오버로딩

		
		//MyIntegerPtr* p = new MyIntegerPtr(new int(50));
		// 이거는 주소이기 때문에 소멸자가 안불려서 문제가 생김
	}

	return 0;
}

int main15() {
	// p. 416
	// 포인터 연산자의 중복
	// pointer operator overloading
	// 극강의 난이도
	//

	//while (true)
	//{
	//	int* p = new int(40);
	//	// 한개의 p가 다 가르키는게 아니라
	//	// 새로운 p가 가르키는거라 
	//	// 메모리 누수가 발생한다
	//	// memory leak이 발생
	//	// bad alloc 오류가 남
	//	// 할당할 메모리가 안남아서
	//	delete p;
	//	// 이걸 해줘야 정상화 됨
	//	// 이걸 잊은 경우를 대비해 유니크 포인터가 나옴
	//}

	//while (true)
	//{
	//	unique_ptr <int> p(new int(40));
	//	// 자체적으로 프리까지 해주어서 편함
	//	// 위와 같은 역할을 한다.
	//	// 메모리 누수의 역할을 알아서 처리해준다.
	//	// 
	//	// 이게 어떻게 만들어졌을까?
	//	// 이거에 대해 얘기하기 위해 보여줌
	//	// 만드는 방법이 
	//	// 포인터 연산자의 중복
	//	//
	//}

	

	return 0;
}


int main14() {
	MyValue v1(10);
	cout << v1[30] << endl;
	// 말도 안되는 소리지만 
	// 오퍼레이터 오버로딩이 가능

	return 0;
}


int main13() {
	// p.411 대입연산자

	MyValue v1(10);
	MyValue k = v1; // 복사생성자 : k가 원래 없었고 만들어짐

	MyValue v2(20);
	k = v2;  // 대입 연산자 : 원래 만들어진거에 대해 고치므로
	// 대입 연산자를 만들었기 때문에 40이 저장됨
	k = v2 = v1;
	// 이 체이닝에 void 반환형을 사용한다면 void 사용이므로 이상한 상황
	// 그래서 레퍼런스 타입을 쓰는게 맞음
	// 왜 레퍼런스를 넘기는가?
	// 복사본도 가능하지만
	// 복사본 사용하면 결국 복사본을 넘기는 것에 메모리 필요
	// 그래서 꼭 복사본이 아니라면 레퍼런스 사용하면 좋음
	// 
	// 이게 누적 되면 나중에 속도 차이가 확실히 남
	//

	k.showMyValue();

	return 0;
}


int main12()
{
	MyValue v1(10);
	v1.showMyValue();


	//++v1;
	//++v1;
	//++(++v1);
	//// 안에있는 값을 증가시키고 싶다
	//// 안에 있는 x값 증가를 시키고 싶다.
	//// ++(++v1); 이렇게 하면 왜 오류가 날까
	//// 반환이 없어서
	//// 반환을 넣어줘야 함
	//
	//v1.showMyValue();

	MyValue k = v1++;

	k.showMyValue();
	// k에는 v1의 옛날 값이 들어가기 떄문에 10이 들어가는게 맞음
	v1.showMyValue();

	(v1++)++;
	// v1은 실질적으로 한번 증가한것이다

	(++v1)++; // 12 원본이 넘어오고 복사본
	++(v1++); // 11 복사본이 넘어오고 원본 건들기
	// 이렇게 코드 짜지 말기 - 그냥 두줄로 나누어서 만드는게 중요

	v1.showMyValue();



	return 0;
}



int main11() {
	MyVector v1(10, 20);
	MyVector v2(10, 10);

	cout << boolalpha;
	cout << "v1 == v2 : " << (v1 == v2 )<< endl;
	// 연산자 오버로딩으로 이게 가능해진다

	cout << "v1 != v2 : " << (v1!= v2) << endl;


	return 0;
}






//====================================================================
// 저번수업

int main6() {
	MyVector* v1 = new MyVector(10, 10);
	MyVector v2(10, 10);

	

	return 0;
}

int main5() {
	MyVector v1(10, 10);
	MyVector v2(10, 10);


	MyVector v3 = v1 + v2;
	
	v3.showXY();

	cout << boolalpha;
	cout << "same? : " << (v1 == v2) << endl;

	MyVector* p5 = v1 + &v2;
	p5->showXY();

	return 0;
}





class MyOnlyObj {
private:
	int d;
private:
	static MyOnlyObj* instance;
	MyOnlyObj() {
		d = 100;
	}
public:
	static MyOnlyObj* getInstance() {
		if (instance == nullptr) {
			instance = new MyOnlyObj();
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
	

	p1->showD();
	p2->setD(300);
	p1->showD();

	return 0;
}




class MyObj {
private:
	int i;
	float j;

public:
	static int k;
	MyObj(int _i, float _j) : i(_i), j(_j) { }
	void showMyContent()
	{
		cout << "i : " << i << " " << "j : " << j << endl;
		cout << "k : " << k << endl;
	}

	static void showStatics() {
		
		cout << "I am static function\n" << endl;
		

		cout << k << endl;
	}
};

int MyObj::k = 10;

int main3() {
	MyObj::showStatics();
	return 0;
}

int main2() {

	MyObj o1(10, 3.14);
	

	o1.showMyContent();

	MyObj* o2 = new MyObj(20, 9.999);
	o2->k = 777;
	o1.showMyContent();

	return 0;
}