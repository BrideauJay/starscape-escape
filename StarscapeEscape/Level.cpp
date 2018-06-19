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
	{
		//width = 2880;
		Screen screen01 = Screen(width, height, pixel_width);
		//screen01.addPixelCluster(20, 25, 10, 15, 1, 0, 0);

		Platform p = Platform(15, 57, 25, pixel_width);
		Platform p2 = Platform(0, 30, 35, pixel_width);
		Platform p3 = Platform(37, 50, 40, pixel_width);
		Platform pt4 = Platform(83, 37, 20, pixel_width);

		screen01.addPlatform(p);
		screen01.addPlatform(p2);
		screen01.addPlatform(p3);
		screen01.addPlatform(pt4);

		screen01.screenid = "lvl1scr1";

		addScreen(screen01);

		Screen screen02 = Screen(width, height, pixel_width);
		//screen02.addPixelCluster(50, 70, 20, 40, 0, 1, 0);

		Platform p4 = Platform(0, 20, 20, pixel_width);
		Platform pt5 = Platform(27, 35, 25, pixel_width);
		Platform pt6 = Platform(70, 50, 20, pixel_width);
		screen02.addPlatform(p4);
		screen02.addPlatform(pt5);
		screen02.addPlatform(pt6);

		screen02.screenid = "lvl1scr2";

		addScreen(screen02);

		Screen screen03 = Screen(width, height, pixel_width);
		//screen03.addPixelCluster(5, 25, 40, 45, 0, 0, 1);

		Platform p5 = Platform(0, 20, 20, pixel_width);
		screen03.addPlatform(p5);

		Platform p6 = Platform(25, 30, 30, pixel_width);
		screen03.addPlatform(p6);

		screen03.screenid = "lvl1scr3";

		addScreen(screen03);

		break;
	}

	case 2:
	{
		Screen screenOnly = Screen(width, height, pixel_width);
		screenOnly.screenid = "lvl2scr1";

		Platform p = Platform(25, 105, 20, pixel_width);
		screenOnly.addPlatform(p);

		addScreen(screenOnly);

		break;
	}

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

void Level::setCurrentScreen(Screen new_current_screen) {
	for (int i = 0; i < screens.size(); i++){
		if (screens[i].screenid == new_current_screen.screenid) {
			current_screen = i;
		}
}
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