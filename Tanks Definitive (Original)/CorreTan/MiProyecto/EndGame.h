#ifndef ENDGAME_H
#define ENDGAME_H
#include "Scene.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
using namespace std;
using namespace sf;
class EndGame:public Scene {
	Text text1,text2,text3;
	Font font;
	Music mus;
	bool pvc;
	int points;
	Text t11,t12,t13,t;
	char b='-';
	char c='-';
	char d='-';
	char e='-';
public:
	EndGame(bool pvC,bool player_one);
	void actu(Game &g) override;
	void draww(RenderWindow &w)override;
	void guardar(char a,char b,char c,char d);
};

#endif

