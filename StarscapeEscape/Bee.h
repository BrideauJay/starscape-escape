#ifndef Bee_h
#define Bee_h
#include "Player.h"

class Bee : public Player {
public:
	Bee();
	Bee(int x, int y, int pixel);
	void draw();
};

#endif