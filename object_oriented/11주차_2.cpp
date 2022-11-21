//
// p. 534
// 이진파일 
// binary file <=> text file, ascii file, .txt
// 
// text file : 저장 내용이 아스키 코드로 기록 
// 
// binary file : 값이 그대로 기록 
//  
//

// binary file

// stream - input stream , ouput stream

#include <iostream>
#include <fstream>

using namespace std;

int main1() {
	
	// p. 536

	int buffer[] = {10,20,30,40,50};
	char buffer_c[] = { 'a','b','c','d','e' };

	// file open
	// c : fopen, fclose
	// 객체 생성 == open
	//      소멸 == close

	ofstream os("binary.dat", ofstream::binary);
	os.write((char*)&buffer[0], sizeof(buffer));
	//os.write((char*)&buffer_c[0], sizeof(buffer_c));

	// 타입 캐스팅 유의 하기 


	return 0;
}

// 바이너리 읽기

int main2() {

	int buffer[5];

	ifstream is("binary.dat", ifstream::binary);
	is.read((char*)buffer, 20);

	for (auto& v : buffer) {
		cout << v << endl;
	}

	return 0;

}

// p.540 
// random access file 

// 순차접근 방식 : 앞에서부터 파일을 모두 읽어야 원하는 위치 도달
// 임의 접근 방식 : random access file
// 
// 내가 무엇을 읽으려는 위치까지 이동 
// 무엇을 --> 파일 포인터 
//

int main3() {

	ifstream is("binary.dat", ifstream::binary);

	int v;
	is.seekg(4, ios::beg);
	// file pointer를 옮긴다.
	// g 는 get의 약자 
	// 읽는 포인터 seekg 
	// 쓰는 포인터 seekp -> put
	// beg -> 시작점
	// 뒤의 4만큼의 바이트를 옮기면 20을 읽는다.
	//
	is.read((char*)&v, 4);
	cout << "value is : " << v << endl;

	is.seekg(4, ios::cur);

	is.read((char*)&v, 4);
	cout << "value is : " << v << endl;

	is.read((char*)&v, 4);
	cout << "value is : " << v << endl;
	is.seekg(-4, ios::end);
	// 마지막에서 4 바이트 뒤로 오니까 50을 읽음 



	return 0;
}

// p.559 
// 
// exception handling
// error handling 
//

int main4() {

	try {
		// 코딩에 집중하며 문제가 생기는 경우 
		// 에러 처리를 따로 해주기 때문에 코드 가독성이 올라감
		// 개인적으로 자바보다는 에러처리에 대해 많이 약한편 
		int person = 0;
		if (person == 0)
		{
			throw person;
		}
		else {
			throw 'c';
		}

	}
	// 다중 캐치문 , multiple exeption handling
	catch (int e) {
		cout << "Exeption catched!" << endl;
	}
	catch (char c)
	{
		cout << "Charater exeption catched!" << endl;
	}

	return 0;
}

// p.572
// 함수 template
//

//int get_max(int x, int y) {
//	if (x > y)
//	{
//		return x;
//	}
//	return y;
//}
//
//float get_max(float x, float y) {
//	if (x > y)
//	{
//		return x;
//	}
//	return y;
//}

// 함수 내용이 완전히 같은데 낭비가 심해짐

template<typename T>
// 내용이 같다면 오버로딩보다 훨씬 좋은 개념

T get_max(T x, T y) {
	if (x > y)
	{
		return x;
	}
	return y;
}

int main() {

	cout << get_max(3, 4) << endl;
	cout << get_max(3.4, 5.6) << endl;

	return 0;
}