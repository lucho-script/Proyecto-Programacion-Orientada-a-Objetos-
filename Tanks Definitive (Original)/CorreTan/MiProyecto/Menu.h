#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"


#define Max_main_menu 4
using namespace sf; 
class Menu: public Scene{
	Text text1, MainMenu[Max_main_menu];
	Font font;
	Sprite backgraundSprite;
	Texture backgraundTexture;
	int MainMenuSelected=0;
	Music m;
	int a,b;
public:
	Menu(float width, float height);
	void actu(Game &g);
	void draww(RenderWindow &w)override;
	int MainMenuPressed(){
		return MainMenuSelected;
	}
	~Menu();
};
#endif

