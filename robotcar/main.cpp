/*
 * main.cpp
 *
 *  Created on: Jan 19, 2022
 *      Author: steve
 */
#include "Mode.h"
#include "TurretMock.h"
#include "DriveMock.h"
#include "Pinger.h"
#include "PingerMock.h"
#include "State.h"
#include "Controller.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;


Turret* turret;
Drive* drive;
Pinger* pinger;
Controller* controller;

int main() {
	turret = new TurretMock();
	  drive = new DriveMock();
	  pinger = new PingerMock(4, 5);

	controller = new Controller(turret, drive, pinger);
	State state = controller->setup();

	state = controller->loop(initial);
	cout << "loop(initial): " << state << endl;

	state = controller->loop(driving);
	cout << "loop(driving): " << state << endl;

	state = controller->loop(stopped);
	cout << "loop(stopped): " << state << endl;
}



