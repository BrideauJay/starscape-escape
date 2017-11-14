#include "Player.h"
#include "graphics.hpp"
#include "Level.h"
#include <iostream>

using namespace std;

//void Player::moveLeft() {
	//xCurrentSpeed = 1;
	//charDirection = left;
	//setX(getX() - xCurrentSpeed);
//}
//void Player::moveRight() {
	//xCurrentSpeed = 1;
	//charDirection = right;
	//setX(getX() + xCurrentSpeed);
//}
void Player::handleXMove() {
	if (xCurrentSpeed != 0) {
		if (xCurrentSpeed < 0) {
			charDirection = leftPos;
		}
		else {
			charDirection = rightPos;
		}
		setX(getX() + xCurrentSpeed);
	}
}
void Player::setXMove(int i) {
	xCurrentSpeed = i;
}
void Player::jump() {
	yCurrentSpeed = -12;
	setY(getY() + yCurrentSpeed);
 }

void Player::follow(Player* p) {
	int followX = p->getX();
	int followY = p->getY();

}