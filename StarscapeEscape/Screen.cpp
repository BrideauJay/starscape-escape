#include "Screen.h"

using namespace std;

Screen::Screen() {
	width = 960;
	height = 640;
}

Screen::Screen(int wide, int high, int pixel) {
	width = wide;
	height = high;
	pixel_width = pixel;
}

void Screen::addPlatform(int start_x, int end_x, int y) {
	Platform p = Platform(start_x, end_x - start_x, y, pixel_width);
	platforms.push_back(p);
}

void Screen::addPlatform(Platform p) {
	platforms.push_back(p);
}

void Screen::addPixelCluster(int left_x, int right_x, int top_y, int bottom_y, int red, int green, int blue) {
	Pix new_rect;
	new_rect.left_x = left_x;
	new_rect.right_x = right_x;
	new_rect.top_y = top_y;
	new_rect.bottom_y = bottom_y;
	new_rect.red = red;
	new_rect.green = green;
	new_rect.blue = blue;
	pixel_art.push_back(new_rect);
}

void Screen::draw() {
	for (int i = 0; i < pixel_art.size(); ++i) {
		Pix pixel = pixel_art[i];
		glBegin(GL_QUADS);
		glColor3f(pixel.red, pixel.green, pixel.blue);
		glVertex2i(pixel.left_x * pixel_width, pixel.top_y * pixel_width);
		glVertex2i(pixel.right_x * pixel_width, pixel.top_y * pixel_width);
		glVertex2i(pixel.right_x * pixel_width, pixel.bottom_y * pixel_width);
		glVertex2i(pixel.left_x * pixel_width, pixel.bottom_y * pixel_width);
		glEnd();
	}
	for (int j = 0; j < platforms.size(); ++j) {
		Platform p = platforms[j];
		p.draw();
	}
}

vector <Platform> Screen::get_platforms() {
	return platforms;
}