#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
using namespace sf;

int main(int argc, char *argv[]){
	Game g(new Menu(1024,1024));
	g.play();
	return 0;
}

