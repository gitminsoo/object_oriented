// p.302
// 陥献惟績 幻級嬢左奄

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

//
// 酔軒澗 5獣娃 鎧拭 幻球澗杏稽 拝 森舛
// 神板 5獣拭辞 12獣舛亀檎 馬蟹 幻級 呪 赤製 
// せせせせせせせせせせせせせせ
// 
//

class LunarLander {
private:
	double x, y;
	// y逐戚 暗荷稽 績
	// 薄仙 是帖
	double velocity;
	// 紗亀
	double fuel;
	// 害焼赤澗 尻戟 丞
	string status;
	Texture t1, t2;
	// 鳶渡 巷缶
	// t1 space ship t2 fire
	//Sprite* spaceship = nullptr;

	// 什原闘 匂昔斗 獄穿
	unique_ptr <Sprite> spaceship;
	// p.339 'this'pointer
	// 適掘什 照拭辞幻 紫遂馬澗 匂昔斗
	// 切奄 切重聖 亜軒徹澗 匂昔斗
	// 幻級走 省焼亀 硝焼辞 幻級嬢閃 赤製
	// 五辞球拭辞 呉獄 葵聖 郊蝦 凶
	// 
	//

	// p.337
	// 呉獄亀 疑旋 持失馬奄
	// nullptr亀 切舛 照背操亀 喫

	Sprite burst;
	// 崇送戚澗 繕唖 
	Font font;
	// 越切 肉闘
	Text text;
	// 越 啄嬢爽澗暗
	// 惟績 鉢檎雌拭 窒径鞠澗 庚切伸


public:
	LunarLander(double h, double v, double f);
	void update(double dx, double dy); // 鉢詞妊 刊硯拭 魚虞 痕馬澗 xy是帖
	void draw(RenderWindow& window);
	// 鉢檎戚 益掘波旋生稽 益形走澗 但
	~LunarLander();
	// 什凪戚什 襲 五乞軒 背薦研 是背 琶推
	// 硝焼辞 蒸蕉爽走 省製

	//void setXY(double _x, double _y)
	//{
	//	x = _x;
	//	y = _y;
	//	// 奄沙旋生稽 督虞耕斗亜 酔識 授是研 握澗陥
	//	// local parameter global去税 酔識授是研 亜遭陥
	//	// 授辞企稽 壕舛戚 喫
	//	// 酔軒亜 据馬澗 倶生稽 馬形檎
	//	this->x = _x;
	//	this->y = _y;
	//	// 戚惟 薦析 疏精 号狛


	//}
};

LunarLander::LunarLander(double h, double v, double f)
{
	// space ship image to texture
	t1.loadFromFile("images/spaceship.png");
	//spaceship = new Sprite(); // new delete type

	// 什原闘 匂昔斗澗 梓端艦亜 五社球 戚遂
	spaceship.reset(new Sprite());

	spaceship->setTexture(t1);
	this->x = 500;
	// this pointer税 紫遂


	y = 200.0;
	spaceship->setPosition(x, y);
}
LunarLander::~LunarLander() {
	//delete spaceship;
}

void LunarLander::update(double dx, double dy)
{
	// x & y change shen press up,down,right,left key
	// each value is 10 -10 10 -10
	x += dx;
	y += dy;
	spaceship->setPosition(x, y);
}

void LunarLander::draw(RenderWindow& window)
{
	window.draw(*spaceship);
	// 什凪戚什 襲戚 匂昔斗稽 郊餓艦
	// 巨 傾遁訓縮聖 是背 *聖 細績
}

int main()
{
	// 酔爽識戚 馬悪 馬澗汽 
	// 徹左球 鉢詞妊 徹研 戚遂背 臣虞亜澗 覗稽益轡

	// 惟績戚 蟹展蟹澗 但 幻級奄
	RenderWindow window(VideoMode(1025, 475), "Luna Lander");
	window.setFramerateLimit(60);
	// FPS 妊獣 
	// 掻推廃 戚政 
	// 巷廃 欠苧亜 亀澗 紗亀研 走舛背捜
	// 益掘辞 段雁 60腰幻 鋼差庚聖 宜惟 背捜
	// 左搭 60戚檎 中歳
	//

	Texture t; // 巷缶 鳶渡 // 什覗虞戚闘 是拭 益形走澗 鳶渡
	Sprite background; // 叔薦稽 鉢檎拭 益形走澗 推社

	t.loadFromFile("images/background.png");
	background.setTexture(t);

	// 欠覗穿拭 含 鐸建識聖 幻窮陥 
		// 0,0,0 精 紫遂馬走 省生糠稽 益撹 焼巷呪蟹 脊径
	LunarLander* lander = new(LunarLander)(0.0, 0.0, 0.0);
	// 持失切 採牽澗 号縦生稽 郊会

	unique_ptr<LunarLander> lander2(new LunarLander(0.0, 0.0, 0.0));
	// 什原闘 匂昔斗
	// 坪球研 左檎 爽昔戚 1誤 lander 2
	// 及税 持失切稽 幻級嬢遭依税 爽昔精 lander2
	// lander2 亜 敗呪亜 魁蟹檎 紫虞霜 凶 硝焼辞 蒸蕉澗 坪球亜 級嬢赤製
	// 側 限窒 切重 赤生檎 敢 渠軒闘 床澗惟 蟹製
	//

	// 制亀酔亜 伸形赤澗 疑照 段雁 60腰 
	while (window.isOpen())
	{
		Event e;
		// 虹精 戚坤闘 級嬢尽澗走 溌昔馬澗依
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) {
				window.close();
			}
		}


		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			lander->update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			lander->update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			lander->update(-10, 0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			lander->update(10, 0);

		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			lander2->update(0, -10);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			lander2->update(0, 10);

		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			lander2->update(-10, 0);

		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			lander2->update(10, 0);

		}

		// 制亀酔拭 益形遭 依戚 赤生檎 走錘陥
		window.clear();
		// 什覗虞戚闘昔 拷益虞錘球研 益鍵陥. 
		window.draw(background);

		lander->draw(window);
		lander2->draw(window);

		window.display();

		Sleep(100);
		//100ms. delay
	}

	delete lander;

	return 0;
}