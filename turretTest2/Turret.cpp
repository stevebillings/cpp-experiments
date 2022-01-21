/*
 * Turret.cpp
 *
 *  Created on: Jan 18, 2022
 *      Author: steve
 */
#include <iostream>
using namespace std;
#include "Turret.h"

#define SERVO_LEFT 180
#define SERVO_RIGHT 10
#define SHORT_DELAY 25
#define LEFT_TO_RIGHT_DELTA -1
#define RIGHT_TO_LEFT_DELTA 1

Turret::Turret(unsigned int pwmPin) {
	cout << "Turret ctor passed pin: " << pwmPin << endl;
	cout << "Turret ctor: currentAngle: " << currentAngle << endl;
	servoWrapper = new ServoWrapper(pwmPin); // TODO delete this in dtor
	currentAngle = SERVO_STRAIGHT;
}

void Turret::aimRight() {
	toAngle(SERVO_RIGHT);
}

void Turret::aimLeft() {
	toAngle(SERVO_LEFT);
}

void Turret::aimStraight() {
	toAngle(SERVO_STRAIGHT);
}

// private

void Turret::toAngle(int targetAngle) {
	if (currentAngle > targetAngle) {
		rightToAngle(targetAngle);
	} else if (currentAngle < targetAngle) {
		leftToAngle(targetAngle);
	}
}

void Turret::rightToAngle(int targetAngle) {
	cout << "Moving right:" << endl;
	for (; currentAngle >= targetAngle; currentAngle += LEFT_TO_RIGHT_DELTA) {
		servoWrapper->write(currentAngle);
		//delay(SHORT_DELAY);
	}
	currentAngle -= LEFT_TO_RIGHT_DELTA;
	cout << "Done moving right" << endl;
}

void Turret::leftToAngle(int targetAngle) {
	cout << "Moving left:" << endl;
	for (; currentAngle <= targetAngle; currentAngle += RIGHT_TO_LEFT_DELTA) {
		servoWrapper->write(currentAngle);
		//delay(SHORT_DELAY);
	}
	currentAngle -= RIGHT_TO_LEFT_DELTA;
	cout << "Done moving left" << endl;
}





