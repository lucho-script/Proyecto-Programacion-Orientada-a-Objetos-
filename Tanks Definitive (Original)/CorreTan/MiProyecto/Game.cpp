#include "Game.h"
#include <SFML/Window/Event.hpp>
#include "Scene.h"


Game::Game (Scene *e):wi(VideoMode(1024,1024),"Ejemplo de SFML") {
	sce_actual=e;
}

void Game::play ( ) {
	wi.setFramerateLimit(60);
	
	while(wi.isOpen()) {
		Event e;
		while(wi.pollEvent(e)) {
			if(e.type == Event::Closed)
				wi.close();	
		}
		
		wi.clear(Color::Black);
		sce_actual->actu(*this);
		wi.clear();
		sce_actual->draww(wi);
		wi.display();
		if(nextt){
			delete  sce_actual;
			sce_actual=nextt;
			nextt=nullptr;
		}
	}
}

void Game::scene_change (Scene * new_scene) {
	nextt=new_scene;
}

void Game::close ( ) {
	wi.close();
}

Game::~Game ( ) {
	delete sce_actual;
}

