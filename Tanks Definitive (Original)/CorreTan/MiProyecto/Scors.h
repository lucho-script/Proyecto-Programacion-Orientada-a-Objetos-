#ifndef SCORS_H
#define SCORS_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include <SFML/Graphics/Font.hpp>
#include <vector>
#include <SFML/Graphics/Text.hpp>
using namespace std;
using namespace sf;

class Scors:public Scene {
	Font font;
	Text text,text2,text3,text4,text5,textT;
public:
	Scors();
	void actu(Game &g)override;
	void draww(RenderWindow &w)override;
};

#endif

