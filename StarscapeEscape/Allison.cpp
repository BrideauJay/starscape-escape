#include "Allison.h"
#include "graphics.hpp"

Allison::Allison() {

}

Allison::Allison(int x, int y, int pixel) {
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

void Allison::draw() {
	if (getDirection() == user) {
		//hair
			//base
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i(getX() * pixel_width, (getY()-1) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width * 5, (getY()-1) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width * 5, ((getY()-1) * pixel_width) + pixel_width * 3);
		glVertex2i(getX() * pixel_width, ((getY()-1) * pixel_width) + pixel_width * 3);
		glEnd();
			//ponytail base
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX()-1) * pixel_width, (getY() - 2) * pixel_width);
		glVertex2i(((getX()-1) * pixel_width) + pixel_width * 3, (getY() - 2) * pixel_width);
		glVertex2i(((getX()-1) * pixel_width) + pixel_width * 3, ((getY() - 2) * pixel_width) + pixel_width * 3);
		glVertex2i((getX()-1) * pixel_width, ((getY() - 2) * pixel_width) + pixel_width * 3);
		glEnd();
			//ponytail tip
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() - 2) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() - 2) * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i(((getX() - 2) * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 2);
		glVertex2i((getX() - 2) * pixel_width, (getY() * pixel_width) + pixel_width * 2);
		glEnd();

		//head
		glBegin(GL_QUADS);
		//rgb: (241, 204, 164)
		glColor3f(0.945, 0.8, 0.643);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//body
			//overalls
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() +1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() +1) * pixel_width) + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i(((getX() +1) * pixel_width) + (pixel_width * 3), ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() +1) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
			//shirt peek
		glBegin(GL_QUADS);
		glColor3f(.9, .7, .95);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();

		//arms
			//left
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.945, 0.8, 0.643);
		glVertex2i(getX() * pixel_width, (getY()+3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
				//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(.9, .7, .95);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();
			//right
				//skin
		glBegin(GL_QUADS);
		glColor3f(0.945, 0.8, 0.643);
		glVertex2i((getX()+4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
				//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(.9, .7, .95);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();

		//legs
			//left
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
			//right
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
	}
	else if (getDirection() == leftPos){
		//head
		glBegin(GL_QUADS);
		//rgb: (241, 204, 164)
		glColor3f(0.945, 0.8, 0.643);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//hair
			//base
				//top
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 1) * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 2, (getY() - 1) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 2, ((getY() - 1) * pixel_width) + pixel_width);
		glVertex2i((getX() + 1) * pixel_width, ((getY() - 1) * pixel_width) + pixel_width);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 2) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width);
		glVertex2i((getX() + 2) * pixel_width, (getY() * pixel_width) + pixel_width);
		glEnd();
				//bottom
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width * 2, (getY() + 1) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width * 2, ((getY() + 1) * pixel_width) + pixel_width);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 2) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 2) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 2) * pixel_width) + pixel_width);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 2) * pixel_width) + pixel_width);
		glEnd();
			//ponytail base
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 3) * pixel_width, (getY() - 2) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width * 3, (getY() - 2) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width * 3, ((getY() - 2) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() - 2) * pixel_width) + pixel_width * 3);
		glEnd();
			//ponytail tip
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 6) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 6) * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 6) * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 2);
		glVertex2i((getX() + 6) * pixel_width, (getY() * pixel_width) + pixel_width * 2);
		glEnd();

		//body
		//overalls
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();

		//arm (left)
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.945, 0.8, 0.643);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(.9, .7, .95);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();

		//legs
		//left
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
		//right
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
	}
	else if (getDirection() == rightPos) {
		//head
		glBegin(GL_QUADS);
		glColor3f(0.945, 0.8, 0.643);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//hair
			//base
				//top
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX()+2) * pixel_width, (getY()-1) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width * 2, (getY() - 1) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width * 2, ((getY() - 1) * pixel_width) + pixel_width);
		glVertex2i((getX() + 2) * pixel_width, ((getY() - 1) * pixel_width) + pixel_width);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 2) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width);
		glVertex2i((getX() + 2) * pixel_width, (getY() * pixel_width) + pixel_width);
		glEnd();
				//bottom
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i(getX() * pixel_width, (getY() + 1) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width * 2, (getY() + 1) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width * 2, ((getY() + 1) * pixel_width) + pixel_width);
		glVertex2i(getX() * pixel_width, ((getY() + 1) * pixel_width) + pixel_width);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i(getX() * pixel_width, (getY() + 2) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 2) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 2) * pixel_width) + pixel_width);
		glVertex2i(getX() * pixel_width, ((getY() + 2) * pixel_width) + pixel_width);
		glEnd();
			//ponytail base
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() - 1) * pixel_width, (getY() - 2) * pixel_width);
		glVertex2i(((getX() - 1) * pixel_width) + pixel_width * 3, (getY() - 2) * pixel_width);
		glVertex2i(((getX() - 1) * pixel_width) + pixel_width * 3, ((getY() - 2) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() - 1) * pixel_width, ((getY() - 2) * pixel_width) + pixel_width * 3);
		glEnd();
			//ponytail tip
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() - 2) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() - 2) * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i(((getX() - 2) * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 2);
		glVertex2i((getX() - 2) * pixel_width, (getY() * pixel_width) + pixel_width * 2);
		glEnd();

		//body
		//overalls
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();

		//arm (right)
			//skin
		glBegin(GL_QUADS);
		glColor3f(0.945, 0.8, 0.643);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
			//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(.9, .7, .95);
		glVertex2i((getX() + 2) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 2) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i((getX() + 2) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();

		//legs
		//left
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
		//right
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
	}
	else if (getDirection() == away) {
		//head
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 1) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, getY() * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width * 3, (getY() * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, (getY() * pixel_width) + pixel_width * 3);
		glEnd();

		//hair
		//base
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i(getX() * pixel_width, (getY() - 1) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width * 5, (getY() - 1) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width * 5, ((getY() - 1) * pixel_width) + pixel_width * 3);
		glVertex2i(getX() * pixel_width, ((getY() - 1) * pixel_width) + pixel_width * 3);
		glEnd();
		//ponytail base
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 3) * pixel_width, (getY() - 2) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width * 3, (getY() - 2) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width * 3, ((getY() - 2) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() - 2) * pixel_width) + pixel_width * 3);
		glEnd();
		//ponytail tip
		glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i((getX() + 6) * pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 6) * pixel_width) + pixel_width, getY() * pixel_width);
		glVertex2i(((getX() + 6) * pixel_width) + pixel_width, (getY() * pixel_width) + pixel_width * 2);
		glVertex2i((getX() + 6) * pixel_width, (getY() * pixel_width) + pixel_width * 2);
		glEnd();

		//body
		//overalls
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + (pixel_width * 3), ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();

		//arms
		//left
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.945, 0.8, 0.643);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(.9, .7, .95);
		glVertex2i(getX() * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i((getX() * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i(getX() * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();
		//right
		//skin
		glBegin(GL_QUADS);
		glColor3f(0.945, 0.8, 0.643);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width * 4);
		glEnd();
		//shirt sleeve
		glBegin(GL_QUADS);
		glColor3f(.9, .7, .95);
		glVertex2i((getX() + 4) * pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, (getY() + 3) * pixel_width);
		glVertex2i(((getX() + 4) * pixel_width) + pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glVertex2i((getX() + 4) * pixel_width, ((getY() + 3) * pixel_width) + pixel_width);
		glEnd();

		//legs
		//left
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 1) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 1) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 1) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
		//right
		glBegin(GL_QUADS);
		glColor3f(1, .3, .35);
		glVertex2i((getX() + 3) * pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, (getY() + 7) * pixel_width);
		glVertex2i(((getX() + 3) * pixel_width) + pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glVertex2i((getX() + 3) * pixel_width, ((getY() + 7) * pixel_width) + pixel_width * 3);
		glEnd();
	}
}