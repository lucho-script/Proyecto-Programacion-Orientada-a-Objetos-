#ifndef BOMBA_H
#define BOMBA_H
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;
class Bomba {
	Clock spriteTimer,spawnTimer;
	Time spriteDuration,spawnInterval;
	Sprite s2;
	Texture tt2;
	int c=0;
	bool si=true; 
	int min_x = 100;
	int max_x = 930;
	int min_y = 150;
	int max_y = 900;
public:
	Bomba(bool if_zona);
	void actu();
	Vector2f showPosBomb();
	void draww(RenderWindow &w);
	void set_position(int x, int y);
};

#endif


