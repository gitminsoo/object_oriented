
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
		// 정상종료가 안되고 실패한다.
		// error == exeption 
		// 처리를 제대로 안해줘서 죽은거야
		// exeption이 생기자 마자 넘어가므로
		// 오류 밑의 값은 출력은 안된다.
		// 사용 메서드의 온라인 검색으로 
		// 오류를 알 수 있다. 
		// 에러에 대해 try catch 문으로 만들어 보면 좋다.
	}
	
	catch (out_of_range& e) {
		cout << "me : " << e.what() << endl;
		// 다중 캐치문을 사용하면 
		// 여기서 잡히고 밑에거까지는 실행되지 않는다.
		// 원하는 exeption에 따른 캐치문을 써주면된다.
	}

	catch (length_error& e) {
		cout << "me : " << e.what() << endl;
		// resize 에 대한 에러 처리
	}
	
	catch (exception& e) {
		// 모든 에러를 잡아준다.
		// 복사없이 들어오게 해주는 레퍼런스 참조
		
		cout << e.what() << endl;
		// invalid vector subscript
		// 를 출력해준다.
		// 여기서 exeption 처리를 해주기 때문에
		// 아래의 program ended를 출력해준다.
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
	class template ==> class 보다 상위개념
	: class template --> class 
	: class ---> object, instance
*/

// 내가 쓴 에러난 코드 고쳐보기

//template <typename T>
//// 멤버 변수의 자료형을 마음대로 바꿀 수 있다.
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
//	// c++ 등..
//
//
//	vector<int> v = { 1,2,3,4,5 };
//	// 벡터는 클래스 템플릿
//	// vector<int> -> 하면 클래스 v는 그걸로 만들어진 객체
//
//	// 1단계 : int 를 데이터로 갖는 class를 
//	// class template으로부터 만듦
//	// 2단계 : 만들어진 class Box<int> 로 부터 객체를 만든다.
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

// 돌아가는 동교코드 한번 보기

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
	vector<int> <-- 대표적인 예시

	1. container
	데이터를 담아둔다...
	담아두는 모든것을 컨테이너라고 한다.
	vector, list, queue, stack, priority queue, set, map...
	set -> 중복을 허용하지 않는 데이터들의 집합
	map -> c언어의 해시테이블 mapping의 줄임말

	2. iterator
	반복자 -> contain 안에 넣고 하나씩 꺼내보고 싶을때 쓰는거 


	3. algorithm
	find, sort, reverse, remove, transform
	transform -> 전체에 대한 변화

	c++ 은 빨라서 시간 리밋에 잘 안걸려서 시험에 많이 씀 
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
		배열이지만 5개 넣으면 10개정도 할당 받아 놓음

		list : insertion , deletion 거의 일정 
		vector : add는 일정, insertion, deletion 은 상황에 따라 다르다
					지우고 삽입하고 등등에 대해 값들에 대한 이동 시간이 다르기 때문에
		
		list : large memory
		vector : small memory

		list : no default size
		vector : default size (늘어나는 default size가 있음)

		list : random access is not possible. at(i) --> 불가능
		vector: v.at(i) --> 배열이라 가능한것

		차이를 알고 있어야 언제 뭘 쓸지에 대해 정할 수 있음 
		list -> 속도가 느릴 수 있으니 그럴때는 vector
		vector -> 사이즈가 계속 변화가 생긴다 그럴때는 list 
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
		양방향 통행 가능한 큐
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
