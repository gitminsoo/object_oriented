// 0926

//
// ������� ��ã���� ���� ��ġ�� ��������� �� 
// �ַ�� �ȿ� ������Ʈ�� �ִ�
// ������ ������Ʈ�� ������ ���� �ƴ� ���� �ִ�.
// ���� ��� ��� ��ã���� ������Ʈ ��Ŭ�� ��������
// ���� �������� ��°� ����.
// vs installer ���� �������� ���� �����
// ���� ���� ���� ���� ��� 
// �������� �ٲ� �� ���� 
// tools option international setting -> ����� 
// �ѱ��̸��� ������ �����ؼ� �̻��Ѱ� ���� 
// ���۸��� ����� ����
// ������Ʈ ��Ŭ�� c/c++ �Ϲ� - ���� - ��� �߰�
//

//
// p.196 - ��ü���� ���α׷��� �����
// 
// 1. Encapsulation (ĸ��ȭ)
// -> ĸ���� Ŭ������ ���Ѵ�. -> ĸ���ȿ� �����Ϳ� �޼ҵ尡 ���� �ִ�.
// �ڵ� ���뼺�� �ö󰣴�
// 
// 2. information hiding (��������) : p.198
// public �� Ŭ���� �ۿ����� ��� ���� ���� ����
// private �� �ٲٸ� �ۿ��� �ִ��� ���� �𸣴� ������ ���°� �� 
// ���������ڸ� �̿��Ͽ� ��������� ��ȣ�ϴ� ��
// ������ ���� �Ѵ�.
// 
// 3. inheritance(���) : p.199
// �θ� Ŭ������ �ڽ� Ŭ���� ������ ��� ���
// ������ ���� �ڵ� ���뼺�� ����
// 
// 4. Polymorphism (������) : p.200
// �̰��� ���� -> ��ü�� Ư���̳� �ƴϳ� �� ���� ��������
// �������� �ƴ϶�� ���� ��
// overloaded function �� ū ����
// overloaded func, method ��� 
// 
//

//
// p.205 UML
//       Unified Modeling Language
// 100���� �׷��� 
// c�� �������� ������ c++�� UML �� �ִ�
// ����� ���ۿ� �ĺ���^^
// class���� ���� , ���� ����� �׸����� ǥ�� 
// --> UML Ǯ�� ���� ���� �ϳ��� ����^^
// 


//#include <iostream>
//
//using namespace std;

//int my_add(int a,int b) {
//	return a + b;
//}
//float my_add(float a, float b) {
//	return a + b;
//}
//
//class Circle {
//public:
//	// ����������
//	// 3���� �� protected �� 
//	// �ܺο����� ������ �ȵ����� �ڽĿ��Դ� ����� ����� �Ҷ�
//	// �ۿ��� ������ private �ڽ��� ������ public
//	//
//	int x;
//	int y;
//	int r;
//
//public:
//	void increase_radius(int d)
//	{
//		r = r + d;
//	}
//};
//
//class ColoredCircle : public Circle{
//	// ������ ���ǰ� �����ؾ������� 
//	// �ڵ尡 �ʹ� ����� --> ����� ����
//	// ��ó�� ǥ���ϸ� ��κ� �������� �߿��Ѱ�
//	// 
//	// ���ǰ��� �� ������ �ְ� �Ʒ��� �߰�
//	//
//private: 
//	string color;
//};
//
//int main(){
//
//	Circle c;
//	c.x = 10;
//	c.y = 10;
//	c.r = 30;
//	c.increase_radius(20);
//
//}

