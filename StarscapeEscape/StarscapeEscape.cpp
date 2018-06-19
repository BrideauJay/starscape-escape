#include "graphics.hpp"
#include "Character.h"
#include "Player.h"
#include "Level.h"
#include "Platform.h"
#include "Allison.h"
#include "Bee.h"
#include "Caleb.h"

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

int width, height, pixel_width;
Level lvl1;
Screen current_screen;
int wd;
Player* active_player;
Player* follower1;
Player* follower2;
Allison allison;
Bee bee;
Caleb caleb;

void init() {
	lvl1 = Level(1);
	width = 960;
	height = 640;
	pixel_width = lvl1.pixel_width;

	allison = Allison(15, 5, pixel_width);
	bee = Bee(25, 5, pixel_width);
	caleb = Caleb(35, 5, pixel_width);

	allison.charCurrentScreen = lvl1.getCurrentScreen();
	bee.charCurrentScreen = lvl1.getCurrentScreen();
	caleb.charCurrentScreen = lvl1.getCurrentScreen();

	active_player = &allison;
	follower1 = &bee;
	follower2 = &caleb;
}

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // almost black and opaque

}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	// tell OpenGL to use the whole window for drawing
	glViewport(0, 0, width, height);

	// do an orthographic parallel projection with the coordinate
	// system set to first quadrant, limited by screen/window size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	lvl1.getCurrentScreen().draw();

	if (follower2->charCurrentScreen.screenid == lvl1.getCurrentScreen().screenid) {
		follower2->draw();
	}
	if (follower1->charCurrentScreen.screenid == lvl1.getCurrentScreen().screenid) {
		follower1->draw();
	}	
	if (active_player->charCurrentScreen.screenid == lvl1.getCurrentScreen().screenid) {
		active_player->draw();
	}

	allison.handleXMove();
	bee.handleXMove();
	caleb.handleXMove();

	glFlush();  // Render now
}

void kbd(unsigned char key, int x, int y) //CHECK MORE OFTEN 
//only checks when key registers as pressed, overrides 'old' keypress data even if current
{
	//jump
	if (key == 32) {
		active_player->jump();
	}
	//look at user
	if (key == 'S' || key == 's') {
		active_player->setDirection(user);
	}
	//look away from user
	if (key == 'W' || key == 'w') {
		active_player->setDirection(away);
	}

	//switch players (REPLACE WITH MENU)
	if (key == 'Q' || key == 'q') {
		if (active_player == &allison) {
			active_player = &bee;
			follower1 = &caleb;
			follower2 = &allison;
		}
		else if (active_player == &bee){
			active_player = &caleb;
			follower1 = &allison;
			follower2 = &bee;
		}
		else {
			active_player = &allison;
			follower1 = &bee;
			follower2 = &caleb;
		}
		//get the screen the active player is on, and display it
		current_screen = active_player->charCurrentScreen;
		lvl1.setCurrentScreen(current_screen);
	}

	glutPostRedisplay();

	return;
}

void timer(int extra) {

	//LEFT AND RIGHT MOVEMENT

	//register A press/left movement
	if (GetAsyncKeyState(0x41) != 0) {
		if (active_player->getX() > 0) {
			active_player->setXMove(-1);
		}
		else if (lvl1.getCurrentScreenNum() != 0) {
			lvl1.screen_left();
			active_player->setX(120 - active_player->getCharWidth());
			active_player->setXMove(-1);
			active_player->charCurrentScreen = lvl1.getCurrentScreen();
		}
		else {
			active_player->setXMove(0);
		}
	}
	//register d press/right movement
	else if (GetAsyncKeyState(0x44) != 0) {
		if ((active_player->getX() + active_player->getCharWidth()) < 120) {
			active_player->setXMove(1);
		}
		else if (lvl1.getCurrentScreenNum() < lvl1.screens.size() - 1) {
			lvl1.screen_right();
			active_player->setX(0);
			active_player->setXMove(1);
			active_player->charCurrentScreen = lvl1.getCurrentScreen();
		}
		else {
			active_player->setXMove(0);
		}
	} else {
		active_player->setXMove(0);
	}

	if (allison.charCurrentScreen.screenid == lvl1.getCurrentScreen().screenid) {
		allison.gravity(lvl1.getCurrentScreen().platforms);
	}
	if (bee.charCurrentScreen.screenid == lvl1.getCurrentScreen().screenid) {
		bee.gravity(lvl1.getCurrentScreen().platforms);
	}
	if (caleb.charCurrentScreen.screenid == lvl1.getCurrentScreen().screenid) {
		caleb.gravity(lvl1.getCurrentScreen().platforms);
	}

	glutTimerFunc(60, timer, 0);
	glutPostRedisplay();
}


/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

	init();

	glutInit(&argc, argv);          // Initialize GLUT

	glutInitDisplayMode(GLUT_RGBA);

	glutInitWindowSize((int)width, (int)height);
	glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
									  /* create the window and store the handle to it */
	wd = glutCreateWindow("Starscape Escape (Debug Build)" /* title */);

	// Register callback handler for window re-paint event
	glutDisplayFunc(display);

	// Our own OpenGL initialization
	initGL();

	// register keyboard press event processing function
	// works for numbers, letters, spacebar, etc.
	glutKeyboardFunc(kbd);

	// handles timer
	glutTimerFunc(0, timer, 0);

	// Enter the event-processing loop
	glutMainLoop();
	return 0;
}