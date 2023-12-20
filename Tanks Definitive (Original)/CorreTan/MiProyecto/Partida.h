#ifndef PARTIDA_H
#define PARTIDA_H
#include "Explo.h"
#include "Bomba.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Tanque.h"
#include <vector>
#include "Disparo.h"
#include <SFML/Audio/Music.hpp>
#include "Scene.h"
#include "VidaEnPartida.h"
#include "Scors.h"
#include "BotonVida.h"
using namespace std;
using namespace sf;

class Partida:public Scene{
	Explo explo;
	Bomba bomb,pared;
	Sprite s;
	int mov=0; 
	Texture tt;
	Tanque t1,t2;
	vector<Disparo>ds;
	vector<Bomba>paredes;
	VidaEnPartida lifeGame;
	bool pvc;
	Music musi;
	BotonVida vida;
public:
	Partida(bool isvsPc,int a,int b);
	void actu(Game &g);
	void draww(RenderWindow &w);
};

#endif

