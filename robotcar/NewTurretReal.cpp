#include "Mode.h"

#include <Arduino.h>
#include "NewTurret.h"
#include "ServoWrapper.h"

#define SERVO_STRAIGHT 100
#define SERVO_LEFT 180
#define SERVO_RIGHT 10
#define SHORT_DELAY 25
#define LEFT_TO_RIGHT_DELTA -4
#define RIGHT_TO_LEFT_DELTA 4

NewTurretReal::NewTurretReal(unsigned int pwmPin) {
	servoWrapper = new ServoWrapper(pwmPin); // TODO delete this in dtor
	currentAngle = SERVO_STRAIGHT;
	minAngle = currentAngle;
	maxAngle = currentAngle;
}

void NewTurretReal::aimRight() {
	toAngle(SERVO_RIGHT);
}

void NewTurretReal::aimLeft() {
	toAngle(SERVO_LEFT);
}

void NewTurretReal::aimStraight() {
	toAngle(SERVO_STRAIGHT);
}

// private

void NewTurretReal::toAngle(int targetAngle) {
	servoWrapper->write(targetAngle);
        delay(750);
}
