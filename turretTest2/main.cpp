/*
 * main.cpp
 *
 *  Created on: Jan 19, 2022
 *      Author: steve
 */
#include <iostream>
using namespace std;
#include "Turret.h"

Turret turret(9);

int main() {
	cout << "Starting test:" << endl;
	turret.aimLeft();
	turret.aimRight();
	turret.aimLeft();
	turret.aimStraight();
}



