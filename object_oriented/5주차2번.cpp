// p.302

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
	Sprite spaceship, burst;
	// 崇送戚澗 繕唖 
	Font font;
	// 越切 肉闘
	Text text;
	// 越 啄嬢爽澗暗

public:
	LunarLander(double h, double v, double f);
	void update(double rate);
	void draw(RenderWindow& window);
};

int main()
{
	// 酔爽識戚 馬悪 馬澗汽 
	// 徹左球 鉢詞妊 徹研 戚遂背 臣虞亜澗 覗稽益轡

	


	return 0;
}