// p. 219 
// ������ (constructor)
// ��ü ����� �ʱⰪ�� �־��ִ� �Լ�
// �������� ����
// 
// 0. ��ü�� ������ �� ���� �� �ѹ��� ȣ��ȴ�.
// -> �ٽ� ȣ���� ��ü�� ���� ����� ����ۿ� ����
// 1. �̰��� �Լ��̴�
// 
// 2. ��� class �� constructor�� ���´�,
// -> �ȸ���� ���Ƶ� default constructor ��
// Circle(){
// }
// ������ constructor�� �ڵ����� ����� �д�
// 
// �׷� �ϳ��� ����� default�� �����ؼ� 2���ΰ�??
// constructor�� �ϳ��� ����� �����Ϸ��� default constructor�� �ȸ����.
// �� 1��
// 
// default ����� ���� Circle cd;
// Circle cd(); -> �̷��� ġ�� �Լ��� �����ϰ� �Ǵ°���
// ����Ʈ�� �θ��°� �ƴ� 
// ����ϱ�
// 
// 
// 3. polymorphism �� �����Ѵ�
// 4. default argument�� �����Ѵ�
// -> �Լ��� �⺻ default ���� ����
//


//class Circle {
//public:
//	// ����������
//	// 3���� �� protected �� 
//	// �ܺο����� ������ �ȵ����� �ڽĿ��Դ� ����� ����� �Ҷ�
//	// �ۿ��� ������ private �ڽ��� ������ public
//	//
//	int x;
//	int y;
//	int r;
//
//	// constructor
//	// �Լ��� �̸��� �������ִ�.
//	// ��ȯ���� ���°� ���� ū Ư¡
//	// ȣ�� ���ص� �ҷ���
//	// polymorphism �� ����
//	Circle(int _x, int _y, int _r) {
//		x = _x;
//		y = _y;
//		r = _r;
//	}
//
//	Circle(int  _r) {
//		r = _r;
//	}
//
//	Circle() {
//		x = y = r = 0;
//	}
//
//	void showinfo() {
//		cout << x << " " << y << " " << r << endl;
//	}
//};
//
//
//
//int main(){
//
//	// constructor �� ���� �ʱ�ȭ
//	Circle c(10, 10, 5);
//	c.showinfo();
//
//}


//
// p.226  �Ҹ��� : destructor <---> constructor
// ��ü�� ����� �� �ڵ����� �Ҹ��� �Լ�
// ���� �Ⱥҷ��൵ ��
// ��� Ŭ������ ���� 
// �ȸ���� default �� ����
// �ϴ� ����
// ���� ��� constructor�� malloc �� ������� 
// �Ҿ���� �޸𸮰� ����
// �̷��� free �Ҷ� �������� ������ 
// ��ü�� ����, ��� �� �޸� �Ҵ���� Ǯ���ֱ� ���� 
// ����
// ��ü ���� �Ҹ꿡 ���� ����뵵 ����
//

// p.232 �������� access control 
// 
// private, public, protected
// ���� Ŭ���� member variable �� private�� �صδ°� ������
// Ŭ������ �ϳ��� ����ϴ°� �ƴ϶� �ٸ� �ֵ��� ��ģ�ſ�
// �ٸ� �ڵ尡 ���� ��ȭ�� ����ų �� �ִ�.
// �а� ���� method ������ �ʼ���
// �д� �޼ҵ� -> getter
// ���� �޼ҵ� -> setter
// ��޾��� �˾Ƽ� ����� �ִ� �� ����
// c++�� ������ ��
// 
//

// p.240
// ��ü�� �Լ�
// class �� call by value�� �Ѿ��...
// -> �޸𸮰� �ʹ� �������� �ʳ���?
// �׷��� refernce �����ڷ� �ѱ��.
// 
// �� value �� �Ѱ�����
// ���纻 �ѱ�°� �������� �ƴϴ�
// ��ü �ȿ� ��ü�� ����ִ� ��찡 �ִµ�
// �װ� �����ϱⰡ �������,,
// 


