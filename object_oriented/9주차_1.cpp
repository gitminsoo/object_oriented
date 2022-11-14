//
// ���� ��������
// �ϴ� ����
//

// p. 384 
// ��������
// ���� �Լ�
// 
// static method (function) �� �������
// �ݵ�� ���� ������ ���� �Լ��� ����� �� �ִ�.
// �������� �����ϸ� �翬
// 
// non - static �޼���� ���� �޼��带 �θ� �� ������?
// �翬�� �θ� �� �ִ�.
//

//
// c++ ������ ������������ �����ؾ��Ѵ�
// ���������� �дٸ� 
// �Լ��� ���� ���� ������ ������ ���ư��� �ʴ� ������ ����
// �ڵ��� ��Ȱ�뼺�� ���� ������
// �׷��� ��ü ������ Ŭ���� �ȿ��� �� ����°� ����
// ���� ���� ���°� ����
// ���� �Լ��� �ʿ䰡 ����
// ������ ���Ѱ��� ���ִ°��� ����
// ��ü�� ��� �θ� �� �ִ� ���� ����, �޼��� ���
//

//
// p. 389
// singleton designe pattern (������ ����)
// ������ �����̶� 
// designe patterns GOF - ������ å
// �̰Ŵ� �˾ƾ� �߱��� �����ڴ� �� �� ����
// Gang Of Four
// 4���� ���ڸ� ����
// �ڵ� ���뼺�� �ش�ȭ �ϴ� ������ ��Ƴ��� å
// �� �о�� �� å
// ����� �������� �ݵ��
// ������ ������ ����� ������ ����
// �������� �����ϱ� �� �о��
// 
// �� �ȿ� �ִ� singleton pattern �� ����
// ��Ʈ�� �������� ����� �����̴�
// 
// ������� ���� ��� ������ �޼��尡 �� �ʿ�
// 
// ��Ȳ 
// -> � ������ �ִ�. �ٵ� ��� ¥�� ���뼺�� �ش�ȭ �� �� ������
// �̱����� ��Ȳ ::: Ư�� Ŭ�������� ���� �Ѱ��� ��ü�� ����������� �� �� ������
// ���Ӱ����� ���� ������ ������ �ϳ��� �����ؾ� �Ѵ� ���� ����
// �Ѱ��� ��ü�� ����������� 
// - 2���̻��� Ŭ������ ��������� �ʵ���
// ���??
// 
//

//
// p. 399
// operator overloading 
// ������ �����ε�
// �߾��� ����
// ������ ������ c++ ������ ���� �����
// �����̳�~
// function overloading�� ������ ���� ���� �� ����ѵ� �޶�
// 
//

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
		// + �� ���� �Լ��� ����°Ͱ� ����
		// ������ �����ε�
		cout << "ù��° ���ϱ� �����ε�" << endl;
		MyVector temp(this->x + other.x, this->y + other.y);
		return temp;
	}

	MyVector* operator+(MyVector* other) {
		cout << "�ι�° ���ϱ� �����ε�" << endl;

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


	MyVector addToVectors(MyVector& v)
	{
		MyVector temp(this->x + v.x, this->y + v.y);
		return temp;
	}
};

int main() {
	MyVector* v1 = new MyVector(10, 10);
	MyVector v2(10, 10);

	// MyVector v3 = v1 + v2;
	// ������
	// v1�� �ᱹ �����Ͷ� ������ ���ǵ� �Լ��� �ȰŴ�.
	// ������ �����ε��� �⺻ Ÿ�Կ� ���ؼ��� �ȵ�
	// ��ü�� ���ؼ��� ������.
	// ��ȣ �ȿ� �ִ� �ֵ��� ��ü���߸� �Ѵ�
	// �⺻ ������ �ȸ�����.
	//

	return 0;
}

int main5() {
	MyVector v1(10, 10);
	MyVector v2(10, 10);


	// MyVector v3 = v1 + v2;
	// ��ü������ ���� ���ǰ� �ȵǾ� ������ ����.

	/*MyVector v3 = v1.addToVectors(v2);
	v3.showXY();*/
	// �׷��� �̷��� �޼��带 ����� ����� �ִ�.
	// ���������� �ʰ� �������� ��������.
	// 
	// 
	// �׷��� ��ó�� �׳� ���ϰ� �; ���°�
	// �����ڿ����ε�

	MyVector v3 = v1 + v2;
	// ���� + �� �����ϴ�.
	// ��ü�� ���ϰ� ���°� ���� ��
	v3.showXY();

	cout << boolalpha;
	cout << "same? : " << (v1 == v2) << endl;
	// ��ü������ �����ڸ� �� �� ����

	MyVector* p5 = v1 + &v2;
	// ù��°�� �����̶� �׳� �ְ� ������ �޴°� �ּҶ� &����
	p5->showXY();

	return 0;
}















