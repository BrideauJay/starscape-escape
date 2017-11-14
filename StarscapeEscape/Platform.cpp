#include "Platform.h"
#include "graphics.hpp"
using namespace std;

Platform::Platform() {

}
Platform::Platform(int startx, int length, int starty, int pixel_width) {
	this->startx = startx;
	this->starty = starty;
	this->length = length;
	this->pixel_width = pixel_width;
}

void Platform::draw() {
	glBegin(GL_QUADS);
	glColor3f(20, 20, 20);
	glVertex2i(startx * pixel_width, starty * pixel_width);
	glVertex2i(startx * pixel_width + (length * pixel_width), starty * pixel_width);
	glVertex2i(startx * pixel_width + (length * pixel_width), starty * pixel_width + pixel_width);
	glVertex2i(startx * pixel_width, starty * pixel_width + pixel_width);
	glEnd();
}

bool Platform::contains(int xin, int yin) {
	if (xin >= startx && xin < (startx+length) 
		&& yin >= starty && yin <= (starty +1)) {
		return true;
	}
	else {
		return false;
	}
}