#ifndef player_h
#define player_h

#include "Character.h"
#include "Screen.h"

class Player : public Character {
public:
	//virtual void moveLeft();
	//virtual void moveRight();
	virtual void handleXMove();

	virtual void setXMove(int i);

	virtual void draw() = 0;

	virtual void jump();

	virtual void follow(Player* p);

	int xTargetSpeed = 1;
	int yTargetSpeed = 0;
	int xCurrentSpeed = 0;
	int yCurrentSpeed = 1;
	int gravitySpeed;

	Screen thisCurrentScreen;

protected:
	int pixel_width;


};

#endif