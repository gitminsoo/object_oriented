//
// include ���� : Ŭ����, function declaration ����
//                Ŭ���� definition ����
// 
// lib ���� : Ŭ����, �Լ� ���� �ҽ��ڵ��� ������ �����
//            ���̳ʸ� �ڵ带 �ѵ� ���� ���� �� 
//            ---> ���� �ۼ��� �ڵ�� ���� ������ link 
// 
// ����� ������ 
// --> �ٸ� �̿��ڵ� sfml �̿�� �� ���α׷� �ȿ� 
// sfml �ߺ� -> �޸� �ߺ� 
// �ٸ� ���� sfml ���׷��̵� �� 
// �ٸ� �ֵ��� ��ũ�� �ٽ� �ؾ� �ϴ� ������ �߻�
// 
// �̹������� �ذ��ϰ��� ���°� dll �̶�� ���� 
// dynamically linked library
// �ݴ� ������ statically linked library
// 
// DLL
// �������� ������ ��ũ ������ 
// �̰��� �ϳ��� sfml ���� �̿��ϸ� 
// ã�ư��� �ּ��� ������ ����
// ������Ʈ�� sfml �ϳ��� �ϸ� ��
// 
// �� dll ���� bin �� ������
// bin ���� �ֵ鵵 ����
// 
// sll �� �ٸ� ������ ���� �������� ��� ���ϴٴ� ����
// (���� ���� ��)
// 
//

// p.293
//

#include <SFML/Graphics.hpp>
using namespace sf;

//å
//3�� ������� ��
//sfml - graphics
//system
//window
//
//- d �� ������ ����
//- d �����ŷ� �ϴ°� ����
//����� ���
//�Ⱥ����� ������ ���

int main()
{
	RenderWindow window(VideoMode(200, 200), "First Example");
	// ȭ�� â�� ũ�� 200,200 (����,����)
	// renderwindow�� ������ ȣ��

	CircleShape shape(100.0f);
	shape.setFillColor(Color::Green);

	while (window.isOpen())
	{
		Event e;

		while (window.pollEvent(e)) {
			// poll �� �̺�Ʈ �˻� �ϴ°�
			// e�� ��Ƽ� �˷��ַ�
			if (e.type == Event::Closed) {
				// �ǵ���� e �� ���� �Ѿ��
				// �̺�Ʈ Ÿ���� â��ħ ��ư ������ 
				window.close();
				// ������ �ݾ� ����
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	return 0;
}
