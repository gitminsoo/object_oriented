//
//  p.106 2���� �迭
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
//	// a�� �ִ°� �ϳ����� �̾� �´� 
//	// v���� 1 2 3 ū ����� ����
//	// v2 �� �� ���� ���� �ϳ��� �̾��ش�
//	// 
//	// range - based for loop
//	// 
//	// & ��ȣ�� ���� ������ �� 
//	// �� ������??
//	// &�� �Ⱥ��̸� ���� ù �迭�� �ּҰ� ���´� 
//	// �׷��� reference �� ���̸� v�� int* a ó�� ó����
//	// -- > int& a  �̰� ���̹Ƿ� �迭�μ��� ��Ʈ���� ���� ����
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
//	// ��Ʈ���� �迭�� ������ 2���� �迭
//	//
//
//	for (auto v : names)
//		// & �Ⱥ��̴� �Ŷ�� �ϴµ� �ٿ��� ������
//	{
//		for (auto v2 : v)
//		{
//			cout << v2 << " ";
//		}
//		cout << endl;
//	}
//}

////
//// p.123 �Լ�����
//// 
//// �Լ��� ���� ���ִ°� ������ �ڵ尡 �ʹ� ��������
//// �׷���  
////
//
//int fun1(int a);
//// function prototype
//// Ȥ�� function header 
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
//}// prototype ���� �̰� ������ ������ ������ �� 

//
// p. 130 �Լ�ȣ��� �μ����� ���
// call by value 
// call by reference
// 
// value 
// ���� �� �Ѱ��ִ� ��
// ������ �����ϴ� 
// ������ �ð��� ���� �ɸ��� �޸𸮸� �� ����
// �׷��� ������Ÿ���� �����ѰŸ� ���� 
// 
// reference 
// ������ �ּҸ� �ѱ�� ��� 
// ������ ������ �ǵ帱 �� ����
// ��뷮�� reference�� �ѱ�°� �´�
// array�� reference�� �Ѿ��
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
//	// reference variable ���°� ����
//	// �̷� �ڵ忡 ������ ���ش�.
//	// 
//	// �����ͷ� �޾Ƽ� �Ϸ���
//	// �ڵ带 �Ǽ��� ���ٸ� 
//	// �ٸ� �ֵ��� ���� ������ �� �� �ִ�
//	// ���������� �ֵ鳢�� �پ����� 
//	// 
//	// �̷����輺������ ���°�
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
//	// ���� �ٲ�� ���´�
//	// 
//	//
//}

//
// p. 135 �ߺ��Լ�
// overloaded func
// 
// argument type �� ����, ������ ����
// �ٸ� �Լ��� �ν��Ѵ�.
// 
// return Ÿ���� ������ prototype �� �ٸ��� 
// �ٸ� �Լ��̴�
// 
// �� �ʿ�??
// �Լ��� ���������� ���� �� �ִ�.
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
//// ��ó�� ���� float ���ļ�
//// ���������� ���� �� �ִ�.


//
// p.140 
// default parameter 
// ��κ��� �Ķ���Ͱ� �����Ҷ� ����
// ���� �ٲ��� �� ���°Ŵ�
// �ٲ�� ���� �ȵ�� ���� default �� ���� 
// ���� ������ ���� ������ ����
// 
// ���θ��� ����ϸ� �ȵ�
// �⺻ �μ��� �տ� ������ �ȵ�
// 
// ����Ʈ�� �ڿ������� ä�������� --> �߿�
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
// �Լ� ȣ�� �� �Լ��� ���ٰ� ���°� �⺻
// ���ƿ� �ּҸ� �����ϰ� �־�� �Ѵٴ� ����
// argument �� ��������
// ������� �����صΰ� return ���� �����س��� �ּҸ� ������
// main���� ���ư��� �� �ּҸ� ������ �ٽ� �� ���� �����´�
// ������尡 ����!!!
// 
// �׷��� �Լ��� ��� ���� ���� ���
// �ٵ� �׷��⿣ �ʹ� ������...
// 
// �ζ����� ���� �� �ڵ带 �����ؼ� �Լ� ȣ���ϴ� �κп�
// ���� ���δ� �׷��� �θ��� ��ŭ�� �ð��� ���δ�
// �ٵ� �ڵ� ũ�Ⱑ ũ�� �� 
// �ð��� �����̶� ���̱� ���ؼ��� ���µ��� ����
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
//	//	// ���� ���� ��
//	//}
//
//	// p.151 string member function
//	// s1[0]
//	cout << boolalpha;
//	cout << s1.empty() << endl;
//	// s1 ����ִ��� Ȯ��
//
//	cout << s1.insert(2, s2) << endl;
//	cout << s1.find("llo") << endl;
//
//}

