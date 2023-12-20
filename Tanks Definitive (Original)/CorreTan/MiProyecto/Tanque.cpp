#include "Tanque.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <ctime>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
using namespace sf;

Tanque::Tanque (int player,bool isvsPc) :explo(true,seconds(1.0f)),pvc(isvsPc),play(player){
	///configuramos
	if(player==1){
		t.loadFromFile("Texture/tanke1.3.png");
	}else{
		if(player==2){
			t.loadFromFile("Texture/tanke2.3.png");
		}else{
			if(player==3){
				t.loadFromFile("Texture/tanke3.1.png");
			}
		}
	}
	s.setTexture(t);
	if(isvsPc){
		text.setString("Points: "+to_string(points));
		text.setFont(font2);
		text.setPosition(800,100);
		text.setCharacterSize(40);
		text.setFillColor(Color::Red);
	}
	if(player==1){
		acel=Keyboard::Up;
		fren=Keyboard::Down;
		dere=Keyboard::Right;
		izq=Keyboard::Left;
		shoot=Keyboard::LControl;
		
	}else{
		if(player==2){
			s.setRotation(180);
			acel=Keyboard::W;
			fren=Keyboard::S;
			dere=Keyboard::D;
			izq=Keyboard::A;
			shoot=Keyboard::J;
		}
	}
	if(pvc and player==1){
		text.setString("Points: "+to_string(points));
		text.setFont(font2);
		text.setPosition(800,100);
		text.setCharacterSize(40);
		text.setFillColor(Color::Red);
	}
	int min_x = 100;
	int max_x = 930;
	int min_y = 150;
	int max_y = 900;
	
	int x = rand() % (max_x - min_x) + min_x;
	int y = rand() % (max_y - min_y) + min_y;
	s.setPosition(x,y);
	s.setOrigin(30,25);	
	
	font2.loadFromFile("Font/Evil.otf");
	
}

void Tanque::actu (int player,int mov) {
	if(player==1 or player==2){
		if(Keyboard::isKeyPressed(dere)){
			s.rotate(2);
		}
		if(Keyboard::isKeyPressed(izq)){
			s.rotate(-2);
		}
		if(Keyboard::isKeyPressed(acel)){
			float ang=s.getRotation()*M_PI/180;
			s.move(cos(ang),sin(ang));
		}
		if(Keyboard::isKeyPressed(fren)){
			float ang=s.getRotation()*M_PI/180;
			s.move(-cos(ang),-sin(ang));
		}
	}else{
		int speed=3;
		if(mov==0){
			s.setRotation(180);
			// Movimiento hacia la derecha
			float elapsedTime = static_cast<float>(time.getElapsedTime().asSeconds());
			float newX = s.getPosition().x + speed * sin(elapsedTime);
			float newY = s.getPosition().y;
			s.setPosition(newX, newY);
		}
		if(mov== 1){
			// Movimiento hacia la izquierda
			s.setRotation(180);
			float elapsedTime2 = static_cast<float>(time.getElapsedTime().asSeconds());
			float newX2 = s.getPosition().x - speed * sin(elapsedTime2);
			float newY2 = s.getPosition().y;
			s.setPosition(newX2, newY2);
		}
		if(mov==2){
			// Movimiento vertical arriba/abajo
			s.setRotation(90);
			float elapsedTime3 = static_cast<float>(time.getElapsedTime().asSeconds());
			float newX3 = s.getPosition().x;
			float newY3 = s.getPosition().y + speed * sin(elapsedTime3); // Usar la función sinusoidal para movimiento vertical
			s.setPosition(newX3, newY3);
		}
	}
	///no se sale del mapa + explo animed
	if(!explo.isFinished()){
		explo.actu(s.getPosition());
	}
	if(s.getPosition().x<100){
		s.setPosition(100,s.getPosition().y);
	}
	if(s.getPosition().y<200){
		s.setPosition(s.getPosition().x,200);
	}
	if(s.getPosition().x>924){
		s.setPosition(924,s.getPosition().y);
	}
	if(s.getPosition().y>924){
		s.setPosition(s.getPosition().x,924);
	}
	if (!explo.isFinished()) {
		explo.actu(lastExplosionPosition);  // Usar la última posición de explosión
	}
}

void Tanque::draww (RenderWindow & w) {
	if(pvc){
		w.draw(s);
		if(play==1){
			w.draw(text);
		}
	}else{
		w.draw(s);
	}
	if (!explo.isFinished()) {
		explo.draww(w);
	}
}

bool Tanque::can_shoot ( ) {
	if(time.getElapsedTime().asMilliseconds()<600){
		return false;
	}
	if(not Keyboard::isKeyPressed(shoot)){
		return false;
	}
	
	time.restart();
	return true;
}

Disparo Tanque::generate_shoot ( ) {
	Vector2f p=s.getPosition();
	float ang=s.getRotation()*M_PI/180;
	Vector2f d(cos(ang),sin(ang));
	
	return Disparo(p+35.f*d,d);
}

Vector2f Tanque::see_positon ( ) {
	return s.getPosition();
}

int Tanque::show_life ( ) {
	return Heart;
}
void Tanque::destroyed ( ) {
	int min_x = 100;
	int max_x = 930;
	int min_y = 150;
	int max_y = 900;
	
	int x = rand() % (max_x - min_x) + min_x;
	int y = rand() % (max_y - min_y) + min_y;
	lastExplosionPosition = s.getPosition();
	s.setPosition(x, y);
	Lastbombing = time2.getElapsedTime();
	time2.restart();
	explo.activate();
}

void Tanque::hurt ( ) {
	--Heart;
}

void Tanque::hurtBomb ( ) {
	--Heart;
	Lastbombing=time2.getElapsedTime();
}

bool Tanque::canBeDamaged ( ) {
	Time currentTime =time2.getElapsedTime();
	return (currentTime - Lastbombing) >seconds(1.0f); 
}

int Tanque::show_points ( ) {
	return points;
}

void Tanque::ScorePoints (bool isvsPc) {
	if(isvsPc){
		points+=100;
		text.setString("Points: "+to_string(points));
	}
}
void Tanque::guardar(int po){
	ofstream archi("BackUpPoints.txt",ios::out | ios::trunc);
	archi<<po;
}
void Tanque::ajustar_posicion (float dx, float dy) {
	s.move(dx, dy);
}

void Tanque::new_life ( ) {
	Heart=2;
}
void Tanque::DarVida(){
	++Heart;
}
