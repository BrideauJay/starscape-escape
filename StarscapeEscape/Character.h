#ifndef character_h
#define character_h

#include <vector>
#include <memory>
#include "Platform.h"

using namespace std;

enum direction{leftPos, rightPos, user, away};

class Character {
public:

	//virtual void moveLeft() = 0;
	//virtual void moveRight() = 0;

	virtual void gravity(vector<Platform> platforms);

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);

	virtual void draw() = 0;

	//get character's direction
	direction getDirection();

	void setDirection(direction d);

	int getCharHeight();
	int getCharWidth();

	//acceleration variables
	int xTargetSpeed;
	int yTargetSpeed;
	int xCurrentSpeed;
	int yCurrentSpeed;
	int gravitySpeed = 1;

	//is there solid ground under the player
	bool solid;

protected:
	//x and y coords are for top left corner of box containing whole character
	int xcoord;
	int ycoord;

	//dimensions of character
	int charheight;
	int charwidth;

	//direction character is facing, for drawing
	direction charDirection;
};


#endif