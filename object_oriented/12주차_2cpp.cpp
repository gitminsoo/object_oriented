/*
	
*/

#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main1() {

	/*
		vector, list , dequeue

		set , map 
	*/

	set<int> my_set;

	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(2);
	// 중복을 허용하지 않기 때문에 마지막 2는 들어가지 않음

	// iterator
	for (auto it = my_set.begin(); it != my_set.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;

	for (auto& e : my_set)
	{
		cout << e << endl;
	}

	return 0;
}

int main2() {

	// map -> hash table ==>(key, value)
	// 검색 짱

	// p.620
	// key 와 value 의 type을 각각 지정

	map<string, int> my_map;

	my_map["john"] = 20;
	my_map["tom"] = 19;

	cout << "john's age : " << my_map["john"] << endl;
	cout << "tom's age : " << my_map["tom"] << endl;


	return 0;
}

int main3() {

	/*
		 p.626 container adapter
		 stack
		 stl의 stack은 좀 다름 
		 vector와 list를 stack이라는 포장지를 씌우는거임 
		 그래서 하나의 입출구만 사용 

		 어댑터의 역할로 사용되기 때문

		 그래서 
		 stack, queue, priority queue 도 다 adapter로 제공
		 container가 아님 

		 동작만 바꿔주는 것 

		 #include <stack>
		 #include <queue>

		 기본적으로는 vector로 구성
	*/
	
	//stack<int> my_stack; // vector로 구현된 stack
	stack<int,list<int>> my_stack; // list 로 구현 가능 
	// vector를 많이 선호

	my_stack.push(10);
	my_stack.push(20);
	my_stack.push(30);

	cout << my_stack.size() << endl;
	// element 의 갯수 

	cout << my_stack.top() << endl;
	// pop을 하지는 않고 
	// 맨위의 값을 보여줌 

	my_stack.pop();
	// 맨위 삭제

	// 스택에 있는것을 모두 꺼내가며 출력
	while (my_stack.empty() == false)
	{
		cout << my_stack.top() << endl;
		my_stack.pop();
	}

	return 0;
}

int main4() {

	//queue<int, deque<int>> my_q;
	queue<int> my_q;

	my_q.push(10);
	my_q.push(20);
	my_q.push(30);

	cout << my_q.size() << endl;
	cout << my_q.front() << endl; // 맨 앞에 있는것
	cout << my_q.back() << endl; // 맨 뒤에 있는 것

	while (my_q.empty() == false)
	{
		cout << my_q.front() << endl;
		my_q.pop();
	}


	return 0;
}

template <typename T>
class MyCompare {
public:
	bool operator() (T a, T b) {
		if (a > b)
		{
			// 이거에 따라 priority가 달라짐
			return true;
		}
		return false;
	}
};

int main5() {

	//priority_queue<int, vector<int>> pq;
	//priority_queue<int> pq;
	priority_queue<int,vector<int>,MyCompare<int>> pq;


	pq.push(10);
	pq.push(20);
	pq.push(30);

	while (pq.empty() == false) {
		cout << pq.top() << endl;
		pq.pop();
		// 기본적인 순서는 순서가 큰 순서
	}


	return 0;
}

/*
	STL : container , iterator , algorithm

	Algorithm 
		: find
		: count_if : 조건을 만족하는 것의 갯수
		: copy : 복사하기
		: reverse : 순서 뒤집기
		: sort : 정렬 , 기본은 오름차순
		: for_each : 각 요소에 함수 적용
*/

bool my_condition(string s)
{
	// 템플릿으로 만들어보기

	if (s.length() >= 6) {
		return true;
	}
	else
	{
		return false;
	}

}

int main6() {

	vector<string> myf = { "사과","바나나","토마토","배" };
	// 한글은 한글자에 2바이트

	// 토마토가 있는지 확인해 보자
	// 1. 검색 범위 지정
	//		[A,B) 의 범위 => A는 범위 포함 B는 포함 안함 
	// 2. 찾고자 하는 것

	//auto it = find(myf.begin(), myf.end(), "토마토");

	auto it = find_if(myf.begin(), myf.end(),my_condition);
	// 뒤에 함수를 넣고 그게 true인 애를 찾음
	// 맨 앞에 있는 한개만 찾음


	if (it == myf.end()) {
		cout << "없는뎅??" << endl;
	}
	else {
		cout << "찾았당 " << *it << endl;
	}

	return 0;
}

bool my_str_sort(string s1, string s2)
{
	if (s1 < s2)
	{
		// 이게 기본적인 오름차순
		// 앞에게 뒤보다 작다 하면 기본적인 오름차순
		// 클래스를 비교하고 싶으면 직접 만들어야 함
		return true;
	}
	return false;
}

int main7() {

	vector<string> myf = { "사과","바나나","토마토","배" };

	sort(myf.begin(), myf.end(), my_str_sort);
	// 정말 원본을 바꾸므로 주의

	for (auto& e : myf) {
		cout << e << endl;
	}

	return 0;
}

void my_func(string s)
{
	cout << "문자열 : " << s << endl;
}

int main8() {

	vector<string> myf = { "사과","바나나","토마토","배" };

	//for_each(myf.begin(), myf.end(), my_func);
	// 각각에 대한 요소에 함수를 적용한다.

	sort(myf.begin(), myf.end(), my_str_sort);

	for (auto& e : myf) {
		cout << e << endl;
	}


	reverse(myf.begin(), myf.end());
	// 리버스는 그 자체를 역순으로 바꾸어주므로 
	// 정렬 후 리버스 하면 굳이 뒤에 함수 안넣어 줘도
	// 내림차순 정렬이 됨

	for (auto& e : myf) {
		cout << e << endl;
	}


	return 0;
}

bool my_my_func(int i) {

	if (i % 2 == 0) {
		return true;
	}
	else
	{
		return false;
	}

}

int main() {

	/*
		p.640
		Lamda function == Lamda expression

		자바 파이썬에도 많이 씀 

		=> 무명씨
		=> 작자미상

		함수는 기본적으로 이름을 가지는데 
		그걸 안가지는 함수 
	*/

	vector<int> numbers = { 1,2,3,4,5 };

	auto count = count_if(numbers.begin(), numbers.end(), my_my_func);
	cout << "일반 함수 갯수 세기 : " << count << endl;
	// 근데 my_my_func 를 한번만 쓰면 굳이 함수를 만들어야 할까?

	auto count2 = count_if(numbers.begin(), numbers.end(),
		[](int x) {
			if (x % 2 == 0)return true;
			else return false;
		});
	cout << "일반 함수 갯수 세기 : " << count << endl;
	// [] <- 이름이 없는 함수를 나타냄
	// 그 뒤는 인수, 그 뒤는 함수 본체이다.
	// 일회용 함수라고 생각하면 좋다.
	// return 은 타입 추론인데 써주고 싶으면 [](인수)->(변환형){} 
	// 이렇게 사이에 써주면 됨

	return 0;
}