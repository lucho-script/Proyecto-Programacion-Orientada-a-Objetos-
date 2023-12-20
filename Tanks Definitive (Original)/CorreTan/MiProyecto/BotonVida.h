#ifndef BOTONVIDA_H
#define BOTONVIDA_H
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
using namespace std;
using namespace sf;
class BotonVida {
	Clock spriteTimer,spawnTimer;
	Time spriteDuration,spawnInterval;
	Sprite s2;
	Texture tt2;
public:
	BotonVida();
	void actu();
	Vector2f showPosVida();
	void draww(RenderWindow &w);
	void newPosition();
};

#endif

