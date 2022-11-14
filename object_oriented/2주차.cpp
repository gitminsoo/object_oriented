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
//	// 콘솔로 나가는 방향
//	//
//
//	cout << "입력할 숫자를 넣으세요" << endl;
//
//	int i;
//	cin >> i;
//	// cin 을 통해i로 들어가는 방향
//	cout << "입력한 숫자는 " + to_string(i) + " 입니다." << endl;
//
//	return 0;
//}


int main()
{
	// p.49 연산자
	// + - * / %

	// p.65
	// 제어구조
	// 관계연산자 relational operator
	// == != < > <= >=
	// c언어에서는 1 or 0 의 결과가 나온다
	// c++ 은 이 결과가 bool 형태로 나온다
	//
	
	//bool b;
	//b = (1 == 2);
	//cout << b << endl;
	//// 이렇게 하면 숫자 0이 나옴
	//cout << boolalpha;
	//cout << b << endl;
	//// 위의 문단을 적어주면 
	//// bool 타입은 알파벳으로 써줘라
	//cout << noboolalpha;
	//cout << b << endl;
	//// 이렇게 하면 다시 숫자로 나옴

	// p.66 논리연산자
	// && || !

	// p.68
	// if else
	// c언어랑 똑같이 쓰면 됨
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
	//	cout << "입력문자는 " + str << endl;*/

	//	/*getline(cin, str);
	//	cout << "입력문자는 " + str << endl;*/

	//	// c언어의 strcat 의 역할을 해준다 
	//	// 입력 중간에 스페이스를 주면 한 단어씩 끊겨서 저장된다
	//	// cin의 한계
	//	// 공백을 \n 으로 인식한다.
	//	// 문장 인식은 cin을 사용할 수 없다.
	//	// 그래서 getlie() 함수를 사용해준다
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

	//	// auto 는 안쓰는게 좋지만
	//	// 여기처럼 쓰고 버리는거는 auto로
	//	// 짜는게 나음
	//	// auto 를 적재적소에 사용하는게 주요점

	//	break;
	//	// 자신과 가장 가까운 for 탈출
	//	continue;
	//	// 가장 가까운 for의 다음 for로 넘어간다
	//}


	// p.95
	//int a[5] = { 1,2,3,4,5 };
	//int b[] = { 1,2,3,4,5 };
	//int c[]{ 1,2,3,4,5 };
	//// --> c 가 c++스타일
	//// 배열도 객체다 라는 뜻을 가지고 이렇게 한다
	//// 교수님은 그냥 a처럼 쓴다.
	//// 모두 같은 뜻

	//int d[10] = { 1, };
	//// 맨 앞은 1 나머지는 all zero

	//string names[3] = { "tom","jane","james" };
	//// 기적이야... c언어로 가능하겠어?? 힘들거든,,,
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
		// 이렇게 하나씩 꺼낼 수 있다.
		// (auto i=0;i<5;i++) 의 조건과 같은 문장
		cout << i << endl;
	}
	string names[] = { "tom","jane","james" };
	for (auto i : names)
	{
		// 오.. 문자열을 이렇게 다룬다...?
		cout << i << endl;
	}


	for (int& i : num) {
		// int& --> & 뺴면 2배가 되지 않음
		// 
		// pointer type int* i;
		// 
		// 포인터의 위험성 ==> 옆집을 가는 경우가 있음
		// 그래서 자바는 포인터를 없애고
		// c++은 reference type이 생김
		// -- int& i;
		// int j = 100;
		// int& i = j;
		// i=200;
		// 이렇게 만들면 j가 200이된다
		// 같은 메모리에 다른 이름을 붙여서 접근이 가능하게 한다
		// 
		// 조금더 보기
		// 포인터보다 훨씬 안전함
		// 공부해보기
		// 
		i = 2 * i;
	}
	for (int /*auto*/ i : num)
	{
		cout << i << endl;
	}

}



//__________________________________
// 예제문제 <주사위>
 
//#include <cstdlib>
//// rand, srand
//
//int main()
//{
//	// 주사위 시뮬레이션으로 1 1 이 나올 확률을 구해라
//	// c++ 함수 사용
//	// cplusplus.com reference 에서 찾아서 사용
//	// 위에 검색 후 헤더파일 보는게 중요
//
//	int cnt = 0;
//	// 1,1이 나오는 숫자
//	srand(3000);
//	cout << "rand max is " << RAND_MAX << endl;
//
//	for (auto i = 0; i < 10000; i++)
//	{
//		int k1 = rand() % 6 + 1;
//		// 주사위 숫자가 0이 없으니까
//		int k2 = rand() % 6 + 1;
//		if ((k1 == 1) && (k2 == 1))
//		{
//			cnt++;
//		}
//
//	}
//	cout << "10000 번 중 " << cnt << " 번 나옴" << endl;
//
//}

//__________________________________