//class Circle2 {
//private:
//	// ����������
//	// 3���� �� protected �� 
//	// �ܺο����� ������ �ȵ����� �ڽĿ��Դ� ����� ����� �Ҷ�
//	// �ۿ��� ������ private �ڽ��� ������ public
//	//
//	int x;
//	int y;
//	int r;
//	
//public:
//
//	void setX(int _x)
//	{
//		x = _x;
//	}
//	int getX()
//	{
//		return x;
//	}
//
//	// constructor
//	// �Լ��� �̸��� �������ִ�.
//	// ��ȯ���� ���°� ���� ū Ư¡
//	// ȣ�� ���ص� �ҷ���
//	// polymorphism �� ����
//	Circle2(int _x, int _y, int _r) : x(_x), y(_y), r(_r) {
//	} // �̷��� ����� ������ ���� ���ٷ� ���°Ͱ� ���� �ǹ�
//
//	~Circle2() {
//		// destructor
//		cout << "destructor is called " << endl;
//		// �����ϸ鼭 �˾Ƽ� �ҷ���
//	}
//
//	void showinfo() {
//		cout << x << " " << y << " " << r << endl;
//	}
//};
//
//
//class Circle {
//public:
//	// ����������
//	// 3���� �� protected �� 
//	// �ܺο����� ������ �ȵ����� �ڽĿ��Դ� ����� ����� �Ҷ�
//	// �ۿ��� ������ private �ڽ��� ������ public
//	//
//	int x;
//	int y;
//	int r;
//
//	// constructor
//	// �Լ��� �̸��� �������ִ�.
//	// ��ȯ���� ���°� ���� ū Ư¡
//	// ȣ�� ���ص� �ҷ���
//	// polymorphism �� ����
//	Circle(int _x, int _y, int _r) : x(_x),y(_y),r(_r) {
//	} // �̷��� ����� ������ ���� ���ٷ� ���°Ͱ� ���� �ǹ�
//
//	~Circle() {
//		// destructor
//		cout << "destructor is called " << endl;
//		// �����ϸ鼭 �˾Ƽ� �ҷ���
//	}
//
//	void showinfo() {
//		cout << x << " " << y << " " << r << endl;
//	}
//};
//
//bool compare_circle(Circle2& c, Circle2& d)
//{
//	if (c.getX() == d.getX()) {
//		return true;
//	}
//	return false;
//}
//
//
//
//
//int main(){
//
//	Circle c(10, 10, 30);
//	c.showinfo();
//	return 0;
//}


// 0928 

#include <iostream>

using namespace std;

// p. 253
// ��ü�迭
// 
// class �� ���� ��������� instance
// 
// ũ�⺯ȭ�� �Ұ��� �ϴٴ� ������ ����
// �ε����� �ٷ� ���� �ϴٴ� ����
// �޸� ȿ������ ���� ���� ����.
// 
// �׷��� ���°� ��ũ�� ����Ʈ
// 
// ¥�ߵ�...??
// �̹� �� �־�~
// 
// c++ �� ��ũ�� ����Ʈ�� ���� ��
//


#include <vector> // linked list  


class Circle {
public:
	int x, y;
	int radius;

	Circle() : x(0), y(0), radius(0) {
		cout << "Circle constructor was involved\n" << endl;
	}

	Circle(int _x, int _y, int _radius) : x(_x), y(_y), radius(_radius) {
		cout << "Circle constructor was involved\n" << endl;
	}
	void showCircleInfo()
	{
		cout << x << " " << y << " " << radius << endl;
	}
};

