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


Turret turret(9);

int main() {
	cout << "Starting main.cpp:" << endl;
	turret.aimLeft();
	turret.aimRight();
	turret.aimLeft();
	turret.aimStraight();
	turret.report();
}



