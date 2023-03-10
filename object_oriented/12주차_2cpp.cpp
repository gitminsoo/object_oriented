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
	// �ߺ��� ������� �ʱ� ������ ������ 2�� ���� ����

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
	// �˻� ¯

	// p.620
	// key �� value �� type�� ���� ����

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
		 stl�� stack�� �� �ٸ� 
		 vector�� list�� stack�̶�� �������� ����°��� 
		 �׷��� �ϳ��� ���ⱸ�� ��� 

		 ������� ���ҷ� ���Ǳ� ����

		 �׷��� 
		 stack, queue, priority queue �� �� adapter�� ����
		 container�� �ƴ� 

		 ���۸� �ٲ��ִ� �� 

		 #include <stack>
		 #include <queue>

		 �⺻�����δ� vector�� ����
	*/
	
	//stack<int> my_stack; // vector�� ������ stack
	stack<int,list<int>> my_stack; // list �� ���� ���� 
	// vector�� ���� ��ȣ

	my_stack.push(10);
	my_stack.push(20);
	my_stack.push(30);

	cout << my_stack.size() << endl;
	// element �� ���� 

	cout << my_stack.top() << endl;
	// pop�� ������ �ʰ� 
	// ������ ���� ������ 

	my_stack.pop();
	// ���� ����

	// ���ÿ� �ִ°��� ��� �������� ���
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
	cout << my_q.front() << endl; // �� �տ� �ִ°�
	cout << my_q.back() << endl; // �� �ڿ� �ִ� ��

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
			// �̰ſ� ���� priority�� �޶���
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
		// �⺻���� ������ ������ ū ����
	}


	return 0;
}

/*
	STL : container , iterator , algorithm

	Algorithm 
		: find
		: count_if : ������ �����ϴ� ���� ����
		: copy : �����ϱ�
		: reverse : ���� ������
		: sort : ���� , �⺻�� ��������
		: for_each : �� ��ҿ� �Լ� ����
*/

bool my_condition(string s)
{
	// ���ø����� ������

	if (s.length() >= 6) {
		return true;
	}
	else
	{
		return false;
	}

}

int main6() {

	vector<string> myf = { "���","�ٳ���","�丶��","��" };
	// �ѱ��� �ѱ��ڿ� 2����Ʈ

	// �丶�䰡 �ִ��� Ȯ���� ����
	// 1. �˻� ���� ����
	//		[A,B) �� ���� => A�� ���� ���� B�� ���� ���� 
	// 2. ã���� �ϴ� ��

	//auto it = find(myf.begin(), myf.end(), "�丶��");

	auto it = find_if(myf.begin(), myf.end(),my_condition);
	// �ڿ� �Լ��� �ְ� �װ� true�� �ָ� ã��
	// �� �տ� �ִ� �Ѱ��� ã��


	if (it == myf.end()) {
		cout << "���µ�??" << endl;
	}
	else {
		cout << "ã�Ҵ� " << *it << endl;
	}

	return 0;
}

bool my_str_sort(string s1, string s2)
{
	if (s1 < s2)
	{
		// �̰� �⺻���� ��������
		// �տ��� �ں��� �۴� �ϸ� �⺻���� ��������
		// Ŭ������ ���ϰ� ������ ���� ������ ��
		return true;
	}
	return false;
}

int main7() {

	vector<string> myf = { "���","�ٳ���","�丶��","��" };

	sort(myf.begin(), myf.end(), my_str_sort);
	// ���� ������ �ٲٹǷ� ����

	for (auto& e : myf) {
		cout << e << endl;
	}

	return 0;
}

void my_func(string s)
{
	cout << "���ڿ� : " << s << endl;
}

int main8() {

	vector<string> myf = { "���","�ٳ���","�丶��","��" };

	//for_each(myf.begin(), myf.end(), my_func);
	// ������ ���� ��ҿ� �Լ��� �����Ѵ�.

	sort(myf.begin(), myf.end(), my_str_sort);

	for (auto& e : myf) {
		cout << e << endl;
	}


	reverse(myf.begin(), myf.end());
	// �������� �� ��ü�� �������� �ٲپ��ֹǷ� 
	// ���� �� ������ �ϸ� ���� �ڿ� �Լ� �ȳ־� �൵
	// �������� ������ ��

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

		�ڹ� ���̽㿡�� ���� �� 

		=> ����
		=> ���ڹ̻�

		�Լ��� �⺻������ �̸��� �����µ� 
		�װ� �Ȱ����� �Լ� 
	*/

	vector<int> numbers = { 1,2,3,4,5 };

	auto count = count_if(numbers.begin(), numbers.end(), my_my_func);
	cout << "�Ϲ� �Լ� ���� ���� : " << count << endl;
	// �ٵ� my_my_func �� �ѹ��� ���� ���� �Լ��� ������ �ұ�?

	auto count2 = count_if(numbers.begin(), numbers.end(),
		[](int x) {
			if (x % 2 == 0)return true;
			else return false;
		});
	cout << "�Ϲ� �Լ� ���� ���� : " << count << endl;
	// [] <- �̸��� ���� �Լ��� ��Ÿ��
	// �� �ڴ� �μ�, �� �ڴ� �Լ� ��ü�̴�.
	// ��ȸ�� �Լ���� �����ϸ� ����.
	// return �� Ÿ�� �߷��ε� ���ְ� ������ [](�μ�)->(��ȯ��){} 
	// �̷��� ���̿� ���ָ� ��

	return 0;
}