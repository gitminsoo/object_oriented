//
// p.9
// 
// c++
// object oriented programming
// ��ü������
// 
// c: ����
// ���� : ���꼺�� �ſ� ����
// ���� : �ӵ� --> 10~100 �� ���� python, java
// �޸� ������
// 
// c++, Bjarne Stroustrup
// 
// �ڵ� ���뼺�� ��ü ������ ������ ����
// 
// c --> (SIMULA) --> c++
// ���� : �޸� ������ �����
// �׷��� 
// --> Java (c++ ���� �����͸� ����)
// --> C# (micro soft���� Java�� �����ϱ� ���� �������)
// Ű����ũ �ȿ� �׷��Ŵ� ��� C#���� �������
// 
// p.11
// class
// ==> struct + function 
// c���� dataó���� ���� �Լ��� ���� 
// �ΰ��� �и��� �Ǿ� �־ ������ ���� ���� 
// �ΰ��� ��ü�� ��ġ��!! --> �ٽ�
// data�� data�� ó���� �� �ִ� function�� ���� ������ ��
// 
// inheritance
// <-- ���
// ���� �緯�� ���� ��� �ʿ� ���߸� ���� �ȵ��
// �׷��� �ٸ� ���� ��?? --> c���
// �� ���� ���� �̰� �ֽð�� ���ߴ� �ٸ��ŷ� �ּ��� --> ���
// ������ �ִ� Ŭ������ �Ϻκ��� �ٲٴ� �� 
// 
// polymorphism 
// operator overloading
// 
// reference type
// <-- pointer ��ü��
// pointer�� ���輺�� ���� �� ����
// 
// standard library
// <-- ������ �����ð��� ��� �׷��� ������ �׳� �ҷ��� �� �� ����
// 
// new, delete
// <-- malloc free ���� ������ ����
// 
// generic
// <- type 
// c���� ���� �ΰ��޾� ���� ��ȯ�ϴ� �Լ��� �ִ�
// �ٵ� float���� �ʿ��ϸ� ���� ������ �Ѵ� 
// generic�� �ϳ��� ����� �׶��׶� type�� �˾Ƽ� �ٲ� �� �ִ�
// 
// p.16
// 
// ��������, ��ü����
// c , c++
//

// p.34

// #include <stdio.h> // printf, scanf
//#include <iostream> // c++������ .h�� ����
//
//using namespace std;
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	// cout console out --> ȭ��â�� �������� �� 
//	// ������ �귯�� console out ���� ����
//	// endl�� end of line --> �ٹٲ�ǥ�� ==\n
//
//	// std�� ����
//	// printf scanf�� ���.
//	// namespace ���͹ٸ��� ����
//	// c++�� ��ɾ�� �ٸ������ �浹�� ���� �� �ִ�. 
//	// �׷��� ���� �ٿ����� �װ� namespace
//	// �� �ڵ��� namespace�� ���̴� ::�� �װ� ����Ű�� ��
//	// std���� �ȿ� �ִ� cout�̴� 
//	// std���� �ȿ� �ִ� endl�̴� 
//	// � ������ ���������
//	// std:: �ϴϱ� ���� ����
//	//
//	//�׷���
//	// ���� using namespace std;
//
//	cout << "hello world"<< endl;
//
//	return 0;
//}


// p.39
// ������ �ڷ���
// 
// short 2
// int 4
// long 4
// long long 8
// 
// char 1
// 
// float 4
// double 8
// long double 8
// 
// c++ �߰��� 
// bool : 1
// 

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	bool b;
//	b = true;
//	bool c;
//	c = false;
//
//	cout << b << " " << c << endl;
//}

// ���ڿ��� : string

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s1 = "hello";
//	string s2 = "world!";
//
//	cout << s1 + s2 << endl;
//
//	cout << (s1 == s2) << endl;
//	// ���ڿ� �� 
//
//	const int k = 10;
//	cout << s1 + to_string(k) + s2 << endl;
//	// ���ڸ� ���ڿ��� �ٲپ��ִ� �� 
//
//
//
//}

// p.45 auto

#include <iostream>
using namespace std;

int main()
{
	int k = 10;
	auto v = 20;
	auto v2 = 13.3;
	// �ڷ��� �ڵ� ����
	// �ٵ� ���ϴ°� ���� 
	// �Ժη� ���°� �ƴ϶� ��� ���� ���°ſ��� ���°� 

	return 0;
}