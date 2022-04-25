#ifndef NEWTURRETREAL_H_
#define NEWTURRETREAL_H_

#include "ServoWrapper.h"
#include <Servo.h>

class NewTurretReal : public NewTurret {
	private:
		ServoWrapper* servoWrapper;
		int currentAngle;
		int minAngle;
		int maxAngle;
		void toAngle(int targetAngle);

	public:
		NewTurretReal(unsigned int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();
};

#endif /* NEWTURRETREAL_H_ */
