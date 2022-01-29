/*
 * Servo.cpp
 *
 *  Created on: Jan 28, 2022
 *      Author: steve
 */
#include <iostream>
using namespace std;

#include "Servo.h"

void Servo::attach(unsigned int pin) {
	printf("Servo.attach(%d)\n", pin);
}

void Servo::write(unsigned int angle) {
	printf("Servo.write(%d)\n", angle);
}



