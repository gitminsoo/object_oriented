// p.302

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

//
// �츮�� 5�ð� ���� ����°ɷ� �� ����
// ���� 5�ÿ��� 12�������� �ϳ� ���� �� ���� 
// ����������������������������
// 
//

class LunarLander {
private:
	double x, y;
	// y���� �Ųٷ� ��
	// ���� ��ġ
	double velocity;
	// �ӵ�
	double fuel;
	// �����ִ� ���� ��
	string status;
	Texture t1, t2;
	Sprite spaceship, burst;
	// �����̴� ���� 
	Font font;
	// ���� ��Ʈ
	Text text;
	// �� ����ִ°�

public:
	LunarLander(double h, double v, double f);
	void update(double rate);
	void draw(RenderWindow& window);
};

int main()
{
	// ���ּ��� �ϰ� �ϴµ� 
	// Ű���� ȭ��ǥ Ű�� �̿��� �ö󰡴� ���α׷�

	


	return 0;
}