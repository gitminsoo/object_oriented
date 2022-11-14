#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

using namespace std;
using namespace sf;


// 11. enemy class ����
class ENEMY
{
public:
	RectangleShape enemy;
	float offset_x;
	bool enemy_alive;

	ENEMY(float pos_x, float pos_y);
	void update();
	void draw(RenderWindow& _window);
};
ENEMY::ENEMY(float pos_x = 0, float pos_y = 0)
{
	enemy = RectangleShape(Vector2f(80.0f, 20.0f));
	enemy.setFillColor(Color::Magenta);
	enemy.setPosition(pos_x, pos_y);

	offset_x = 2.0f;

	enemy_alive = true;
}
void ENEMY::update()
{
	if (enemy_alive == false) {
		return;
	}
	// 10. enemy ������ ���� ����.
	Vector2f e_pos = enemy.getPosition();
	if (e_pos.x <= 0) {
		offset_x = 2.0f;
	}
	else if (e_pos.x + 80 >= 640) {
		offset_x = -2.0f;
	}

	// 9. enemy �����̱�.
	enemy.move(offset_x, 0.0f);
}
void ENEMY::draw(RenderWindow& _window)
{
	if (enemy_alive == false) {
		return;
	}
	_window.draw(enemy);
}

// 19. ����ȭ
class ENEMY_SET
{
public:
	vector<ENEMY> enemy_vec;

	ENEMY_SET(int num);
	void update();
	void draw(RenderWindow& _window);
};
ENEMY_SET::ENEMY_SET(int num = 4)
{
	for (int i = 0; i < num; i++) {
		ENEMY buf(i * 30, i * 30);
		enemy_vec.push_back(buf);
	}
}
void ENEMY_SET::update()
{
	for (int i = 0; i < enemy_vec.size(); i++) {
		enemy_vec[i].update();
	}
}
void ENEMY_SET::draw(RenderWindow& _window)
{
	for (int i = 0; i < enemy_vec.size(); i++) {
		enemy_vec[i].draw(_window);
	}
}

// 14. gun�� classȭ ��Ű��
class GUN
{
public:
	CircleShape gun;
	CircleShape bullet;
	bool bullet_alive;

	GUN();
	void update(RenderWindow& _window);
	void draw(RenderWindow& _window);
	void fire();
};
GUN::GUN()
{
	/* gun */
	gun = CircleShape(50.0f);
	gun.setFillColor(Color::Green);
	gun.setPosition(640 / 2 - gun.getRadius(), 480 - gun.getRadius());

	/* bullet */
	bullet = CircleShape(10.0f, 3);
	bullet.setFillColor(Color::Red);
	bullet.setPosition(700, 700); // �ָ� ������, �ֳĸ� �ʱ���ġ�� 0,0 �̿��� �������ʾҴµ� ���� �浹 ���ɼ� ����.
	bullet_alive = false;
}
void GUN::update(RenderWindow& _window)
{
	// 13. gun�� ���콺 ���� �����̵��� �ϱ�.
	Vector2i mouse_pos = Mouse::getPosition(_window);
	gun.setPosition(mouse_pos.x - gun.getRadius(), gun.getPosition().y);
	if (gun.getPosition().x <= 0) {
		gun.setPosition(0, gun.getPosition().y);
	}
	else if (gun.getPosition().x + (2 * gun.getRadius()) >= 640)
	{
		gun.setPosition(_window.getSize().x - 2 * gun.getRadius(), gun.getPosition().y);
	}

	if (bullet_alive == true) {
		bullet.move(0.0, -5.0f);
	}

	// bullet�� ȭ���� �ֻ�ܺο� �������� ��.
	if (bullet.getPosition().y <= 0) {
		bullet_alive = false;
	}

	// �Ǵ� enemy ��ü�� bullet ��ü�� ���� �浹���� ��.



}
void GUN::draw(RenderWindow& _window)
{
	_window.draw(gun);

	if (bullet_alive == true) {
		_window.draw(bullet);
	}

}
void GUN::fire()
{
	if (bullet_alive == true) {
		return;
	}

	bullet_alive = true;
	// gun ��ü�� �߽ɺο��� �Ѿ��� �߻� �ǵ��� ����.
	Vector2f gun_pos = gun.getPosition();
	bullet.setPosition(gun_pos.x + gun.getRadius() - bullet.getRadius(), gun_pos.y);
}

// 18. Ŭ���� ��ġ��.
class SHOOT_GAME
{
public:
	//ENEMY enemy;
	ENEMY_SET enemy_set;
	GUN gun;

	int alive_enemy_num;
	Text alive_enemy_num_text;
	Font font;

	SHOOT_GAME(int num);

