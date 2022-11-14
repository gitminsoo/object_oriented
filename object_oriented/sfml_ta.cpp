#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

using namespace std;
using namespace sf;


// 11. enemy class 정의
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
	// 10. enemy 움직일 방향 설정.
	Vector2f e_pos = enemy.getPosition();
	if (e_pos.x <= 0) {
		offset_x = 2.0f;
	}
	else if (e_pos.x + 80 >= 640) {
		offset_x = -2.0f;
	}

	// 9. enemy 움직이기.
	enemy.move(offset_x, 0.0f);
}
void ENEMY::draw(RenderWindow& _window)
{
	if (enemy_alive == false) {
		return;
	}
	_window.draw(enemy);
}

// 19. 벡터화
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

// 14. gun을 class화 시키기
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
	bullet.setPosition(700, 700); // 멀리 던져놔, 왜냐면 초기위치가 0,0 이여서 쏘지도않았는데 적과 충돌 가능성 있음.
	bullet_alive = false;
}
void GUN::update(RenderWindow& _window)
{
	// 13. gun을 마우스 따라서 움직이도록 하기.
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

	// bullet이 화면의 최상단부에 도달했을 때.
	if (bullet.getPosition().y <= 0) {
		bullet_alive = false;
	}

	// 또는 enemy 객체와 bullet 객체가 서로 충돌했을 때.



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
	// gun 객체의 중심부에서 총알이 발사 되도록 구현.
	Vector2f gun_pos = gun.getPosition();
	bullet.setPosition(gun_pos.x + gun.getRadius() - bullet.getRadius(), gun_pos.y);
}

// 18. 클래스 합치기.
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
	//enemy.update();			// enemy 위치 업데이트.
	enemy_set.update();
	gun.update(_window);	// gun and bullet 위치 업데이트.

	// enemy와 gun.bullet 사이의 충돌을 검사.
	// 혹시 충돌을 한다면 -> enemy 그리고 bullet 둘다 보여주지 않기.
	// 충돌을 검사하기 위해 bullet의 바운더리, enemy의 바운더리를 얻어야함
	// FloatRect bulletArea = gun.getBulletArea(); // 원래는 이렇게 하는것이 좀 더 bullet 객체를 보호하고 안전하지만.

	FloatRect bulletArea = gun.bullet.getGlobalBounds();

	for (int i = 0; i < enemy_set.enemy_vec.size(); i++) {
		FloatRect enemyArea = enemy_set.enemy_vec[i].enemy.getGlobalBounds();

		if (bulletArea.intersects(enemyArea) == true && enemy_set.enemy_vec[i].enemy_alive == true && gun.bullet_alive == true) { // 총알과 적이 부딪혔다!
			// 총알 지우기.
			gun.bullet_alive = false;

			// enemy 지우기.
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

	// enemy가 다 사라졌는지 확인 == 모두 false

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
	// * start 버튼을 draw() 해야함.
	//		. start 버튼 역할을 할 객체를 정의해야함.
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
					// 마우스가 버튼 위치에서 클릭됐는지 검사
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

	// * 마우스로 start 버튼을 클릭하면 게임이 시작 되어야 함.
	//		. 마우스 커서 클릭 위치와 start button 위치를 비교해야함.
}

int main()
{
	// 0. 화면 변수 선언.
	RenderWindow window(VideoMode(640, 480), "shoot");
	Vector2u window_sz = window.getSize();

	// 1. 화면 레이트 설정.
	window.setFramerateLimit(120);

	SHOOT_GAME shoot_game(5);

	// 20. 시작 화면 만들기.
	shoot_game.init_end(window);

	// 2. 화면 띄우는 무한 루프 만들기.
	while (window.isOpen()) {

		// 6. window 내 이벤트 처리 와일문 작성. (close)
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