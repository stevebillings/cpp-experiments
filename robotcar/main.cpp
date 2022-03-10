/*
 * main.cpp
 *
 *  Created on: Jan 19, 2022
 *      Author: steve
 */
#include "Mode.h"
#include "Turret.h"
#include "Drive.h"
#include "Pinger.h"
#include "Controller.h"
#include <iostream>
using namespace std;


Turret* turret;
Drive* drive;
Pinger* pinger;
Controller* controller;

int main() {
	turret = new Turret(9);
	  drive = new Drive();
	  pinger = new Pinger(4, 5);

	controller = new Controller(turret, drive, pinger);
	controller->setup();
	controller->loop();
}



