/*
 * Turret.h
 *
 *  Created on: Jan 18, 2022
 *      Author: steve
 */

#ifndef TURRET_H_
#define TURRET_H_

#include "ServoWrapper.h"

#define SERVO_STRAIGHT 100

class Turret {
	private:
		ServoWrapper* servoWrapper;
		int currentAngle = SERVO_STRAIGHT;
		void toAngle(int targetAngle);
		void rightToAngle(int targetAngle);
		void leftToAngle(int targetAngle);

	public:
		Turret(unsigned int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();


};

#endif /* TURRET_H_ */
