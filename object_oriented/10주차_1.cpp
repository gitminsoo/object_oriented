////
//// ������ �̾
//// 10.9 friend function and friend class
//// p. 419 
//// p. 424 ===> "���" ������ �Լ��� �� �ʿ��Ҷ��� ��� -> �ٵ� ����� ����
////
//
//#include <iostream>
//
//using namespace std;
//
//// private : access specifier, ���� ������
//// ==> OOP�� �߿��� ������ information hiding (��������)
//// �������� : ��ü ������ private�� ��ü ������ �Լ��� ���켭�� ����
////				==> �ڵ� security & safety �� ���ؼ� �߿�
//// 
//// �̰� ���� ���� �Ұž�
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
//	// �Լ��� ����� �߰� �ϰ� 
//	// ������ ������ �ߴ�.
//	// ģ�� �Լ��̱� ������ private���� ���� ����
//	// Ŭ���� ���ο��� ������ �ؾ� ��
//	// ��� �ǰ� ������ ����
//	// Ŭ���� �ȿ� �Լ��� �־��ִ°� ����
//	// �����带 �ȸ���°� ����
//	// �ִٴ°Ÿ� �˸� ��
//	// 
//
//	friend class B;
//	// B�� A�� ���� �� �� ���� 
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
//		// information hiding �� ��Ģ�� ����� ����
//		// �׷��� ���� �ȵ�
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
//// ===> <<,>> �������� �ߺ�
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
//// ������ �Ⱦ��� ����� �Ϳ� ���� �����غ���
//
//ostream& operator<<(ostream& os, Point& p)
//{
//	// ��� �ڱ� �ڽ��� ��� �ڱ� �ڽ��� �� �������� ��
//	// ��-> �ƿ�ǲ 
//	// ��Ʈ�� -> ���� 
//	//
//
//	os << p.x << ", " << p.y << endl;
//	// �����̺��̶� �ȵǴµ�
//	// å������ �̰Ÿ� ������� ����
//	// �̰��Ҷ�� ������ ����°Ŵ� ���ذ� �ȵ�
//	return os;
//	// �ΰ��� �������� cout ���ִ� ��츦 ����
//	// ostream& ������ ��ȯ���ش�.
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
//// operator overloading�� ���� �����ڸ� �� ���� �ϴ� ����
//// ���ο� �����ڸ� ���� ���� ����!!  !!! ?!! ?* -> �̷��Ŵ� �ȵȴ�
//// ������ �͸� ��� ����
////
//
////==================================================================================


// p. 439
// ���,, inheritance
// 
// ��������!!!
// ��� ==> ���꼺�� ���� �ʼ� ����
//

// public �� ������ ��ӵ� 
// private�� �Ѱ����� ����
// ���� !!! ����� �ȵ�
// �����̺��� �ƹ����Ե� ��ӵ��� ����
//

// �ڽĿ��Դ� ����� ���ְ� 
// �ۿ��� ������ �ȵǴ� �ְ�
// protected
// �̴�.
// --> ��ӿ��� public , �ܺο����� privarte
//

// p.445 ���������� , public, private, protected  �� ��� ������ ���� �ƴ°�

// p.449 �����ڿ� �Ҹ���
//

#include <iostream>
using namespace std;

class A {
public:
	int a, b;
	A() {
		cout << "�θ� ������" << endl;
		a = 10;
		b = 20;
	}

	A(int _a,int _b):a(_a),b(_b){
		cout << "�θ� ������ 2" << endl;
	}

	void showAB() {
		
		cout << a << ", " << b << endl;
	}
	~A() {
		cout << "�θ� �Ҹ���" << endl;
	}
};

class AA :public A {
protected:
	// AA�� �ƹ��� �����Ͱ� ������ A�� ���� ��ӹ��� a,b�� �ִ�.
	// �ڴ� ��ӹ��� Ŭ���� �̸�
	// ���� �ۺ��� ��ӹ޾� ��� ���ų�
	// ���� ���Ÿ� �޾ƿͼ� �ۺ����� ���� �� �ִ�.
	// 
	int c;
public:

	/*AA() {
		cout << "�ڽ� ������" << endl;
		c = 10;
	}*/
	AA() : A(21, 31) {
		cout << "�ڽ� ������ 2" << endl;
	}
	void showABsum() {
		cout << (this->a + this->b) << endl;
	}
	~AA() {
		cout << "�ڽ� �Ҹ���" << endl;
		c = 10;
	}
};

class AAA : public AA {

};

int main() {
	AA aa;
	aa.showAB();
	aa.showABsum();
	// �θ� �����ڰ� ��������� �ڽ��� ��������°� ����
	// �Ҹ��ڴ� �ݴ�� �ڽĺ��� �Ҹ�
	// �޸𸮰� �θ���� �����°��̹Ƿ� �̷��� ����
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
	// AA::c �� ������Ƽ��� �س��� ������ ��
	aaa.a = 10;
	aaa.b = 10;


	return 0;
}