//
// polymorphism, ������ : � method �� �θ��� �׶� �׶� �޶��
//
// OOP 1. : information hiding (��������) :
//		-- access specifier : private, public, protected
// OOP 2. : inheritance
//		-- reuserability (�ڵ� ���뼺)
//		-- parent's protected : child's public, outer's private
// 
// method(function) oveloading 
// method overriding : �θ�޼���� �Ȱ��� ������ �� ,,,
// 
// binding : static, dynamic
// � �Լ��� �θ��� ���°� ���ε� �Ѵٰ� �Ѵ�.
// static binding : 
//
// upcasting : �ڽ� ��ü���� �θ� Ŭ���� �����ͷ� ����ų �� 
// (�չ�)
// 
// downcasting : �θ� ��ü�� �ڽ� Ŭ���� �����ͷ� ����ų ��
// (�չ� - �ٵ� ������ ������)
//
//
// Dynamic binding : virtual (method �տ� �ٴ´�)
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
	// �θ��� showme
	// �޼��� �տ� virtual ���̸� 
	// �ڽ��� �������̵� �� �Լ��� ã�ư��� �װ� �θ�
	// virtual �� �پ�߸� dynamic binding
	pb->showMe();
	// �ڽ��� showme
	// �޼��� �������̵����� �ڽİŸ� ���




	return 0;
}

#endif //  0

//=========================================================================


#include <iostream>

using namespace std;

// 12.5 ���� ���� �Լ�
//			pure virtual method (func)
// ���� ���� �Լ��� ���� Ŭ������ ��ü�� ���� �� ������?
// ���ǰ� ���� ���� �Լ��� ���� ���� �Ҷ� ������ ����� ������
// ���� �� ����.
//

// pure virtual method �� ���� Ŭ������ Ư���� 
// abstract class (�߻�Ŭ����)��� �Ѵ�.
// abstract class�� ���ʹ� ��ü�� ������ ���Ѵ�.
// 
// �����??
// 
// 
//

//class A {
//public:
//	virtual void showMe() = 0;
//	// ���� ���� �Լ�!!
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
// �ڹ��� �������̽� ����
// C++ �� abstract class (virtual function) �� �̿��ؼ� interface ����
// 
// interface : Ŭ������ �ݵ�� �����ؾ� �� �޼ҵ���� ���

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
	// Circle �� ������� �ִ�
	// �޼��� �� ����Ŭ���� �ȿ� �ִ�
	// �޼����� �̸��� ���� �ְ� ������ ������ ����.

	Rect r(10, 10);

	Shape* s[3];
	// ��ü�� �� �������� �������� ������ ����

	s[0] = &t;
	s[1] = &c;
	s[2] = &r;

	for (int i = 0; i < 3; i++)
	{
		s[i]->getArea();
		cout << s[i]->getArea() << endl;
		// �̷��� ����� ��� Ŭ������ ���� ���� �� ���� 
	}


	return 0;
}

#endif // 0

//
// p. 519
// 
// ���� �����
// 
// stream : �ܺο� �ִ� �����͸� �а� ���� ���
// 
// input stream
// output stream  <-- �ڹٿ��� �ִ� ���
// 
// ������ 2���� ���� : text, binary
// text : ASCII code ������ ���� --> 0 : 48(10����), 0x30
// binary : �� �״�� --> 0 : 0
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	//ofstream os("test.txt");
	//// close �����൵ �� 
	//// ��ü�� �Ҹ��ڿ� �̹� ����

	//for (int i = 0; i < 100; i++)
	//{
	//	os << i << " ";
	//	// cout �� console out �̶�� ���� ��ü
	//}
	// ������Ʈ ���Ͽ� ������� ����

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
		// ĳ���� ������ �޾Ƽ� ���鹮�ڵ� �˾Ƽ� ���� 

	}

	return 0;
}