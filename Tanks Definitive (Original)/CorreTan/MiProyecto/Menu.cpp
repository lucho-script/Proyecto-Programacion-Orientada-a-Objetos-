#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Scors.h"
#include "Partida.h"
#include "EndGame.h"

Menu::Menu (float width, float height) {
	m.openFromFile("Audio/1.ogg");
	m.setVolume(50);
	m.setLoop(true);
	m.play();
	font.loadFromFile("Font/Evil.otf");
	text1.setFont(font);
	text1.setCharacterSize(120);
	text1.setPosition(300,700);
	text1.setString("TANKS WAR");
	backgraundTexture.loadFromFile("Texture/Tanks2.jpeg");
	backgraundSprite.setTexture(backgraundTexture);
	
	MainMenu[0].setFont(font);
	MainMenu[0].setFillColor(Color::White);
	MainMenu[0].setString("Player Vs Player");
	MainMenu[0].setCharacterSize(40);
	MainMenu[0].setPosition(100,150);
	
	MainMenu[1].setFont(font);
	MainMenu[1].setFillColor(Color::White);
	MainMenu[1].setString("Player vs PC");
	MainMenu[1].setCharacterSize(40);
	MainMenu[1].setPosition(100,200);
	
	MainMenu[2].setFont(font);
	MainMenu[2].setFillColor(Color::White);
	MainMenu[2].setString("Scores");
	MainMenu[2].setCharacterSize(40);
	MainMenu[2].setPosition(100,250);
	
	MainMenu[3].setFont(font);
	MainMenu[3].setFillColor(Color::White);
	MainMenu[3].setString("Exit");
	MainMenu[3].setCharacterSize(40);
	MainMenu[3].setPosition(100,300);
	
	MainMenu[MainMenuSelected].setFillColor(Color::Red);
}

void Menu::actu (Game & g) { ///Ver Funcionamiento de condiciones
	static Clock keyCooldown;
	if(keyCooldown.getElapsedTime().asMilliseconds()>=60){
		if(Keyboard::isKeyPressed(Keyboard::Down)){
			if(MainMenuSelected+1 <=Max_main_menu){
				MainMenu[MainMenuSelected].setFillColor(Color::White);
				MainMenuSelected++;
				if(MainMenuSelected==4){
					MainMenuSelected=0;
				}
				MainMenu[MainMenuSelected].setFillColor(Color::Red);
			}
		}else{
			if(Keyboard::isKeyPressed(Keyboard::Up)){
				if(MainMenuSelected-1 >= 0){
					MainMenu[MainMenuSelected].setFillColor(Color::White);
					MainMenuSelected--;
					if(MainMenuSelected==-1){
						MainMenuSelected=2;
					}
					MainMenu[MainMenuSelected].setFillColor(Color::Red);
				}
			}else{
				if(Keyboard::isKeyPressed(Keyboard::Return)){
					switch(MainMenuSelected){
					case 0:
						m.stop();
						a=1,b=2;
						g.scene_change(new Partida(false,a,b));
						
						break;
					case 1:
						m.stop();
						a=1,b=3;
						g.scene_change(new Partida(true,a,b));
						break;
					case 2:
						m.stop();
						g.scene_change(new Scors);
						break;
					case 3:
						g.close();
					}
				}
			}
			
		}
		keyCooldown.restart();
	}
	
}

void Menu::draww (RenderWindow & w) {
	w.draw(backgraundSprite);
	w.draw(text1);
	
	for(int i=0;i<Max_main_menu;i++) { 
		w.draw(MainMenu[i]);
	}
}

Menu::~Menu ( ) {
	
}

