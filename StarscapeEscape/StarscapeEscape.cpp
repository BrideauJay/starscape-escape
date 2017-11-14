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
Screen screen01;
Screen screen02;
Screen screen03;
Screen current_screen;
int wd;
Platform p, p2, p3;
Player* active_player;
Player* follower1;
Player* follower2;
Allison allison;
Bee bee;
Caleb caleb;

void init() {
	lvl1 = Level(1);
	width = lvl1.width;
	height = lvl1.height;
	pixel_width = lvl1.pixel_width;

	screen01 = Screen(width, height, pixel_width);
	screen01.addPixelCluster(20, 25, 10, 15, 1, 0, 0);

	screen02 = Screen(width, height, pixel_width);
	screen02.addPixelCluster(50, 70, 20, 40, 0, 1, 0);

	screen03 = Screen(width, height, pixel_width);
	screen03.addPixelCluster(5, 25, 40, 45, 0, 0, 1);

	p = Platform(15, width, 20, pixel_width);
	p2 = Platform(0, 15, 35, pixel_width);
	p3 = Platform(17, 5, 40, pixel_width);
	screen01.addPlatform(p);
	screen01.addPlatform(p2);
	screen01.addPlatform(p3);

	Platform p4 = Platform(0, width, 20, pixel_width);
	screen02.addPlatform(p4);

	Platform p5 = Platform(0, 20, 20, pixel_width);
	screen03.addPlatform(p5);

	Platform p6 = Platform(25, 30, 30, pixel_width);
	screen03.addPlatform(p6);

	lvl1.addScreen(screen01);
	lvl1.addScreen(screen02);
	lvl1.addScreen(screen03);
	allison = Allison(15, 5, pixel_width);
	bee = Bee(25, 5, pixel_width);
	caleb = Caleb(35, 5, pixel_width);
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

	allison.draw();
	bee.draw();
	caleb.draw();

	allison.handleXMove();
	bee.handleXMove();
	caleb.handleXMove();

	glFlush();  // Render now
}

void kbd(unsigned char key, int x, int y)
{
	cout << "a: " << GetAsyncKeyState('A') << endl;
	cout << "d: " << GetAsyncKeyState('D') << endl;
	//move left
	if (key == 'A' || key == 'a') {
		if (active_player->getX() > 0) {
			active_player->setXMove(-1);
		}
		else if (lvl1.getCurrentScreenNum() != 0) {
			lvl1.screen_left();
			active_player->setX(120 - active_player->getCharWidth());
		}
		else {
			active_player->setXMove(0);
		}
	}
	//move right
	if (key == 'D' || key == 'd') {
		if ((active_player->getX() + active_player->getCharWidth()) < 120 ){
			active_player->setXMove(1);
		}
		else if (lvl1.getCurrentScreenNum() < lvl1.screens.size()-1){
			lvl1.screen_right();
			active_player->setX(0);
		}
		else {
			active_player->setXMove(0);
		}
	}
	//jump
	if (key == ' ') {
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
	}

	glutPostRedisplay();

	return;
}

void timer(int extra) {

	allison.gravity(lvl1.getCurrentScreen().platforms);
	bee.gravity(lvl1.getCurrentScreen().platforms);
	caleb.gravity(lvl1.getCurrentScreen().platforms);

	//if player not actively moving left or right AND on solid ground, stop side-to-side movement
	if (GetAsyncKeyState('A') == 0 && GetAsyncKeyState('D') && active_player->solid == true) {
		active_player->setXMove(0);
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