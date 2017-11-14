#include "Bee.h"
#include "graphics.hpp"

using namespace std;

Bee::Bee() {

}

Bee::Bee(int x, int y, int pixel) {
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

void Bee::draw() {
	if (getDirection() == user) {
		//hair
			//left of part
		glBegin(GL_QUADS);
		//rgb: (175,74,10)
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i(getX() * pixel_width, getY() * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i(getX() * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() - 1) * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() - 1) * pixel_width) + pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() - 1) * pixel_width) + pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glVertex2i((getX() - 1) * pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glEnd();
		//top
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 4, (getY() - 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 4, ((getY() - 1) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() - 1) * pixel_width) + pixel_width);
		glEnd();
			//right side
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 4) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 4) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 5) * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 5) * pixel_width) + pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 5) * pixel_width) + pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glVertex2i((getX() + 5) * pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glEnd();

		//head
		glBegin(GL_QUADS);
		//rgb: (245, 228, 213)
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//body
			//shirt base
		glBegin(GL_QUADS);
		glColor3f(.4, .8, 1);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 3) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 3);
		glEnd();
			//shorts begin
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 6) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 6) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 6) * pixel_width) + pixel_width);
		glEnd();

		//arms
			//left
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
				//sleeve
		glBegin(GL_QUADS);
		glColor3f(1, 0.75, 0.2);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glEnd();
			//right
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
				//sleeve
		glBegin(GL_QUADS);
		glColor3f(1, 0.75, 0.2);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glEnd();

		//legs
			//left
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
				//shorts
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glEnd();
			//right
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
				//shorts
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glEnd();

	}
	else if (getDirection() == leftPos) {
		//head
		glBegin(GL_QUADS);
		//rgb: (245, 228, 213)
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//hair
		//back
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 4) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 4) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 5) * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 5) * pixel_width) + pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 5) * pixel_width) + pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glVertex2i((getX() + 5) * pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glEnd();
		//top
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() - 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, ((getY() - 1) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() - 1) * pixel_width) + pixel_width);
		glEnd();
		//over face
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 2) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width * 2, getY() * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width * 2, (getY() * pixel_width) + pixel_width);
		glVertex2i((getX() + 2) * pixel_width, (getY() * pixel_width) + pixel_width);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 1) * pixel_width) + pixel_width * 2);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 1) * pixel_width) + pixel_width * 2);
		glEnd();

		//body
		//shirt base
		glBegin(GL_QUADS);
		glColor3f(.4, .8, 1);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 3) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 3);
		glEnd();
		//shorts begin
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 6) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 6) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 6) * pixel_width) + pixel_width);
		glEnd();

		//arm (left)
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//sleeve
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glEnd();

		//legs
		//left
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
		//shorts
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glEnd();
		//right
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
		//shorts
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glEnd();
	}
	else if (getDirection() == rightPos) {
		//head
		glBegin(GL_QUADS);
		//rgb: (245, 228, 213)
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//hair
			//back
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i(getX() * pixel_width, getY() * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i(getX() * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() - 1) * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() - 1) * pixel_width) + pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() - 1) * pixel_width) + pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glVertex2i((getX() - 1) * pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glEnd();
			//top
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() - 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, ((getY() - 1) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() - 1) * pixel_width) + pixel_width);
		glEnd();
			//over face
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 2, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 2, (getY() * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 1) * pixel_width) + pixel_width * 2);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 1) * pixel_width) + pixel_width * 2);
		glEnd();

		//body
			//shirt base
		glBegin(GL_QUADS);
		glColor3f(.4, .8, 1);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 3) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 3);
		glEnd();
			//shorts begin
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 6) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 6) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 6) * pixel_width) + pixel_width);
		glEnd();

		//arm (right)
			//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
			//sleeve
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glEnd();

		//legs
			//left
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
				//shorts
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glEnd();
			//right
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
				//shorts
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glEnd();
	}
	else if (getDirection() == away) {
		//hair
			//left of part
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i(getX() * pixel_width, getY() * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i(getX() * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() - 1) * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() - 1) * pixel_width) + pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() - 1) * pixel_width) + pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glVertex2i((getX() - 1) * pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glEnd();
			//top
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i(getX() * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width * 4, (getY() - 1) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width * 4, ((getY() - 1) * pixel_width) + pixel_width);
		glVertex2i(getX() * pixel_width, ((getY() - 1) * pixel_width) + pixel_width);
		glEnd();
			//right side
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 4) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 4) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 5) * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 5) * pixel_width) + pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 5) * pixel_width) + pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glVertex2i((getX() + 5) * pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glEnd();

		//head
		glBegin(GL_QUADS);
		glColor3f(0.686, 0.29, 0.039);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//body
			//shirt base
		glBegin(GL_QUADS);
		glColor3f(.4, .8, 1);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 3) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 3);
		glEnd();
			//shorts begin
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 6) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 6) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 6) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 6) * pixel_width) + pixel_width);
		glEnd();

		//arms
			//left
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
				//sleeve
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glEnd();
			//right
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
				//sleeve
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 2);
		glEnd();

		//legs
			//left
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
				//shorts
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glEnd();
			//right
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.961, 0.894, 0.835);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
				//shorts
		glBegin(GL_QUADS);
		glColor3f(1, .75, .2);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width);
		glEnd();
	}
}