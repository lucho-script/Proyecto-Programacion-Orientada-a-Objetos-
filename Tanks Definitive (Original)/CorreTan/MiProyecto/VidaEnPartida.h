#ifndef VIDAENPARTIDA_H
#define VIDAENPARTIDA_H
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "VidaEnPartida.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class VidaEnPartida {
	Text text,text2;
	Font font;
public:
	VidaEnPartida();
	void drawHeart(RenderWindow &w);
	void lostlife(bool player_one,int lifee);
};

#endif

