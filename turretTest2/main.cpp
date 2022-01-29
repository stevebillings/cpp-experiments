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
#include "Pinger.h"
#include "Drive.h"


Turret turret(9);
Pinger pinger(10, 11);
Drive drive;

int main() {
	turret.aimLeft();
	int dist = pinger.getObstacleDistanceInches();
	printf("Left obstacle dist: %d\n", dist);
	turret.aimStraight();dist = pinger.getObstacleDistanceInches();
	printf("Straight obstacle dist: %d\n", dist);
	drive.startForward();
	drive.stop();


	turret.aimRight();
	dist = pinger.getObstacleDistanceInches();
	printf("Right obstacle dist: %d\n", dist);


	turret.aimStraight();
	dist = pinger.getObstacleDistanceInches();
	printf("Straight obstacle dist: %d\n", dist);
	turret.report();
}



