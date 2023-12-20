#include "Scors.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Partida.h"
using namespace std;
using namespace sf;
struct Datos{
	string nom;
	int num;
};
bool operator<(Datos &a,Datos &b){
	return a.num<b.num;
}

Scors::Scors() {
	
	string aux; Datos f; vector<Datos>v;
	ifstream archi2("Points.txt");
	while(getline(archi2,aux)){
		int pos1=aux.find(' ');
		f.nom=aux.substr(0,pos1);
		int pos2=aux.find(' ',pos1+1);
		f.num=stoi(aux.substr(pos1+1,pos2-pos1-1));
		v.push_back(f);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	font.loadFromFile("Font/Evil.otf");
	textT.setFont(font);
	textT.setString("Best Points");
	textT.setPosition(300,50);
	textT.setCharacterSize(100);
	
	text.setFont(font);
	text.setCharacterSize(70);
	text.setString(v[0].nom+"   "+to_string(v[0].num));
	text.setPosition(355,170);
	
	text2.setFont(font);
	text2.setCharacterSize(70);
	text2.setString(v[1].nom+"   "+to_string(v[1].num));
	text2.setPosition(355,310);
	
	text3.setFont(font);
	text3.setCharacterSize(70);
	text3.setString(v[2].nom+"   "+to_string(v[2].num));
	text3.setPosition(355,450);
	
	text4.setFont(font);
	text4.setCharacterSize(70);
	text4.setString(v[3].nom+"   "+to_string(v[3].num));
	text4.setPosition(355,600);
	
	text5.setFont(font);
	text5.setCharacterSize(70);
	text5.setString(v[4].nom+"   "+to_string(v[4].num));
	text5.setPosition(355,750);
}

void Scors::actu (Game & g) {
	if(Keyboard::isKeyPressed(Keyboard::F)){
		g.scene_change(new Partida(true,1,3));
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		g.scene_change(new Menu(1024,1024));
	}
}
void Scors::draww (RenderWindow & w) {
	w.draw(text);
	w.draw(text2);
	w.draw(text3);
	w.draw(text4);
	w.draw(text5);
	w.draw(textT);
}

