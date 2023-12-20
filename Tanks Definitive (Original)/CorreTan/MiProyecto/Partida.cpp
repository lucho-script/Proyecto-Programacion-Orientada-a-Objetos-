#include "Partida.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include "Menu.h"
#include "EndGame.h"
#include <cstdlib>
using namespace std;
int a=0,b=0;
tuple<int,int> darPos(int uniqueID){
	int x= 200 + a;
	int y= 260 + b;
	a+=150;
	if(a==750){
		a=0;
		b+=150;
	}
	return make_tuple(x,y);
}
Partida::Partida (bool isvsPc,int a, int b):t1(a,isvsPc),t2(b,isvsPc),pvc(isvsPc),explo(true,seconds(1.0f)),bomb(true),pared(false){
	tt.loadFromFile("Texture/Piso1.png");
	s.setTexture(tt);
	
	musi.openFromFile("Audio/2.ogg");
	musi.setVolume(30);
	musi.setLoop(true);
	musi.play();
	
	for (int i = 0; i < 25; i++) {
		int x, y;
		tie(x, y) = darPos(i);
		Bomba nuevaPared(false);
		nuevaPared.set_position(x, y);
		paredes.push_back(nuevaPared);
	}
}
bool destroy(Disparo &s, Tanque &t){
	Vector2f ps=s.see_positon();
	Vector2f pt=t.see_positon();
	Vector2f v=ps-pt;
	return sqrt(v.x*v.x+v.y*v.y)<20;
}
bool destroy(Disparo &s, Bomba &t){
	Vector2f ps=s.see_positon();
	Vector2f pt=t.showPosBomb();
	Vector2f v=ps-pt;
	return sqrt(v.x*v.x+v.y*v.y)<38;
}

