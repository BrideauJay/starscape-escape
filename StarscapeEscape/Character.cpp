#include "Character.h"
#include "graphics.hpp"

using namespace std;

int Character::getX() {
	return xcoord;
}

int Character::getY() {
	return ycoord;
}


void Character::setX(int x) {
		xcoord = x;
}

void Character::setY(int y) {
		ycoord = y;
}

void Character::gravity(vector<Platform> platforms) {
	//is there solid ground under the player?
	solid = false;
	for (Platform p : platforms) {
		//if the block under at least one of the character's feet isn't a platform,
		if (
			//pixel under left foot is a platform
			(p.contains((getX() + 1), (getY() + charheight)))
			//pixel under right foot is a platform
			|| (p.contains((getX() + 3), (getY() + charheight)))
			) {
			//set solid to true
			solid = true;}
	}

	//if conditions not met, fall
	if (!solid) {
		setY(getY() + gravitySpeed);
		if (yCurrentSpeed < gravitySpeed) {
			yCurrentSpeed += gravitySpeed;
		}
		else {
			yCurrentSpeed = gravitySpeed;
		}
		
	}
	
}

direction Character::getDirection() {
	return charDirection;
}

void Character::setDirection(direction d) {
	charDirection = d;
}

int Character::getCharHeight() {
	return charheight;
}

int Character::getCharWidth() {
	return charwidth;
}