//
// p.167
// 
// object oriented programming , oop
// ��ü���� ���α׷���
// 
// class �� ��ü�� structure
// �� �ȿ� �ڵ带 ���� ���� class 
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
// 9�� 21 ��
//___________________________

#include <iostream>

using namespace std;

//
// p.168 �������� ���α׷���
// procedural programming
// procedure == function
// 
// c : data �� function�� �и� 
// 
// p.170 
// 1960��� SIMULA
// 
// p.172
// ��ü�� �������� �̷�� ���°�
// 2���� 
// member variable == member field
// member function == method
// 
// p.174
// Ŭ������ ��ü�� ���赵
//

// p.176

//class Circle {
//	// member variable
//public : 
//	// �ۺ��� �ܺο��� ���� ����
//	// Ŭ������ ���δ� class a {(����)}
//	// private ���� �ٲٸ� �ܺ������� �Ұ�
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
// �Ϲ������� class ���� �빮�ڷ� ����

//class BankAccount {
//
//	// money�� class ���ο����� �ǵ帱 �� �ִ�.
//	// �̿� ���� �����͸� public: private:�� �̿��Ͽ�
//	// �����͸� ��ȣ�ϴ� ���� ���������̶�� �Ѵ�.
//
//	// �����͸� �ǵ帮�� ���� ���� class ���ο��� ������
//	// �޼��带 ���ؼ��� �ǵ帱 �� �ִ�.
//	// �׸��� �� �޼��� ���� ��� ������ġ�� �� �����Ǿ� �ִ�.
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
//	//// instance ��ü
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
// p.185 ����
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
//		// ���ø����̼��� ���α׷��� �Ҷ� ����� �Լ����� ����
//		// DC -> ��ȭ������ ���� direct context
//		// h�� handler
//		// 
//		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
//		// Ÿ���� �׷��ִ� �Լ�
//		// ���� ������ �´� Ÿ���� �׸��� �Լ���
//		// �ٵ� �Լ���鵵�� �ٸ�
//		// ��ǥ���� x�� �¿��� ��� ������
//		// y���� ������ �Ʒ��� �ݴ���
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
// p. 185 ��������
// x��ǥ�� 200 ���� 600���� 50�� ������Ű�鼭
// ���� �׸��ÿ�
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
//		// ���ø����̼��� ���α׷��� �Ҷ� ����� �Լ����� ����
//		// DC -> ��ȭ������ ���� direct context
//		// h�� handler
//		// 
//		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
//		// Ÿ���� �׷��ִ� �Լ�
//		// ���� ������ �´� Ÿ���� �׸��� �Լ���
//		// �ٵ� �Լ���鵵�� �ٸ�
//		// ��ǥ���� x�� �¿��� ��� ������
//		// y���� ������ �Ʒ��� �ݴ���
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
// ����Լ� �ߺ�
// method overloading
// 
// p.189 
// Ŭ���� �������̽��� ������ �и�
// �Լ� �����̳�ó�� ������ ���� ���
// Ŭ���� ���� ���ϰ� ��
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
// ����� ������ ������ �����ؼ� ����°� ����
// ���� ���� ��ȣ�� ���ؼ��� ù ����
// �Լ��� �ȶ��� ��������� �ִ°�
// .cpp�� assembly ���� �Ѱ��༭ �ѱ��� �ʴ´�
// ������ �Ҷ��� ������� ������ ������ ���� �� ����
//
#include "Circle.h"

int main()
{
	Circle c;
}