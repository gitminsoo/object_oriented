
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

	bool operator!=(MyVector& other)
	{
		return !(*this == other);
		// �����Ÿ� �̿��ؼ� �����
		// this�� �����Ͷ� ��ǥ�� ����
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
		 ���������� : prefix increment operator
		 �� ���۷������� ���������ڴ� �������� �� ����
		 ���� �� �ϱ�
	*/

	MyValue& operator++() {
		this->x = this->x + 1;
		// ���纻�� �Ѿ�°Ŷ� ������ ����
		// ���۷����� �Ѱ��ָ� ��
		return *this;
	}

	/*
		 ����������
		 �ȿ� int �� �־���
	*/

	MyValue operator++(int) {
		// ���۷����� ���� ������ temp�� ���纻�̶� 
		// ������� �ѱ�� ���纻�� �� �Ѿ�� ������
		// ���纻�� �� �ѱ�Ƿ� �׷��� �������� �ʴ´�.

		MyValue temp = *this;
		// ���� �����ؼ� �ϳ��� �����.
		this->x = this->x + 1;

		return temp;
	}

	/*
		���Կ�����
	*/
	MyValue& operator=(const MyValue& other) {
		// const �� ���� ������ ���� �� ���� �ٲ� ������ �����Ƿ�
		 this->x = other.x * 2;
		 return *this;
		 // void �� �ص� ������ ��
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
	~MyIntegerPtr() { // ����Ʈ �����Ͱ� �Ǵ� �ٽ�
		delete p;
	}

	int operator*() {
		// ���� �θ� �� �ְ��ϴ� �κ�
		return *p;
		// ���۷����� �ص� ����
	}


};

int main() {
	while (true)
	{
		MyIntegerPtr p(new int(40));
		// p�� ��ü
		// ��ü�� �ڱⰡ ���� ����� ����� �Ҹ��
		// �˾Ƽ� �Ҹ��� �� �ؼ�
		// p�� �ڵ� ����Ʈ �ؼ� ������ ���Ͼ�� �� 
		// ����� ����� �Ҹ��ڸ� �θ��� ���� ��ü�� ����� ��
		//
		cout << *p << endl;
		// �̰��ϰ� �; ������ �����ε�

		
		//MyIntegerPtr* p = new MyIntegerPtr(new int(50));
		// �̰Ŵ� �ּ��̱� ������ �Ҹ��ڰ� �Ⱥҷ��� ������ ����
	}

	return 0;
}

int main15() {
	// p. 416
	// ������ �������� �ߺ�
	// pointer operator overloading
	// �ذ��� ���̵�
	//

	//while (true)
	//{
	//	int* p = new int(40);
	//	// �Ѱ��� p�� �� ����Ű�°� �ƴ϶�
	//	// ���ο� p�� ����Ű�°Ŷ� 
	//	// �޸� ������ �߻��Ѵ�
	//	// memory leak�� �߻�
	//	// bad alloc ������ ��
	//	// �Ҵ��� �޸𸮰� �ȳ��Ƽ�
	//	delete p;
	//	// �̰� ����� ����ȭ ��
	//	// �̰� ���� ��츦 ����� ����ũ �����Ͱ� ����
	//}

	//while (true)
	//{
	//	unique_ptr <int> p(new int(40));
	//	// ��ü������ �������� ���־ ����
	//	// ���� ���� ������ �Ѵ�.
	//	// �޸� ������ ������ �˾Ƽ� ó�����ش�.
	//	// 
	//	// �̰� ��� �����������?
	//	// �̰ſ� ���� ����ϱ� ���� ������
	//	// ����� ����� 
	//	// ������ �������� �ߺ�
	//	//
	//}

	

	return 0;
}


int main14() {
	MyValue v1(10);
	cout << v1[30] << endl;
	// ���� �ȵǴ� �Ҹ����� 
	// ���۷����� �����ε��� ����

	return 0;
}


int main13() {
	// p.411 ���Կ�����

	MyValue v1(10);
	MyValue k = v1; // ��������� : k�� ���� ������ �������

	MyValue v2(20);
	k = v2;  // ���� ������ : ���� ��������ſ� ���� ��ġ�Ƿ�
	// ���� �����ڸ� ������� ������ 40�� �����
	k = v2 = v1;
	// �� ü�̴׿� void ��ȯ���� ����Ѵٸ� void ����̹Ƿ� �̻��� ��Ȳ
	// �׷��� ���۷��� Ÿ���� ���°� ����
	// �� ���۷����� �ѱ�°�?
	// ���纻�� ����������
	// ���纻 ����ϸ� �ᱹ ���纻�� �ѱ�� �Ϳ� �޸� �ʿ�
	// �׷��� �� ���纻�� �ƴ϶�� ���۷��� ����ϸ� ����
	// 
	// �̰� ���� �Ǹ� ���߿� �ӵ� ���̰� Ȯ���� ��
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
	//// �ȿ��ִ� ���� ������Ű�� �ʹ�
	//// �ȿ� �ִ� x�� ������ ��Ű�� �ʹ�.
	//// ++(++v1); �̷��� �ϸ� �� ������ ����
	//// ��ȯ�� ���
	//// ��ȯ�� �־���� ��
	//
	//v1.showMyValue();

	MyValue k = v1++;

	k.showMyValue();
	// k���� v1�� ���� ���� ���� ������ 10�� ���°� ����
	v1.showMyValue();

	(v1++)++;
	// v1�� ���������� �ѹ� �����Ѱ��̴�

	(++v1)++; // 12 ������ �Ѿ���� ���纻
	++(v1++); // 11 ���纻�� �Ѿ���� ���� �ǵ��
	// �̷��� �ڵ� ¥�� ���� - �׳� ���ٷ� ����� ����°� �߿�

	v1.showMyValue();



	return 0;
}



int main11() {
	MyVector v1(10, 20);
	MyVector v2(10, 10);

	cout << boolalpha;
	cout << "v1 == v2 : " << (v1 == v2 )<< endl;
	// ������ �����ε����� �̰� ����������

	cout << "v1 != v2 : " << (v1!= v2) << endl;


	return 0;
}






//====================================================================
// ��������

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