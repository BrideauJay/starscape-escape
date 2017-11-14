#include "Caleb.h"
#include "graphics.hpp"

using namespace std;

Caleb::Caleb() {

}

Caleb::Caleb(int x, int y, int pixel) {
	charwidth = 5;
	charheight = 10;
	setX(x);
	setY(y);
	pixel_width = pixel;
	charDirection = user;
	//acceleration variables
	int xTargetSpeed = 1;
	int yTargetSpeed = 0;
	int xCurrentSpeed = 0;
	int yCurrentSpeed = 0;
	int gravitySpeed = 1;
}

void Caleb::draw() {
	if (getDirection() == user) {
		//hair
			//left
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i(getX() * pixel_width, getY() * pixel_width);
		glVertex2i(getX() * pixel_width + pixel_width, getY() * pixel_width);
		glVertex2i(getX() * pixel_width + pixel_width, getY() * pixel_width + pixel_width * 2);
		glVertex2i(getX() * pixel_width, getY() * pixel_width + pixel_width * 2);
		glEnd();
			//top
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() - 1) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() - 1) * pixel_width + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width + pixel_width);
		glEnd();
			//right
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 4) * pixel_width, getY() * pixel_width);
		glVertex2i((getX() + 4) * pixel_width + pixel_width, getY() * pixel_width);
		glVertex2i((getX() + 4) * pixel_width + pixel_width, getY() * pixel_width + pixel_width * 2);
		glVertex2i((getX() + 4) * pixel_width, getY() * pixel_width + pixel_width * 2);
		glEnd();

		//head
		glBegin(GL_QUADS);
		//rgb: (141, 83, 17)
		//rgb: (161, 95, 50)
		glColor3f(0.631, 0.373, 0.196);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//body
		//shirt
		glBegin(GL_QUADS);
		//rgb: 251, 246, 78
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i((getX() + 1) * pixel_width,(getY() + 3) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 3) * pixel_width + (pixel_width * 3));
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width + (pixel_width * 3));
		glEnd();
		//pants begin
		glBegin(GL_QUADS);
		//rgb: 54, 153, 51
		//rgb: 83, 237, 128
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 6) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 6) * pixel_width + (pixel_width));
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width + (pixel_width));
		glEnd();

		//arms
		//left
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.631, 0.373, 0.196);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();
		//right
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.631, 0.373, 0.196);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();

		//legs
		//left
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
		//right
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
	}
	else if (getDirection() == leftPos) {
		//head
		glBegin(GL_QUADS);
		glColor3f(0.631, 0.373, 0.196);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//hair
		//right
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 4) * pixel_width, getY() * pixel_width);
		glVertex2i((getX() + 4) * pixel_width + pixel_width, getY() * pixel_width);
		glVertex2i((getX() + 4) * pixel_width + pixel_width, getY() * pixel_width + pixel_width * 3);
		glVertex2i((getX() + 4) * pixel_width, getY() * pixel_width + pixel_width * 3);
		glEnd();
		//top
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() - 1) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() - 1) * pixel_width + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width + pixel_width);
		glEnd();
		//over face
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 2) * pixel_width, getY() * pixel_width);
		glVertex2i((getX() + 2) * pixel_width + (pixel_width * 2), getY() * pixel_width);
		glVertex2i((getX() + 2) * pixel_width + (pixel_width * 2), getY() * pixel_width + pixel_width * 2);
		glVertex2i((getX() + 2) * pixel_width, getY() * pixel_width + pixel_width * 2);
		glEnd();

		//body
		//shirt
		glBegin(GL_QUADS);
		//rgb: 251, 246, 78
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 3) * pixel_width + (pixel_width * 3));
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width + (pixel_width * 3));
		glEnd();
		//pants begin
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 6) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 6) * pixel_width + (pixel_width));
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width + (pixel_width));
		glEnd();

		//arm (right)
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.631, 0.373, 0.196);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();

		//legs
		//left
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
		//right
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
	}
	else if (getDirection() == rightPos) {
		//head
		glBegin(GL_QUADS);
		glColor3f(0.631, 0.373, 0.196);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//hair
		//left
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i(getX() * pixel_width, getY() * pixel_width);
		glVertex2i(getX() * pixel_width + pixel_width, getY() * pixel_width);
		glVertex2i(getX() * pixel_width + pixel_width, getY() * pixel_width + pixel_width * 3);
		glVertex2i(getX() * pixel_width, getY() * pixel_width + pixel_width * 3);
		glEnd();
		//top
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() - 1) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() - 1) * pixel_width + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width + pixel_width);
		glEnd();
		//over face
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 2), getY() * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 2), getY() * pixel_width + pixel_width * 2);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width + pixel_width * 2);
		glEnd();

		//body
		//shirt
		glBegin(GL_QUADS);
		//rgb: 251, 246, 78
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 3) * pixel_width + (pixel_width * 3));
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width + (pixel_width * 3));
		glEnd();
		//pants begin
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 6) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 6) * pixel_width + (pixel_width));
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width + (pixel_width));
		glEnd();

		//arm (right)
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.631, 0.373, 0.196);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();

		//legs
		//left
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
		//right
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
	}
	else if (getDirection() == away) {
		//hair
		//left
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i(getX() * pixel_width, getY() * pixel_width);
		glVertex2i(getX() * pixel_width + pixel_width, getY() * pixel_width);
		glVertex2i(getX() * pixel_width + pixel_width, getY() * pixel_width + pixel_width * 2);
		glVertex2i(getX() * pixel_width, getY() * pixel_width + pixel_width * 2);
		glEnd();
		//top
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() - 1) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() - 1) * pixel_width + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width + pixel_width);
		glEnd();
		//right
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 4) * pixel_width, getY() * pixel_width);
		glVertex2i((getX() + 4) * pixel_width + pixel_width, getY() * pixel_width);
		glVertex2i((getX() + 4) * pixel_width + pixel_width, getY() * pixel_width + pixel_width * 2);
		glVertex2i((getX() + 4) * pixel_width, getY() * pixel_width + pixel_width * 2);
		glEnd();

		//head
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//body
		//shirt
		glBegin(GL_QUADS);
		//rgb: 251, 246, 78
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 3) * pixel_width + (pixel_width * 3));
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width + (pixel_width * 3));
		glEnd();
		//pants begin
		glBegin(GL_QUADS);
		//rgb: 54, 153, 51
		//rgb: 83, 237, 128
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 6) * pixel_width);
		glVertex2i((getX() + 1) * pixel_width + (pixel_width * 3), (getY() + 6) * pixel_width + (pixel_width));
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width + (pixel_width));
		glEnd();

		//arms
		//left
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.631, 0.373, 0.196);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();
		//right
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.631, 0.373, 0.196);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(0.984, 0.965, 0.306);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();

		//legs
		//left
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
		//right
		glBegin(GL_QUADS);
		glColor3f(0.325, 0.929, 0.502);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
	}
}