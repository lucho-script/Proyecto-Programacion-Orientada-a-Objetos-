#ifndef GAME_H
#define GAME_H
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
	RenderWindow wi;
	Scene *sce_actual,*nextt=nullptr; ///Analizar punteros sce_actual y nextt.
	int seg=0,min=0;
public:
	Game(Scene *e);
	void play();
	void scene_change(Scene *new_scene);
	void close();
	~Game();
};
#endif

