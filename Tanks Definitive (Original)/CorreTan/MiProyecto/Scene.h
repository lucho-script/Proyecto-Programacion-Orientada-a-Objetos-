#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class Game;
class Scene {
public:
	Scene();
	virtual void actu(Game &g)=0;
	virtual void draww(RenderWindow &w)=0;
};

#endif

