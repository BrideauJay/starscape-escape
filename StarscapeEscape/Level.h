#ifndef level_h
#define level_h

#include "graphics.hpp"
#include "character.h"
#include "player.h"
#include "Platform.h"
#include "Screen.h"
#define _USE_MATH_DEFINES 
#include <math.h>
using namespace std;

class Level {
public:
	Level();
	Level(int indicator);
	int width;
	int height;
	int pixel_width;
	int current_screen = 0;
	vector<Screen> screens;

	void addScreen(Screen scre);

	int getCurrentScreenNum();
	Screen getCurrentScreen();

	bool screen_left();
	bool screen_right();
};

#endif