void Partida::actu (Game &g) {
	if(pvc){
		t1.actu(1,mov);
		t2.actu(3,mov);
	}else{
		t1.actu(1,mov);
		t2.actu(2,mov);
	}
	
	for (size_t i = 0; i < paredes.size(); i++) {
		paredes[i].actu();
	}
	bomb.actu();
	vida.actu();
	Vector2f t1Pos = t1.see_positon();
	Vector2f  t2Pos = t2.see_positon();
	
	float minDistance = 60; // Establece el radio mínimo para evitar la superposición
	if (sqrt(pow(t1Pos.x - t2Pos.x, 2) + pow(t1Pos.y - t2Pos.y, 2)) < minDistance) {
		// Si los tanques coinciden dentro del radio, desplázalos fuera del radio
		Vector2f direction = t1Pos - t2Pos;
		float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
		direction /= distance; // Normalizar la dirección
		
		float displacement = minDistance - distance;
		t1Pos += direction * (displacement / 2.0f);
		t2Pos -= direction * (displacement / 2.0f);
		
		t1.ajustar_posicion(t1Pos.x - t1.see_positon().x, t1Pos.y - t1.see_positon().y);
		t2.ajustar_posicion(t2Pos.x - t2.see_positon().x, t2Pos.y - t2.see_positon().y);
	}
	
	for(size_t i=0;i<paredes.size();i++) { 
		Vector2f pared=paredes[i].showPosBomb();
		if(sqrt(pow(t1Pos.x-pared.x,2)+pow(t1Pos.y-pared.y,2)) <minDistance){
			Vector2f direction = t1Pos-pared;
			float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
			direction /= distance;
			float displacement = minDistance - distance;
			t1Pos += direction * (displacement / 2.0f);
			pared -= direction * (displacement / 2.0f);
			t1.ajustar_posicion(t1Pos.x - t1.see_positon().x, t1Pos.y - t1.see_positon().y);
		}
		
		if(sqrt(pow(t2Pos.x-pared.x,2)+pow(t2Pos.y-pared.y,2)) <minDistance){
			Vector2f direction = t2Pos-pared;
			float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
			direction /= distance;
			float displacement = minDistance - distance;
			t2Pos += direction * (displacement / 2.0f);
			pared -= direction * (displacement / 2.0f);
			t2.ajustar_posicion(t2Pos.x - t2.see_positon().x, t2Pos.y - t2.see_positon().y);
		}
	}
	for(size_t i=0;i<ds.size();i++) { 
		Disparo &s=ds[i];
		if(destroy(s,t1)){
			if(t1.show_life()>0){
				t1.hurt();
				ds.erase(ds.begin()+i);
				--i;
			}else{
				musi.stop();
				for(size_t i=0;i<paredes.size();i++) { 
					paredes.clear();
					a=0;b=0;
				}
				t1.guardar(t1.show_points());
				g.scene_change(new EndGame(pvc,false));
			}
		}else{
			if(destroy(s,t2)){
				if(t2.show_life()>0){
					t2.hurt();
					ds.erase(ds.begin()+i);
					--i;
				}else{
					if(pvc){
						ds.erase(ds.begin()+i);
						--i;
						explo.activate();
						t2.destroyed();
						mov= 1+rand()%3;
						t2.new_life();
						t1.ScorePoints(true);
					}else{
						musi.stop();
						for(size_t i=0;i<paredes.size();i++) { 
							paredes.clear();
							a=0;b=0;
						}
						t1.guardar(t1.show_points());
						g.scene_change(new EndGame(pvc,true));
					}
				}
				
			}else{
				if(s.isOutOfBounds()){
					ds.erase(ds.begin()+i);
					--i;
				}
			}
		}
		for(size_t j=0;j<paredes.size();j++) { 
			if(destroy(s,paredes[j])){
				ds.erase(ds.begin()+i);
				--i;
			}
		}
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		musi.stop();
		for(size_t i=0;i<paredes.size();i++) { 
			paredes.clear();
			a=0;b=0;
		}
		g.scene_change(new Menu(1024,1024));
	}
	if(t1.can_shoot()){
		ds.push_back(t1.generate_shoot());
	}
	
	if(t2.can_shoot()){
		ds.push_back(t2.generate_shoot());
	}
	for(Disparo &s:ds){
		s.actu();
	}
	Vector2f bombPos = bomb.showPosBomb();
	if(t1.show_life() > 0 and sqrt(pow(bombPos.x - t1.see_positon().x, 2) + pow(bombPos.y - t1.see_positon().y, 2)) < 100) {
		if (t1.canBeDamaged()) {
			t1.hurtBomb();
		}
	}else{
		if(t1.show_life() == 0 and sqrt(pow(bombPos.x - t1.see_positon().x, 2) + pow(bombPos.y - t1.see_positon().y, 2)) < 100){
			musi.stop();
			for(size_t i=0;i<paredes.size();i++) { 
				paredes.clear();
				a=0;b=0;
			}
			t1.guardar(t1.show_points());			
			g.scene_change(new EndGame(pvc,false));
		}
	};
	if(t2.show_life() > 0 and sqrt(pow(bombPos.x - t2.see_positon().x, 2) + pow(bombPos.y - t2.see_positon().y, 2)) < 100) {
		if (t2.canBeDamaged()) {
			t2.hurtBomb();
		}
	}else{
		if(t2.show_life() == 0 and sqrt(pow(bombPos.x - t2.see_positon().x, 2) + pow(bombPos.y - t2.see_positon().y, 2)) < 100){
			musi.stop();
			for(size_t i=0;i<paredes.size();i++) { 
				paredes.clear();
				a=0;b=0;
			}
			t1.guardar(t1.show_points());			
			g.scene_change(new EndGame(pvc,true));
		}
	};

	

	Vector2f posVida =vida.showPosVida();
	if (sqrt(pow(posVida.x - t2.see_positon().x, 2) + pow(posVida.y - t2.see_positon().y, 2)) < 30) {
		t2.DarVida();
		vida.newPosition();
	}
	if (sqrt(pow(posVida.x - t1.see_positon().x, 2) + pow(posVida.y - t1.see_positon().y, 2)) < 30) {
		t1.DarVida();
		vida.newPosition();
	}
}

void Partida::draww (RenderWindow & w) {
	w.draw(s);
	if(pvc){
		lifeGame.lostlife(true, t1.show_life());
		lifeGame.drawHeart(w);
	}else{
		lifeGame.lostlife(true, t1.show_life());
		lifeGame.drawHeart(w);
		lifeGame.lostlife(false, t2.show_life());
		lifeGame.drawHeart(w);
	};	
	vida.draww(w);
	bomb.draww(w);
	t1.draww(w);
	t2.draww(w);
	for(auto &element:paredes) { 
		element.draww(w);
	}
	for(Disparo &s:ds){
		s.draww(w);
	}
}
