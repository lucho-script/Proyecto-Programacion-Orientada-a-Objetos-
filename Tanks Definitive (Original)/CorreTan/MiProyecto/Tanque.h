#ifndef TANQUE_H
#define TANQUE_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include "Disparo.h"
#include "Explo.h"
#include <vector>
using namespace std;
using namespace sf;
class Tanque {
	Font font2;
	Text text,text3;
	Texture t;
	Sprite s;
	Clock time,time2;
	Time Lastbombing;
	int Heart=5;
	Keyboard::Key acel,fren,dere,izq,shoot;
	int points=0;
	bool pvc;
	int play=0;
	Music music;
	Explo explo; 
	Vector2f lastExplosionPosition;
public:
	Tanque(int player,bool isvsPc);
	void actu(int player,int mov);
	void draww(RenderWindow &w);
	bool can_shoot();
	Disparo generate_shoot();
	Vector2f see_positon();
	int show_life();
	void hurt();
	void destroyed();
	void hurtBomb();
	bool canBeDamaged();
	int show_points();
	void ScorePoints(bool isvsPc);
	void ajustar_posicion(float dx, float dy);
	void new_life();
	void DarVida();
	void guardar(int po);
};

#endif

