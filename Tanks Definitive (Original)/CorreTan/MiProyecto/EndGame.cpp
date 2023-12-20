#include "EndGame.h"
#include <windows.h> 
#include <SFML/Window/Keyboard.hpp>
#include "Partida.h"
#include "Menu.h"
#include "Scors.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstdio>
using namespace std;
using namespace sf;
struct Datos{
	string nom;
	int num;
};
EndGame::EndGame (bool pvC,bool player_one):pvc(pvC){
	mus.openFromFile("Audio/3.ogg");
	mus.setVolume(50);
	mus.setLoop(true);
	mus.play();
	
	if(pvc){
		text1.setString("You are dead, loser");
		font.loadFromFile("Font/Evil.otf");
		text1.setFont(font);
		text1.setPosition(350,400);
		text1.setCharacterSize(40);
		text1.setFillColor(Color::Red);
		
		text3.setString("Insert namer for load");
		text3.setFont(font);
		text3.setPosition(330,500);
		text3.setCharacterSize(40);
		text3.setFillColor(Color::Red);
		
		t.setFont(font);
		t.setCharacterSize(40);
		t.setPosition(460,600);
		
		t11.setFont(font);
		t11.setCharacterSize(40);
		t11.setPosition(480,600);
		
		t12.setFont(font);
		t12.setCharacterSize(40);
		t12.setPosition(500,600);
		
		t13.setFont(font);
		t13.setCharacterSize(40);
		t13.setPosition(520,600);
		
		text2.setString("Space to continue");
		text2.setFillColor(Color::Red);
		text2.setFont(font);
		text2.setPosition(395,700);
		text2.setCharacterSize(30);
	}else{
		if(player_one){
			text1.setString("Player Two are Dead");
			
		}else{
			text1.setString("Player One are Dead");
		}
		font.loadFromFile("Font/Evil.otf");
		text1.setFont(font);
		text1.setPosition(350,400);
		text1.setCharacterSize(40);
		text1.setFillColor(Color::Red);
		
		text2.setString("Space to play egain");
		text2.setFillColor(Color::Red);
		text2.setFont(font);
		text2.setPosition(395,500);
		text2.setCharacterSize(30);
	}
}

void EndGame::guardar(char a,char b,char c,char d){
	int po;
	string result;
	result += a;
	result += b;
	result += c;
	result += d;
	
	ifstream archi1("BackUpPoints.txt");
	archi1>>po;
	archi1.close();
	
	
	ofstream archi("Points.txt",ios::app);
	archi<<result<<" "<<po<<endl;
	archi.close();
	
}
void EndGame::actu (Game & g) {
	if(pvc){
		Sleep(10);
		for (int key = Keyboard::A; key <= Keyboard::Z; ++key) {
			if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(key))) {
				Sleep(80);
				char keyPressed = static_cast<char>(key + 'A');
				if (b == '-') { b = keyPressed; }
				else if (c == '-') { c = keyPressed; }
				else if (d == '-') { d = keyPressed; }
				else if (e == '-') { e = keyPressed; }
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
			if (e != '-') { e = '-'; }
			else if (d != '-') { d = '-'; }
			else if (c != '-') { c = '-'; }
			else if (b != '-') { b = '-'; }
		}
		t.setString(string(1, b));
		t11.setString(string(1, c));
		t12.setString(string(1, d));
		t13.setString(string(1, e));
		
		if(Keyboard::isKeyPressed(Keyboard::Space)){
			mus.stop();
			guardar(b,c,d,e);
			g.scene_change(new Scors);
		}
	}else{
		if(Keyboard::isKeyPressed(Keyboard::Space)){
			mus.stop();
			g.scene_change(new Partida(false,1,2));
		}
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		mus.stop();
		g.scene_change(new Menu(1024,1024));
	}
}
void EndGame::draww (RenderWindow & w) {
	w.draw(text1);
	w.draw(text2);
	w.draw(text3);
	w.draw(t);
	w.draw(t11);
	w.draw(t12);
	w.draw(t13);
}

