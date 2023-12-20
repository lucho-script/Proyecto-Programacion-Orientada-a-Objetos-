#include "Disparo.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Disparo::Disparo (Vector2f pos, Vector2f dire) {
	projectile.setPosition(pos);
	projectile.setRadius(2);
	projectile.setOrigin(2,2);
	vel=dire*10.f;
	projectile.setFillColor(Color::Magenta);
}

void Disparo::actu ( ) {
	projectile.move(vel);
}

void Disparo::draww (RenderWindow & w) {
	w.draw(projectile);
}

Vector2f Disparo::see_positon ( ) {
	return projectile.getPosition();
}

bool Disparo::isOutOfBounds ( ) {
	Vector2f position = projectile.getPosition();
	return position.x < 100 || position.x > 924 || position.y < 180 || position.y > 930;
}

