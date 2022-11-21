//
// p. 534
// �������� 
// binary file <=> text file, ascii file, .txt
// 
// text file : ���� ������ �ƽ�Ű �ڵ�� ��� 
// 
// binary file : ���� �״�� ��� 
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
	// ��ü ���� == open
	//      �Ҹ� == close

	ofstream os("binary.dat", ofstream::binary);
	os.write((char*)&buffer[0], sizeof(buffer));
	//os.write((char*)&buffer_c[0], sizeof(buffer_c));

	// Ÿ�� ĳ���� ���� �ϱ� 


	return 0;
}

// ���̳ʸ� �б�

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

// �������� ��� : �տ������� ������ ��� �о�� ���ϴ� ��ġ ����
// ���� ���� ��� : random access file
// 
// ���� ������ �������� ��ġ���� �̵� 
// ������ --> ���� ������ 
//

int main3() {

	ifstream is("binary.dat", ifstream::binary);

	int v;
	is.seekg(4, ios::beg);
	// file pointer�� �ű��.
	// g �� get�� ���� 
	// �д� ������ seekg 
	// ���� ������ seekp -> put
	// beg -> ������
	// ���� 4��ŭ�� ����Ʈ�� �ű�� 20�� �д´�.
	//
	is.read((char*)&v, 4);
	cout << "value is : " << v << endl;

	is.seekg(4, ios::cur);

	is.read((char*)&v, 4);
	cout << "value is : " << v << endl;

	is.read((char*)&v, 4);
	cout << "value is : " << v << endl;
	is.seekg(-4, ios::end);
	// ���������� 4 ����Ʈ �ڷ� ���ϱ� 50�� ���� 



	return 0;
}

// p.559 
// 
// exception handling
// error handling 
//

int main4() {

	try {
		// �ڵ��� �����ϸ� ������ ����� ��� 
		// ���� ó���� ���� ���ֱ� ������ �ڵ� �������� �ö�
		// ���������� �ڹٺ��ٴ� ����ó���� ���� ���� ������ 
		int person = 0;
		if (person == 0)
		{
			throw person;
		}
		else {
			throw 'c';
		}

	}
	// ���� ĳġ�� , multiple exeption handling
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
// �Լ� template
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

// �Լ� ������ ������ ������ ���� ������

template<typename T>
// ������ ���ٸ� �����ε����� �ξ� ���� ����

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