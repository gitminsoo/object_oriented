//
// p.9
// 
// c++
// object oriented programming
// 객체지향언어
// 
// c: 고성능
// 단점 : 생산성이 매우 낮음
// 장점 : 속도 --> 10~100 배 빠름 python, java
// 메모리 절약형
// 
// c++, Bjarne Stroustrup
// 
// 코드 재사용성에 객체 자향의 개념을 도입
// 
// c --> (SIMULA) --> c++
// 단점 : 메모리 관리가 어려움
// 그래서 
// --> Java (c++ 에서 포인터를 없앰)
// --> C# (micro soft에서 Java를 견제하기 위해 만들어짐)
// 키오스크 안에 그런거는 모두 C#으로 만들어짐
// 
// p.11
// class
// ==> struct + function 
// c언어는 data처리를 위해 함수를 만듦 
// 두개가 분리가 되어 있어서 관리가 쉽지 않음 
// 두개의 객체를 합치자!! --> 핵심
// data에 data를 처리할 수 있는 function을 같이 보내는 것
// 
// inheritance
// <-- 상속
// 옷을 사러감 맘에 드는 옷에 단추만 맘에 안들어
// 그러면 다른 가게 가?? --> c언어
// 아 몰랑 옷은 이거 주시고요 단추는 다른거로 주세요 --> 상속
// 기존에 있던 클래스에 일부분을 바꾸는 것 
// 
// polymorphism 
// operator overloading
// 
// reference type
// <-- pointer 대체제
// pointer의 위험성을 줄일 수 있음
// 
// standard library
// <-- 데이터 구조시간에 배운 그러한 구조를 그냥 불러서 쓸 수 있음
// 
// new, delete
// <-- malloc free 보다 안전한 버전
// 
// generic
// <- type 
// c언어에서 정수 두개받아 합을 반환하는 함수가 있다
// 근데 float형도 필요하면 따로 만들어야 한다 
// generic은 하나만 만들고 그때그때 type을 알아서 바꿀 수 있다
// 
// p.16
// 
// 절차지향, 객체지향
// c , c++
//

// p.34

// #include <stdio.h> // printf, scanf
//#include <iostream> // c++전용은 .h가 없음
//
//using namespace std;
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	// cout console out --> 화면창에 보여지는 길 
//	// 물길이 흘러서 console out 으로 나감
//	// endl은 end of line --> 줄바꿈표시 ==\n
//
//	// std는 뭐야
//	// printf scanf를 썼다.
//	// namespace 나와바리의 개념
//	// c++은 명령어에서 다른사람과 충돌이 생길 수 있다. 
//	// 그래서 성을 붙여주자 그게 namespace
//	// 위 코드의 namespace는 성이다 ::은 그걸 가르키는 것
//	// std가문 안에 있는 cout이다 
//	// std가문 안에 있는 endl이다 
//	// 어떤 문제가 생겼을까요
//	// std:: 하니까 손이 아파
//	//
//	//그래서
//	// 위에 using namespace std;
//
//	cout << "hello world"<< endl;
//
//	return 0;
//}


// p.39
// 변수와 자료형
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
// c++ 추가형 
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

// 문자열형 : string

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
//	// 문자열 비교 
//
//	const int k = 10;
//	cout << s1 + to_string(k) + s2 << endl;
//	// 숫자를 문자열로 바꾸어주는 것 
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
	// 자료형 자동 지정
	// 근데 안하는게 좋음 
	// 함부러 쓰는게 아니라 잠깐 쓰고 마는거에만 쓰는거 

	return 0;
}