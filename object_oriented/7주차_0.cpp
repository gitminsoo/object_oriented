//
// ������ ���� ������
// p. 323
// 
// ������
//

#include <iostream>
#include <string>

using namespace std;


// p.344 const ����Լ�

class Person {
public:
	int age;
	Person() {
		age = 10;
	}
	Person(int _age) :age(_age) {}

	int showAge(int x) const
	{
		age = age * 100;
		// �̷��� �ִ� ��찡 ����
		// �׷��� �̷��� ���� ���ؼ� 
		// const ��� �Լ�
		// Ŭ���� �ȿ��� ��� �Լ��� ���鶧
		// �Լ��ڿ� const �� ���̸� 
		// �� �Լ� �ȿ����� ��������� �ٲ��� �ʴ´ٴ� ��
		// ���� ������ ����

		return age;
		// read �ϴ°ž�
	}
};

int main() {

	// #define NULL 0
	// -> �����Ͱ� �ƹ��͵� ����Ű�� �ʴ´�.
	// 
	// c++ ������ nullptr�� Ȯ���� �ϱ����� ���� ����
	//
	/*int* p = nullptr;
	int a = 10;
	p = &a;*/
	// p. 325
	// �ʱ�ȭ ��
	// 0 or NULL �� 0�� �ǹ�
	// �̰ž� ���� ��¥ null pointer
	// ���� : �������� ��������.
	// auto p�� ���� for�� �����ϸ�
	// ������ �������� �ΰ����� ���� �� �� �ִ� ���ɼ�
	// nullptr�� ��ȯ���� pointer �ΰ��� Ȯ���� �� �� ����
	//

	// p.328
	// ���� �޸� �Ҵ� : dynamic memory allocation
	// ex : malloc/ free : heap ���� �޸�
	// ���� �޸� �Ҵ� : static memory allocation
	// ex : array
	// 
	// c++ DMA : new --> malloc, delete --> free
	// malloc free �� �ϴ� ������ �� ������ �߰��� ��� ����
	// 
	//

	int* a = (int*)malloc(sizeof(int));
	free(a);
	// ���� �ϴ� ���� ����
	int* a = new int;
	delete a;

	int* b = (int*)malloc(sizeof(int) * 10);
	free(b);
	// Ÿ���� 10�� �޴� ���
	int* b = new int[10];
	delete[] b;
	// �迭ó�� �������� ����� ����

	string* s = new string[10];
	s[0] = "hello";
	s[1] = "world";
	delete[] s;
	
	// ���� ����Ʈ �� ����ǰ�?
	// �׷��� ������ �� ����
	// �Ҵ� �������� �� �Ȼ�� ��
	// ������� ���� Ŭ����
	//

	Person p;
	p.age = 20;
	Person p[20];
	// �����Ҵ�

	// �����Ҵ�
	// �̷��Ը� �ϸ� ��

	/*Person* pp = nullptr;
	pp = new Person;
	pp = new Person(21);
	delete pp;*/

	// new �� ���� ����
	// clss �κ��� ��ü�� �����ϱ� ���ؼ�
	// malloc���� new�� �ϴ� ���� ���ƴ� ����
	// -- malloc���� ��ü�� ���� �޸𸮴� �Ҵ� ���� �� ������
	// -- malloc �� ������ ȣ���� ����
	// 
	// �׷� �⺻ int �����Ŵ� �� ����
	// ����� malloc new ������ �ϱ� �����Ƽ�
	// �ϳ��� ��ġ�� ��
	// 
	// delete -- free �� �ϴ��� + �Ҹ��� ȣ��
	// 
	// new delete ¦ ���ߴ°Ŵ� �� �ؾ� ��
	// �׷��� ���°�

	// p. 332
	// ����Ʈ ������
	// ���� : ���̻� ����Ʈ�� �Ű澲�� �ʾƵ� �ȴ�

	// delete ���ϸ� ������ �����
	Person* pp = nullptr;
	pp = new Person;
	pp = new Person(21);
	delete pp;

	// smart pointer, delete�� ����κ��� ����
	unique_ptr<Person> pp1(new Person(21));
	// �̸��� pp1
	// �ڴ� ������ �ڵ�
	// pp1�� ��� ��ü
	// tamplete �� Person �� unique_ptr �̶�� Ŭ����
	// �׷��� ��� ��¥ �����ʹ� �ƴ�
	// �׷��� unique_ptr �� ��Ʈ���Ϳ��� delete �� �� �ְ� �ϴ� ��
	// 
	// wrapper --> ���մ� ��� ǥ��
	// 
	// ��¥ �����ʹ� * �̰� ��
	// ����Ʈ �����ʹ� wrapper �ϻ�
	// �޸� ���� ������ ���ص� ��
	//

	pp->age = 30;
	// �����ͷ� ���� �Ҵ� �ȰŶ�
	// ȭ��ǥ�� �ؾ���

	// p.334 const pointer

	//// p�� ����Ű�� ���� ���� ���� ���� ������ �ٲ� �� ����
	//const int* p = 10;
	//// �ּ� 100�� �ٲ� �� ����
	//int* const p = 10;
	//// �Ѵ� �ȵ�
	//const int* const p = 10;

	// ��ü������ �״�� �̾���
	const Person* pp = new Person(20);
	Person* const  pp = new Person(20);
	const Person* const pp = new Person(20);
	// ù��° �ι�°�Ŵ� ����ϱ⿡ ���� ����
	// ��ް����ڵ��� ��ų

	



	return 0;
}