	void fire();
	void update(RenderWindow& _window);
	void draw(RenderWindow& _window);
	void init_end(RenderWindow& _window, int _status = 1);
};
SHOOT_GAME::SHOOT_GAME(int num)
{
	enemy_set = ENEMY_SET(num);
	alive_enemy_num = num;

	font.loadFromFile("images/OpenSans-Bold.ttf");

	alive_enemy_num_text.setFont(font);
	alive_enemy_num_text.setCharacterSize(30);
	alive_enemy_num_text.setFillColor(Color::Magenta);
	alive_enemy_num_text.setStyle(Text::Bold);

}
void SHOOT_GAME::fire()
{
	gun.fire();
}
void SHOOT_GAME::update(RenderWindow& _window)
{
	//enemy.update();			// enemy ��ġ ������Ʈ.
	enemy_set.update();
	gun.update(_window);	// gun and bullet ��ġ ������Ʈ.

	// enemy�� gun.bullet ������ �浹�� �˻�.
	// Ȥ�� �浹�� �Ѵٸ� -> enemy �׸��� bullet �Ѵ� �������� �ʱ�.
	// �浹�� �˻��ϱ� ���� bullet�� �ٿ����, enemy�� �ٿ������ ������
	// FloatRect bulletArea = gun.getBulletArea(); // ������ �̷��� �ϴ°��� �� �� bullet ��ü�� ��ȣ�ϰ� ����������.

	FloatRect bulletArea = gun.bullet.getGlobalBounds();

	for (int i = 0; i < enemy_set.enemy_vec.size(); i++) {
		FloatRect enemyArea = enemy_set.enemy_vec[i].enemy.getGlobalBounds();

		if (bulletArea.intersects(enemyArea) == true && enemy_set.enemy_vec[i].enemy_alive == true && gun.bullet_alive == true) { // �Ѿ˰� ���� �ε�����!
			// �Ѿ� �����.
			gun.bullet_alive = false;

			// enemy �����.
			enemy_set.enemy_vec[i].enemy_alive = false;
		}
	}


	alive_enemy_num = count_if(enemy_set.enemy_vec.begin(), enemy_set.enemy_vec.end(),
		[](ENEMY e1) {
			return (e1.enemy_alive == true);
		});

	alive_enemy_num_text.setString(to_string(alive_enemy_num));
	Vector2f gun_pos = gun.gun.getPosition();
	float gun_radius = gun.gun.getRadius();
	alive_enemy_num_text.setPosition(gun_pos.x + gun_radius - 10, gun_pos.y + gun_radius - alive_enemy_num_text.getCharacterSize());

	// enemy�� �� ��������� Ȯ�� == ��� false

	for (int i = 0; i < enemy_set.enemy_vec.size(); i++) {
		if (enemy_set.enemy_vec[i].enemy_alive == true) {
			return;
		}
	}
	init_end(_window, 0);
}
void SHOOT_GAME::draw(RenderWindow& _window)
{
	//enemy.draw(_window);
	enemy_set.draw(_window);
	gun.draw(_window);
	_window.draw(alive_enemy_num_text);
}
void SHOOT_GAME::init_end(RenderWindow& _window, int _status)
{
	// * start ��ư�� draw() �ؾ���.
	//		. start ��ư ������ �� ��ü�� �����ؾ���.
	RectangleShape startBtn(Vector2f(300, 150));
	startBtn.setPosition(640 / 2 - 150, 480 / 2 - 75);
	Texture startBtnTexture;
	if (_status == 1) { // start
		startBtnTexture.loadFromFile("images/startBtn2.png");
	}
	else if (_status == 0) {
		startBtnTexture.loadFromFile("images/end.png");
	}

	startBtn.setTexture(&startBtnTexture);

	_window.clear();
	_window.draw(startBtn);
	_window.display();

	bool startSig = false;
	while (_window.isOpen()) {
		Event event;
		while (_window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed:
				_window.close();
				break;
			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left) == true) {
					// ���콺�� ��ư ��ġ���� Ŭ���ƴ��� �˻�
					Vector2i mouse_pos = Mouse::getPosition(_window);
					Vector2f btn_pos = startBtn.getPosition();
					Vector2f btn_size = startBtn.getSize();
					if (mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x) {
						if (mouse_pos.y >= btn_pos.y && mouse_pos.y <= btn_pos.y + btn_size.y) {

							startSig = true;

						}
					}
				}
				break;
			default:
				break;
			}
		}
		if (startSig == true) {
			break;
		}


	}

	// * ���콺�� start ��ư�� Ŭ���ϸ� ������ ���� �Ǿ�� ��.
	//		. ���콺 Ŀ�� Ŭ�� ��ġ�� start button ��ġ�� ���ؾ���.
}

int main()
{
	// 0. ȭ�� ���� ����.
	RenderWindow window(VideoMode(640, 480), "shoot");
	Vector2u window_sz = window.getSize();

	// 1. ȭ�� ����Ʈ ����.
	window.setFramerateLimit(120);

	SHOOT_GAME shoot_game(5);

	// 20. ���� ȭ�� �����.
	shoot_game.init_end(window);

	// 2. ȭ�� ���� ���� ���� �����.
	while (window.isOpen()) {

		// 6. window �� �̺�Ʈ ó�� ���Ϲ� �ۼ�. (close)
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left) == true) {
					shoot_game.fire();
				}
				break;

			default:
				break;
			}
		}

		/* update */
		shoot_game.update(window);

		/* 3. window clear */
		window.clear();

		/* 4. window draw */
		shoot_game.draw(window);

		/* 5. window display */
		window.display();
	}


	return 0;
}