// Ŭ�����κ��� ���� 1���� ��ü�� ����������� �ϴ�
// �̱��� ������ ����� Ŭ����

class MyOnlyObj {
private:
	int d;
private:
	static MyOnlyObj* instance;
	// �����͸� �����̺����� ���Ƴ���
	// �ذ� ���缭 static���� ������ ��
	MyOnlyObj() {
		d = 100;
	// �ܺο��� �θ� �� ������ ���Ƴ��´�
	// �����ڸ� �����̺����� �־��� ����
	}
public:
	static MyOnlyObj* getInstance() {
		if (instance == nullptr) {
			instance = new MyOnlyObj();
			// ���̸� ���� ���� �����Ѵ�
			// ���� ���� �� �ִ� ������ static�̶�
			// �� �ϳ��� �����.
			// ���������� �ϳ� ����ɷ� ������ ����� 
			//
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
	// ��� ���� �ּҸ� ������ ����
	
	p1->showD();
	p2->setD(300);
	p1->showD();
	// p2�� �ٲٴ� p1�� ���� �ٲ��� �� �� �ִ�.
	// ����ƽ�� �ƴ� d�� ���� �� �� �ִ�.

	// �ϳ��� �����ϴ� ĳ���͸� ���鶧 �̷��� �̱������� ����� ������ ��

	return 0;
}




class MyObj {
private:
	int i;
	float j;
	
public:
	static int k;
	// k������ Ŭ���� �ȿ��� ����
	// ����ƽ�� ��� �����ִ¾� 
	// Ŭ������ ��������� ��� ��ü�� ���ؼ� 
	// ������ �Ѱ��� ī�Ǻ��� �����
	// �װ��� �����ؼ� ����Ѵ� 
	// Ŭ���� �ȿ� �Ѱ��� ��������� �����Ѵٰ� �����ϱ�
	// ������ �ڹٿ��� �״�� ����
	// ��ü�� ��� ������
	// ���� ���� -> ������Ʈ���� ���°����ϱ� ������ ����
	// ��ü�ʹ� ���� ����� ����
	// 1. �ʱ�ȭ �ϴ� ���� �ٸ�
	// �ؿ� ����
	//
	MyObj(int _i, float _j) : i(_i), j(_j){ }
	void showMyContent()
	{
		cout <<"i : " << i << " " << "j : " << j << endl;
		cout << "k : " << k << endl;
	}

	static void showStatics() {
		// static function
		// ��ü �Ⱥҷ��� ��밡��
		cout << "I am static function\n" << endl;
		// ��������� �ִ�.
		// �ȿ� �ִ� ��������� �θ� �� ����.
		// ��ü�� �־�߸� �ϴ� ���� �� �� ����.
		//
		//cout << i << endl;
		// ���� ����
		//

		cout << k << endl;
		// ����ƽ������ �θ� �� ����
	}
};

int MyObj::k = 10;
// static������ �ʱ�ȭ ���
// Ŭ���� �ۿ��� ���ִ°� ����
// Ŭ���� ���� ���ӽ����̽��� �ִ°����� ��Ÿ����
//

int main3() {
	MyObj::showStatics();
	// ��� ��ü�� �Ⱥҷ��� ����� �����ϴ�.
	return 0;
}

int main2() {
	
	MyObj o1(10, 3.14);
	// Ŭ������ Ÿ������
	// ����ϴ� ���� ��ü�ƴ�
	// �ڵ�� �����ؼ� �ϴ� ��찡 ����
	// �� ������ static �̴�
	//
	// �����Ҵ�
	//

	o1.showMyContent();

	MyObj* o2 = new MyObj(20, 9.999);
	// �����Ҵ�
	o2->k = 777;
	o1.showMyContent();
	// o2�� �ٲ㵵 �ٲ��� ���� �������� �� �� �ִ�.

	return 0;
}