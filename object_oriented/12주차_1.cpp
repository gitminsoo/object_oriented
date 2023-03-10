
#if 1



#include <iostream>
#include <vector>

using namespace std;

int main1() {

	// p.570 
	// multiple catch

	//
	vector<int> v = { 1,2,3,4,5 };

	try {
		cout << v.at(0) << endl;
		cout << v.at(10) << endl;
		cout << v.at(2) << endl;
		v.resize(v.max_size() + 1);
		// �������ᰡ �ȵǰ� �����Ѵ�.
		// error == exeption 
		// ó���� ����� �����༭ �����ž�
		// exeption�� ������ ���� �Ѿ�Ƿ�
		// ���� ���� ���� ����� �ȵȴ�.
		// ��� �޼����� �¶��� �˻����� 
		// ������ �� �� �ִ�. 
		// ������ ���� try catch ������ ����� ���� ����.
	}
	
	catch (out_of_range& e) {
		cout << "me : " << e.what() << endl;
		// ���� ĳġ���� ����ϸ� 
		// ���⼭ ������ �ؿ��ű����� ������� �ʴ´�.
		// ���ϴ� exeption�� ���� ĳġ���� ���ָ�ȴ�.
	}

	catch (length_error& e) {
		cout << "me : " << e.what() << endl;
		// resize �� ���� ���� ó��
	}
	
	catch (exception& e) {
		// ��� ������ ����ش�.
		// ������� ������ ���ִ� ���۷��� ����
		
		cout << e.what() << endl;
		// invalid vector subscript
		// �� ������ش�.
		// ���⼭ exeption ó���� ���ֱ� ������
		// �Ʒ��� program ended�� ������ش�.
	}

	cout << "program ended" << endl;


	return 0;
}

/*
	functiom template vs
	function overloading or overriding
*/

template <typename T>
void showValue(T v)
{
	cout << v << endl;
}

int main2() {
	showValue(10);
	showValue(3.14);
	showValue('c');
	showValue("hello");
}

/*
	class template ==> class ���� ��������
	: class template --> class 
	: class ---> object, instance
*/

// ���� �� ������ �ڵ� ���ĺ���

//template <typename T>
//// ��� ������ �ڷ����� ������� �ٲ� �� �ִ�.
//class Box {
//private:
//	T data;
//public:
//	Box(){}
//	Box(T _data):data(_data){ }
//	T getData() {
//		return data;
//	}
//	void showMyData();
//};
//
//template <typename T>
//void Box<T>::showMyData() {
//	cout << data << endl;
//}
//
//template <typename T>
//class MyItem {
//private:
//	int k;
//public:
//	MyItem() {
//		k = 99;
//	}
//	void showK()
//	{
//		cout << k << endl;
//	}
//	void setData(T _data) {
//		k = _data;
//	}
//};
//
//template <typename T1>
//template <typename T2>
//
//class DBox {
//private:
//	T1 data1;
//	T2 data2;
//};
//
//int main3() {
//	
//	// untyped language
//	/*a = 10;
//	a = 'c';*/
//	// pyton --> type annotation
//	// a: Int = 10;
//	// strongly typed language
//	// c++ ��..
//
//
//	vector<int> v = { 1,2,3,4,5 };
//	// ���ʹ� Ŭ���� ���ø�
//	// vector<int> -> �ϸ� Ŭ���� v�� �װɷ� ������� ��ü
//
//	// 1�ܰ� : int �� �����ͷ� ���� class�� 
//	// class template���κ��� ����
//	// 2�ܰ� : ������� class Box<int> �� ���� ��ü�� �����.
//
//	Box<int> b(10);
//	Box<double> c(10.4);
//
//	cout << b.getData() << endl;
//
//	return 0;
//}
//
//
//int main() {
//
//	Box<MyItem> my_box;
//	MyItem i;
//	my_box.setData(i);
//
//	DBox<string, int> db;
//	DBox<string, string> db2;
//
//	return 0;
//}

