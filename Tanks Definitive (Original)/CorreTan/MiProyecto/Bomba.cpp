#include "Bomba.h"
#include <tuple>
using namespace std;
Bomba::Bomba(bool if_zona):si(if_zona) {
	if(si){
		///ZONA
		spriteDuration = seconds(3); 
		spriteTimer.restart();
		spawnInterval = seconds(3);
		spawnTimer.restart();
		tt2.loadFromFile("Texture/peligro.png");
	}else{
		///PARED
		tt2.loadFromFile("Texture/pared.png");
	}
}

void Bomba::actu ( ) {
	if(si){
		///ZONA
		if (spawnTimer.getElapsedTime() >= spawnInterval) {
			int x = rand() % (max_x - min_x) + min_x;
			int y = rand() % (max_y - min_y) + min_y;
			
			s2.setPosition(x, y);
			
			spawnTimer.restart();
			s2.setTexture(tt2);
			spriteTimer.restart(); 
			++c;
			if(c==10){
				spriteDuration=seconds(2);  
				spawnInterval=seconds(2);
			}else{
				if(c==20){
					spriteDuration=seconds(1);
					spawnInterval=seconds(1);
				}
			}
		}
		if (spriteTimer.getElapsedTime() >= spriteDuration) {
			s2.setTextureRect(IntRect(0, 0, 0, 0));
		}
	}else{
		s2.setTexture(tt2);
		s2.setOrigin(32,32);
	}
	
}
Vector2f Bomba::showPosBomb ( ) {
	return s2.getPosition();
	
}
void Bomba::draww (RenderWindow & w) {
	w.draw(s2);
}

void Bomba::set_position (int x, int y) {
	s2.setPosition(x,y);
}

