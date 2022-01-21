/*
 * ServoWrapper.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: steve
 */
#include <iostream>
using namespace std;
#include "ServoWrapper.h"

ServoWrapper::ServoWrapper(unsigned int pwmPin) {
	cout << "ServoWrapper ctor passed pin: " << pwmPin << endl;
	// servo.attach(pwmPin);
}

void ServoWrapper::write(unsigned int targetAngle) {
	cout << "ServoWrapper::write() passed targetAngle: " << targetAngle << endl;
	// servo.write(targetAngle);
}



