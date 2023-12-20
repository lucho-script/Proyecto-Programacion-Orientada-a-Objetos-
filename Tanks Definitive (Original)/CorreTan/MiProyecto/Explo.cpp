#include "Explo.h"
using namespace sf;
using namespace std;
Explo::Explo(bool muestra,Time lifetime) {
	if (muestra) {
		t.loadFromFile("Texture/explo1.png");
		
	}
	
	spriteDuration = seconds(0.028); // Ajusta el tiempo entre fotogramas (menor duración)
	spriteTimer.restart(); // Reinicia el temporizador
	x = 0; // Reinicia la posición x de los fotogramas
	y = 0; 
	active = false;// Reinicia la posición y de los fotogramas
	this->lifetime = lifetime;  // Configurar el tiempo máximo de vida
	activeTimer.restart();  // Iniciar el temporizador de vida
	music.openFromFile("Audio/explo.ogg");
	music.setVolume(15);
	
}
void Explo::activate() {
	active = true;
	spriteTimer.restart();
	activeTimer.restart();
	music.play();
	
}
bool Explo::isFinished() const {
	return !active || activeTimer.getElapsedTime() >= lifetime;
}
void Explo::actu(Vector2f pos_tank) {
	music.stop(); 
	s.setPosition(pos_tank);
	s.setOrigin(39,39);
	if (spriteTimer.getElapsedTime() >= spriteDuration) {
		s.setTexture(t);
		if (x == 6.5) {
			x = 0;
			if (y == 6.5) {
				y = 0;
			}
			y += 1.3;
		}
		x += 1.3;
		
		spriteTimer.restart(); 
	}
	
	s.setTextureRect(sf::IntRect(x * 78, y * 78, 92, 95));
}

void Explo::draww(RenderWindow& w) {
	if(active) {
		w.draw(s);
	}
}
