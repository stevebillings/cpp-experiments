/*
 * main.cpp
 *
 *  Created on: Jan 19, 2022
 *      Author: steve
 */
#include "Mode.h"
#include <iostream>
using namespace std;
#include "Turret.h"

#ifdef FAKE
#include "Servo.h"
#else
#include <Servo.h>
#endif

Servo servo;

Turret turret(&servo, 9);

int main() {
	cout << "Starting main.cpp:" << endl;
	turret.aimLeft();
	turret.aimRight();
	turret.aimLeft();
	turret.aimStraight();
	turret.report();
}



