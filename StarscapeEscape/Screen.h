#ifndef screen_h
#define screen_h

#include "Platform.h"
#include <vector>
#include "graphics.hpp"
#include <string>

using namespace std;

struct Pix{
	int left_x;
	int right_x;
	int top_y;
	int bottom_y;
	int red;
	int green;
	int blue;
};

class Screen {
public:
	Screen();
	Screen(int wide, int high, int pixel);

	int width;
	int height;
	int pixel_width;

	vector <Platform> platforms;
	vector <struct Pix> pixel_art;

	void addPlatform(int start_x, int end_x, int y);
	void addPlatform(Platform p);
	void addPixelCluster(int left_x, int right_x, int top_y, int bottom_y, int red, int green, int blue);

	vector <Platform> get_platforms();

	void draw();

	//unique identifier
	string screenid;

};

#endif