//int main()
//{
//	// p.261
//
//	// template 
//	// c++, �ڹٵ ����
//	// ���� �� �Ǿ��ְ� ���븸 ����ִ�.
//
//	// vector ������ 
//	// standard template library (STL) --> vector
//	// ť ���� ��� �� ����
//	//
//
//	//
//	// chap 15. STL �� ���ٽ�
//	//
//
//	//
//	// vector �� Ŭ���� 
//	// �����ϴ°� ����~
//	//
//
//	vector<int> first(5);
//	// ������ ���� ��
//	// first�� �̸� 10�� ¥���� ����
//	// int ���� ������ ���� 10�� ¥�� ����Ʈ
//	//
//
//	// �迭ó�� ��� ����
//
//	/*for (auto v : first)
//	{
//		cout << v << endl;
//	}*/
//
//	//cout << first[5] << endl;
//	// array indexing ok
//	//cout << first.at(5) << endl;
//	// ���� �ΰ��� ���� ����
//	// at�� �޼ҵ�ϱ� vector�� Ŭ������
//
//
//	first.push_back(100);
//	first.push_back(200);
//
//	// ���� �߰��Ǹ� �ڿ� ����
//
//	//cout << first.front() << " " << first.back() << endl;
//	// �� �� �� �ڰ� �� �� ����
//	// �̷��� �׳� cplusplus reference ����Ʈ���� ã�� �� ����
//
//	// begin , end
//	// begin�� head�� �ּ�
//	// end �� ���Ͱ� ���������� Ȯ���ϴ� Ư�� ����
//	// �������� �ƴ� �� ������ ����Ű�� ���� �ּ� �� NULL �� �˷���
//	// end()-1 �ؾ� ������ �μ�
//	//
//
//	cout << "___________" << endl;
//	
//	for (auto p = first.begin(); p != first.end(); p++)
//	{
//		cout << *p << endl;
//		//printf("%p : %d\n", p, *p);
//	}
//
//	auto p = first.begin();
//	cout << *(p+5) << endl;
//	// ������ 5�� ���� �پ� �ִ°��� �ƴϴ� ����
//
//
//	first.pop_back();
//	// �ڿ������� ���ִ� ��
//	// 200 ����
//	// ��ȯ�� ������ ������
//
//	vector<int> b;
//	b = first;
//
//	if (first == b)
//	{
//		cout << "thet same" << endl;
//	}
//	// �� , ���� �� ������ ����
//
//	// insert
//
//	first.insert(first.begin(), 999);
//	cout << first.at(0) << endl;
//	// ��ġ�� �ּҷ� ���� �׷��� ������� ����� �ִ� ��
//	// first.begin() + 1;
//	// �̷�������
//
//
//	// assign
//	// �μ� �ΰ��� �޾� ���� �Ϳ��ٰ� �ڿ��� �ִ´�?
//	// �̹� ������� �迭�� �ִ� ����
//	// ã�Ƽ� �غ���
//
//
//	// clear
//	first.clear();
//	cout << first.size() << endl;
//
//
//	for (auto v : first)
//	{
//		//cout << v << endl;
//	}
//
//
//
//	vector<Circle> second(10);
//	// �� ���ƴ� ���븦 ������ �����̴�
//
//
//
//	return 0;
//}

#include <algorithm>
// ���� ���� ����

#include <array>

bool compare(int a, int b)
{
	return a < b;
}

//bool compare(Circle a, Circle b)
//{
//	if ((a.x + a.y) < (b.x + b.y))
//	{
//		return true;
//	}
//	return false;
//}

int main()
{
	// p.270  algorithm
	

	vector<int> first{ 5,4,3,2,1 };
	
	//for (auto v : first)
	//{
	//	cout << v << endl;
	//}

	//
	//sort(first.begin(), first.end(),compare);
	//// ������ �μ��� asc desc ����
	//// c++ �� ����Ʈ

	//for (auto v : first)
	//{
	//	cout << v << endl;
	//}

	// 2���� ����
	//vector<vector<int>>a;
	//// ���� �ȿ� ����

	//for (auto i = 0; i < 3; i++)
	//{
	//	vector<int> row;
	//	for (int j = 0; j < 5; j++)
	//	{
	//		row.push_back(i * j);
	//	}
	//	a.push_back(row);
	//	// �̰� js���� table ������Ŷ� ����Ѱ� ������
	//	// ���� ���ϴ�.

	//	// ���� ���� ���Ͱ� ũ�Ⱑ �޶� �ȴٴ� ���� 
	//}

	// array
	// #include <array> �̰� ���
	// ��¥ ��̶� �Ȱ���
	// ���� ������ Ŭ������ �޼ҵ���� ���Ƽ� ���
	//

	array<int, 3> my_array;
	// ������ 3 ����
	my_array[0] = 10;
	for (auto v : my_array)
	{
		cout << v << endl;
	}
	//
	// size 
	// ��� ũ�� ��ȯ
	// fill
	// ���� ���ڷ� ä���
	// empty
	// ����ִ��� Ȯ��
	// at
	// 
	// front
	// ���ּ�
	// back
	// ���ּ�
	// 
	// �������� ���������� �Ⱦ��ñ� ��
	//

	// p.286
	// SFML : simple and fast multimedia library
	// ����¥�°� �����ͼ� ����°� ��ǥ
	// ���̺귯�� ��ƾ� ��
	//
	

}