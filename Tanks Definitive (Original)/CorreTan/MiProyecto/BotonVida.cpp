#include "BotonVida.h"
#include <vector>
#include <cstdlib>
using namespace std;
struct Pos{
	int x=0,y=0;
};
BotonVida::BotonVida() {
	spriteDuration = seconds(5); 
	spriteTimer.restart();
	spawnInterval = seconds(5);
	spawnTimer.restart();
	tt2.loadFromFile("Texture/vida.png");
}
void BotonVida::actu ( ) {
	vector<Pos>v;
	if (spawnTimer.getElapsedTime() >= spawnInterval) {
		///(200,340);    de uno a otro distancia 150
		///(350,340);    maximos x=800  y=940
		
		int c=0,c2=0;
		for(int i=0;i<25;i++) { 
			Pos pos; 
			pos.x=200+c; pos.y=340+c2;
			if(pos.y==750){
				pos.y-=150;
			}
			v.push_back(pos);
			c+=150;
			if(pos.x==800){
				c=0;
				c2+=150;
				
			}
		}
		srand(time(0));
		int i= 1+rand()%25;
		s2.setPosition(v[i].x,v[i].y);
		
		spawnTimer.restart();
		s2.setTexture(tt2);
		s2.setOrigin(16,16);
		spriteTimer.restart(); 
	}
	if (spriteTimer.getElapsedTime() >= spriteDuration) {
		s2.setTextureRect(IntRect(0, 0, 0, 0));
	}
}

Vector2f BotonVida::showPosVida ( ) {
	return s2.getPosition();
}

void BotonVida::draww (RenderWindow & w) {
	w.draw(s2);
}

void BotonVida::newPosition ( ) {
	s2.setPosition(-100,-100);
}

