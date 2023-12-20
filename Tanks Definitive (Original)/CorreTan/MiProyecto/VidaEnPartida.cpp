#include "VidaEnPartida.h"
using namespace std;
VidaEnPartida::VidaEnPartida() {
	font.loadFromFile("Font/asap1.otf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::Blue);
	
	
	text2.setFont(font);
	text2.setCharacterSize(30);
	text2.setString("Tank ");
}


void VidaEnPartida::drawHeart (RenderWindow & w) {
	w.draw(text);
	w.draw(text2);
}

void VidaEnPartida::lostlife (bool player_one, int lifee) {
	if(player_one){
		text2.setFillColor(Color::Green);
		text.setString("Life: "+to_string(lifee));
		text.setPosition(190,100);
		text2.setPosition(80,100);
	}else{
		text2.setFillColor(Color::Red);
		text.setString("Life: "+to_string(lifee));
		text.setPosition(800,100);
		text2.setPosition(690,100);
	}
}

