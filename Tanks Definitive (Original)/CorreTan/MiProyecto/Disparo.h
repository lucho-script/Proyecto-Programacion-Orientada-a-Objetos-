#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class Disparo {
	CircleShape projectile;
	Vector2f vel;
public:
	Disparo(Vector2f pos,Vector2f dire);
	void actu();
	void draww(RenderWindow &w);
	Vector2f see_positon();
	bool isOutOfBounds();
};

#endif

