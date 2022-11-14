// p.458 
// 11.6 ��� �Լ��� ������

#include <iostream>

using namespace std;

/*
	function overloading
	- �Լ� �̸��� ���Ƶ�, parameter ����, type, ������ �ٸ��� �ٸ� �Լ��� �ν�

	method overloading
	- Ŭ���� ���ǿ� ����� functuon overloading 

	overloading : �Ѱ��� �̸��� �������� �Լ��� �����ؼ�, �����(overloading) �Ѵٴ� �ǹ�

	method overriding
	- Ŭ�������� ���� : OOP
	- ��� ���迡���� �߻�
	- �ڽ� Ŭ�������� ������ method�� ������ signature(�Լ� �̸�, �Ķ����)�� ���� 
		�θ�Ŭ������ method�� ���������� ����

*/
#ifdef DEBUG

class Parent {
public:
	void whoareyou() {
		cout << "Parent" << endl;
	}
};

// parent �κ��� ��� �޾Ƽ� child Ŭ���� ����

// p.462
// pubkic:  public -> public   protected -> protected   private -> ���� ������
// protected : public -> protected   protected -> protected 
// private : public, protected -> private
// 

class Child : public Parent {
public:
	void whoareyou() {
		Parent::whoareyou();
		// �θ� Ŭ������ �Լ��� �θ��� ���
		cout << "Child" << endl;
	}
	// ����� �޾Ҵµ�
	// �Ȱ��� �̸��� �Լ��� ���� �Ǿ� �ִٸ�
	// �翬�� �ش翡 �ִ� child �� ������ �� �� �ִ�
	// 
	// �̷������� �м��� �غ���
	// Ŭ���� �ȿ� �θ� �����ϴ� ������ �ְ�
	// �ڽ� ������ �ִµ�
	// �Լ� �̸��� ������ �ڽ��� Ŭ���� �ȿ� �ִ� �޼ҵ尡
	// �θ��� �޼ҵ带 ������ 
	// �ö� ź�� (overriding) 
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
// ���� ���
// 
// multiple inheritance
// ����Ʈ���� �������δ� �Ⱦ��°� ����
// �ڹٴ� �̰Ŵ� ������ -> ����� �������̽��� ����
// 
// c++�� ����� �� �ۿ� ���� ��찡 ����
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
	// �̷��� ���� ��������� ��
	// ����Ʈ���� ���п����� ���� ������ ����

	return 0;
}

#endif // DEBUG

/*
	p.481, ������, polymorphism
	==> ��ü ���⿡�� �ְ�� ����
	������ : �����ϴ� ���
	==> � ��� �Լ��� �θ��� ��Ȳ�� ���� �޶�����!!

	���� polymorphism -> method overriding
	-> �� �׷��ĸ� ���� ���ø� ����
		whoareyou()�� ��� Ŭ������ �Լ��� �Ҹ����� �̹� �� �� ����
		�ڵ� �м��� ���� �� �� ����

	���� polymorphism : dynamic binding <-- �ذ� ���̵� (�������� �����Ͻ�)


*/
#if 0

class Parent {
public:
	int x;
	virtual void showme() {
		// �� �Լ��� ������ 
		// ���̳��� ĳ��Ʈ�� ������
	}
};

class Child : public Parent {
public:
	int y;
};

int main() {
	// upcasting : �θ�Ŭ���� Ÿ���� �����ͷ�
	// �ڽ� Ŭ������ ��ü�� ����Ű�� ��
	// 
  	// �չ��� ������ ���� ��
	// 
	// �θ� Ŭ������ �θ� Ŭ������ ����� ����ؾ� �Ѵ�.
	// �θ� �����ͷ� �ڽ� ����� �ǵ� �� ���� <--  ������ ����
	//
	/*Parent* p = new Child();
	p->x = 10;*/
	//p->y = 10;
	// parent �� ������ y �� ��� ������ ��


	//Child* c = new Parent();
	// �ȵǰ� ���� ���� ����
	// Ÿ���� �ٸ��� ������
	// �� ���� ���� ������ �θ� �����ϸ�
	// ���ٳ��� ��찡 �־ 
	// ������ �� 
	// ���������� ������ ����� 
	//

	// down casting

	Parent* p = new Parent();
	// Child* c = (Child*)p;
	// ������ �ȵ�����
	// Ÿ�� ĳ������ ���� �����Ͽ� ������ ������ ��
	// ������ y�� ���� ������ ����
	// ������ ������ ���°� ��
	//
	/*c->x = 50;
	c->y = 999;*/
	// �����Ϸ��� ����Ƴ���
	// ������ ���ٰ� ������ �� ������
	// ���� ������ ���ٰ� �ִ°ű� ������ ������
	// down casting�� ������ 
	//


	// p.487
	Child* c = dynamic_cast<Child*>(p);
	/*Child* c = (Child*)p;*/
	// �ٿ� ĳ���� -> ���� ����
	// �ڴ翡�� ���� �Ⱦ� ��ĳ���ø� ���� ��


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

//	virtual : ���� ��� ���ÿ�
//				Ȥ��, ��ӹ��� �ڽ��߿� overriding�� ���� ������ 
//				�װ��� �θ��ÿ� ���� virtual �̴�
// 
// dynamic binding : ��� speak()�� �Ҹ����� runtime�� ������ �ȴ�.
// ==> late binding
// 
// ������ �������̵��� ����� ���̵��� �ö�
// 
// �켱������ �纸? �̷� �������� �����ؾ� �ϳ�
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
	// �θ��� speak�� �θ�
	// ����� animal �� ����
	// �θ��� speak�� virtual �� ���̸� dog�� ����

	/*Dog* d = new Dog();
	d->speak();*/

	Dog d;
	Animal& aa = d;
	aa.speak();
	// �굵 ���� dog�� �θ�

	Dog d2;
	Animal a2 = d2;
	a2.speak();
	// �̰� �ִϸ��� ����
	// ���̳��� ���ε��� ��ü Ÿ�Կ��� ������ ����
	// �����Ϳ� ���ؼ��� ������
	//


	return 0;
}

class P2 {
public:
	virtual ~P2() {
		cout << "P2 �Ҹ���" << endl;
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
		cout << "C2 �Ҹ���" << endl;
	}
};


int main() {

	C2* c = new C2();

	delete c;
	// ��� ����� �ΰ��� �Ҹ��� ��ΰ� ������
	// ������ �Ȼ���

	cout << endl;

	P2* p = new C2();
	// ��ĳ����

	delete p;
	// p2 �Ҹ��ڸ� ����
	// c2 �Ҹ����� ���� �ȵǾ� 
	// �޸� leak�� �����.
	// 
	// �θ��� �Ҹ��ڿ� virtual �� ���ָ�
	// �ΰ��� �Ҹ��ڸ� ��� ������ش�.
	// 
	// ��ĳ������ ������ �ذ����ش�.
	// 
	// ��ĳ���� �ƴϸ� virtual �� ������ ����
	// 
	// �ٸ������ ���� ��츦 ������
	// �Ҹ��� �տ��� virtual�� ���ִ°� ����
	//

	cout << endl;


	C2* cc = new C2();
	delete cc;


	return 0;
}