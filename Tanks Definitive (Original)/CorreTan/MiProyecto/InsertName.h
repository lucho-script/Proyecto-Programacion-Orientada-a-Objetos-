#ifndef INSERTNAME_H
#define INSERTNAME_H
#include "Scene.h"
#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;
using namespace std;
class InsertName:public Scene {
	Font f;
	Texture tt;
	Sprite s;
	Text t,t11,t12,t13;
	string N;
	char b='-';
	char c='-';
	char d='-';
	char e='-';
public:
	InsertName(int point);
	void actu(Game &g)override;
	void draww(RenderWindow &w)override;
};

#endif

