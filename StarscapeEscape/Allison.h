#ifndef Allison_h
#define Allison_h

#include "Player.h"

using namespace std;

class Allison : public Player {
public:
	Allison();
	Allison(int x, int y, int pixel);
	void draw();

};

#endif