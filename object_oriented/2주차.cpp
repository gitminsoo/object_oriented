//
// 
//

#include <iostream>  // #include <stdio.h>
#include <string> 
#include <ctime>
#include <cstdlib>

using namespace std;

//int main()
//{
//	cout << 100 << endl;
//	// std::cout     std::endl
//	// cout - console out
//	// endl - end of line(\n)
//	// �ַܼ� ������ ����
//	//
//
//	cout << "�Է��� ���ڸ� ��������" << endl;
//
//	int i;
//	cin >> i;
//	// cin �� ����i�� ���� ����
//	cout << "�Է��� ���ڴ� " + to_string(i) + " �Դϴ�." << endl;
//
//	return 0;
//}


int main()
{
	// p.49 ������
	// + - * / %

	// p.65
	// �����
	// ���迬���� relational operator
	// == != < > <= >=
	// c������ 1 or 0 �� ����� ���´�
	// c++ �� �� ����� bool ���·� ���´�
	//
	
	//bool b;
	//b = (1 == 2);
	//cout << b << endl;
	//// �̷��� �ϸ� ���� 0�� ����
	//cout << boolalpha;
	//cout << b << endl;
	//// ���� ������ �����ָ� 
	//// bool Ÿ���� ���ĺ����� �����
	//cout << noboolalpha;
	//cout << b << endl;
	//// �̷��� �ϸ� �ٽ� ���ڷ� ����

	// p.66 ��������
	// && || !

	// p.68
	// if else
	// c���� �Ȱ��� ���� ��
	//

	// p.76 
	// switch
	//

	//int c = 10;
	//switch (c)
	//{
	//	case 1:
	//		cout << "helld" << endl;
	//		break;
	//	case 2:
	//		cout << "world" << endl;
	//		break;
	//	default:
	//		cout << "others" << endl;
	//		break;
	//}

	// p.78
	// while , do - while
	//

	//while (false)
	//{
	//	cout << "infinite loop" << endl;
	//}
	//do {
	//	cout << "infinite loop" << endl;
	//} while (false);


	//string str;
	//do {
	//	/*cin >> str;
	//	cout << "�Է¹��ڴ� " + str << endl;*/

	//	/*getline(cin, str);
	//	cout << "�Է¹��ڴ� " + str << endl;*/

	//	// c����� strcat �� ������ ���ش� 
	//	// �Է� �߰��� �����̽��� �ָ� �� �ܾ ���ܼ� ����ȴ�
	//	// cin�� �Ѱ�
	//	// ������ \n ���� �ν��Ѵ�.
	//	// ���� �ν��� cin�� ����� �� ����.
	//	// �׷��� getlie() �Լ��� ������ش�
	//} while (str != "end");

	// p.81
	// for loop 
	// strictly typed language : c++ c java
	// python , inplicitly typed language
	//
	//for (auto i = 0; i < 10; i++)
	//{
	//	cout << "hello world" << endl;
	//	cout << "hello world\n\n";

	//	// auto �� �Ⱦ��°� ������
	//	// ����ó�� ���� �����°Ŵ� auto��
	//	// ¥�°� ����
	//	// auto �� �������ҿ� ����ϴ°� �ֿ���

	//	break;
	//	// �ڽŰ� ���� ����� for Ż��
	//	continue;
	//	// ���� ����� for�� ���� for�� �Ѿ��
	//}


	// p.95
	//int a[5] = { 1,2,3,4,5 };
	//int b[] = { 1,2,3,4,5 };
	//int c[]{ 1,2,3,4,5 };
	//// --> c �� c++��Ÿ��
	//// �迭�� ��ü�� ��� ���� ������ �̷��� �Ѵ�
	//// �������� �׳� aó�� ����.
	//// ��� ���� ��

	//int d[10] = { 1, };
	//// �� ���� 1 �������� all zero

	//string names[3] = { "tom","jane","james" };
	//// �����̾�... c���� �����ϰھ�?? ����ŵ�,,,
	//for (auto i = 0; i < 3; i++)
	//{
	//	cout << names[i] << endl;
	//}

	// p.99 
	// range based for loop
	//
	
	int num[] = { 1,2,3,4,5 };
	for (int /*auto*/ i : num)
	{
		// �̷��� �ϳ��� ���� �� �ִ�.
		// (auto i=0;i<5;i++) �� ���ǰ� ���� ����
		cout << i << endl;
	}
	string names[] = { "tom","jane","james" };
	for (auto i : names)
	{
		// ��.. ���ڿ��� �̷��� �ٷ��...?
		cout << i << endl;
	}


	for (int& i : num) {
		// int& --> & ���� 2�谡 ���� ����
		// 
		// pointer type int* i;
		// 
		// �������� ���輺 ==> ������ ���� ��찡 ����
		// �׷��� �ڹٴ� �����͸� ���ְ�
		// c++�� reference type�� ����
		// -- int& i;
		// int j = 100;
		// int& i = j;
		// i=200;
		// �̷��� ����� j�� 200�̵ȴ�
		// ���� �޸𸮿� �ٸ� �̸��� �ٿ��� ������ �����ϰ� �Ѵ�
		// 
		// ���ݴ� ����
		// �����ͺ��� �ξ� ������
		// �����غ���
		// 
		i = 2 * i;
	}
	for (int /*auto*/ i : num)
	{
		cout << i << endl;
	}

}



//__________________________________
// �������� <�ֻ���>
 
//#include <cstdlib>
//// rand, srand
//
//int main()
//{
//	// �ֻ��� �ùķ��̼����� 1 1 �� ���� Ȯ���� ���ض�
//	// c++ �Լ� ���
//	// cplusplus.com reference ���� ã�Ƽ� ���
//	// ���� �˻� �� ������� ���°� �߿�
//
//	int cnt = 0;
//	// 1,1�� ������ ����
//	srand(3000);
//	cout << "rand max is " << RAND_MAX << endl;
//
//	for (auto i = 0; i < 10000; i++)
//	{
//		int k1 = rand() % 6 + 1;
//		// �ֻ��� ���ڰ� 0�� �����ϱ�
//		int k2 = rand() % 6 + 1;
//		if ((k1 == 1) && (k2 == 1))
//		{
//			cnt++;
//		}
//
//	}
//	cout << "10000 �� �� " << cnt << " �� ����" << endl;
//
//}

//__________________________________