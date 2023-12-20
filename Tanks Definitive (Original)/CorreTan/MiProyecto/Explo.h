#ifndef EXPLO_H
#define EXPLO_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;
class Explo {
	Texture t;
	Sprite s; 
	Clock spriteTimer,activeTimer;
	Time spriteDuration,lifetime;
	float x=0,y=0;
	bool active;
	Music music;
public:
	Explo(bool muestra,Time lifetime);
	void actu(Vector2f pos_tank);
	void draww(RenderWindow &w);
	void activate();
	bool isFinished() const;
};

#endif

