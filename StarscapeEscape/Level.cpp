#include "Level.h"

using namespace std;

Level::Level() {
	width = 960;
	height = 640;
	pixel_width = width / 120;
}

Level::Level(int indicator) {
	width = 960;
	height = 640;
	pixel_width = width / 120;
	switch (indicator) {
	case 1:
		Screen screen01 = Screen(width, height, pixel_width);
		screen01.addPixelCluster(20, 25, 10, 15, 1, 0, 0);

		Platform p = Platform(25, 105, 20, pixel_width);
		Platform p2 = Platform(0, 25, 35, pixel_width);
		Platform p3 = Platform(30, 50, 40, pixel_width);
		
		screen01.addPlatform(p);
		screen01.addPlatform(p2);
		screen01.addPlatform(p3);

		addScreen(screen01);

		Screen screen02 = Screen(width, height, pixel_width);
		screen02.addPixelCluster(50, 70, 20, 40, 0, 1, 0);

		Platform p4 = Platform(0, width, 20, pixel_width);
		screen02.addPlatform(p4);

		addScreen(screen02);

		Screen screen03 = Screen(width, height, pixel_width);
		screen03.addPixelCluster(5, 25, 40, 45, 0, 0, 1);

		Platform p5 = Platform(0, 20, 20, pixel_width);
		screen03.addPlatform(p5);

		Platform p6 = Platform(25, 30, 30, pixel_width);
		screen03.addPlatform(p6);

		addScreen(screen03);

		break;
	}
}

void Level::addScreen(Screen scre) {
	screens.push_back(scre);
}

int Level::getCurrentScreenNum() {
	return current_screen;
}

Screen Level::getCurrentScreen() {
	return screens[current_screen];
}

bool Level::screen_left() {
	if (current_screen == 0) {
		return false;
	}
	else {
		--current_screen;
		return true;
	}
}

bool Level::screen_right() {
	if (current_screen == screens.size()) {
		return false;
	}
	else {
		++current_screen;
		return true;
	}
}