// ���ư��� �����ڵ� �ѹ� ����

//#include <iostream>
//
//using namespace std;
//
//template<typename T>
//class Box {
//private:
//	T data;
//
//public:
//	Box() {
//
//	}
//	Box(T _data) : data(_data) {
//
//	}
//	T getData() {
//		return data;
//	}
//	void setData(T _data) {
//		data = _data;
//	}
//	void showMyData();
//};
//
//template <typename T>
//void Box<T>::showMyData() {
//	cout << data << endl;
//}
//
//template <typename T1, typename T2>
//class DBox {
//	T1 data1;
//	T2 data2;
//};
//
//class MyItem {
//private:
//	int k;
//
//public:
//	MyItem() {
//		k = 99;
//	}
//	void showK() {
//		cout << k << endl;
//	}
//};
//
//int main(void) {
//
//	DBox<string, int> db;
//	DBox<string, string> db2;
//
//	Box<MyItem> my_box;
//	MyItem i;
//	my_box.setData(i);
//
//	MyItem v = my_box.getData();
//	v.showK();
//
//	return 0;
//}


/*
	p. 595
	STL
	C++ STL
	standard Template Library
	vector<int> <-- ��ǥ���� ����

	1. container
	�����͸� ��Ƶд�...
	��Ƶδ� ������ �����̳ʶ�� �Ѵ�.
	vector, list, queue, stack, priority queue, set, map...
	set -> �ߺ��� ������� �ʴ� �����͵��� ����
	map -> c����� �ؽ����̺� mapping�� ���Ӹ�

	2. iterator
	�ݺ��� -> contain �ȿ� �ְ� �ϳ��� �������� ������ ���°� 


	3. algorithm
	find, sort, reverse, remove, transform
	transform -> ��ü�� ���� ��ȭ

	c++ �� ���� �ð� ���Կ� �� �Ȱɷ��� ���迡 ���� �� 
*/

#endif // 0

#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

// p. 612
// vector, list
 
int main11() {

	/*
		list -> DLL
		vector -> array, contiguous memory
		�迭������ 5�� ������ 10������ �Ҵ� �޾� ����

		list : insertion , deletion ���� ���� 
		vector : add�� ����, insertion, deletion �� ��Ȳ�� ���� �ٸ���
					����� �����ϰ� �� ���� ���鿡 ���� �̵� �ð��� �ٸ��� ������
		
		list : large memory
		vector : small memory

		list : no default size
		vector : default size (�þ�� default size�� ����)

		list : random access is not possible. at(i) --> �Ұ���
		vector: v.at(i) --> �迭�̶� �����Ѱ�

		���̸� �˰� �־�� ���� �� ������ ���� ���� �� ���� 
		list -> �ӵ��� ���� �� ������ �׷����� vector
		vector -> ����� ��� ��ȭ�� ����� �׷����� list 
	*/

	vector<int> v = { 3,2,1,5,4 };
	list<int> v2 = { 3,2,1,5,4 };

	for (auto& e : v)
	{
		cout << e << " ";
	}

	cout << endl;

	for (auto& e : v2)
	{
		cout << e << " ";
	}


	return 0;
}

/*
	Iterator
	== generalized pointer
	begin()
	end()
	++
	--
	*
	rbegin() : reverse begin
	rend() : reveese end
*/

int main12() {

	list<int> v = { 3,1,2,4,5 };

	for (auto i = v.begin();i!=v.end();i++)
	{
		cout << *i << endl;
	}

	for (auto& i : v)
	{
		cout << i << endl;
	}

	v.sort();

	for (auto& i : v)
	{
		cout << i << endl;
	}

	return 0;
}

int main() {

	/*
		#include <deque>
		deque == double ended queue
		����� ���� ������ ť
	*/

	deque<int>dq = { 1,2,3,4,5 };
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(999);
	dq.push_front(100);

	//dq.pop_front(); dq.pop_back();


	for (auto& i : dq)
	{
		cout << i << endl;
	}

	return 0;
}
