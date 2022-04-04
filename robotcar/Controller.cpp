#include "Mode.h"
#include "Mock.h"
#include "Turret.h"
#include "Drive.h"
#include "Pinger.h"
#include "State.h"
#include "Controller.h"
#include <iostream>
using namespace std;

#define OBSTACLE_SAFE_DIST_INCHES 6
#define START_SIGNAL_DIST_INCHES 2


State state = initial;
int stuckCount = 0;

Controller::Controller(Turret* turret, Drive* drive, Pinger* pinger) {
  this->turret = turret;
  this->drive = drive;
  this->pinger = pinger;
}

State Controller::setup() {
	return state;
}

State Controller::loop(State state) {
  StateNamer* stateNamer = new StateNamer();
  int sensedObstacleDistInches = pinger->getObstacleDistanceInches();
  cout << "Old state: " << stateNamer->getStateName(state) << endl;
  switch (state) {
    case initial:
      if (pingSensorBlocked(sensedObstacleDistInches)) {
        state = startSignalInProgress;
        ledBlink(LED_BUILTIN, 1);
      }
      break;
    case startSignalInProgress:
      if (pathIsClear(sensedObstacleDistInches)) {
        state = readyToDrive;
      }
      break;
    case stopped:
      if (pathIsClear(sensedObstacleDistInches)) {
        state = readyToDrive;
      } else {
        Direction safeDirection = getSafeDirection();
	cout << "Got safe dir: " << getDirectionName(safeDirection) << endl;
        if (safeDirection == Direction::left) {
          drive->turnLeft();
        } else if (safeDirection == Direction::right) {
          drive->turnRight();
        } else if (safeDirection == Direction::straight) {
          state = readyToDrive;
        } else {
          drive->turnAround();
          stuckCount++;
          if (stuckCount > 4) {
            state = initial;
            stuckCount = 0;
          }
        }
      }
      break;
    case readyToDrive:
      if (pathIsClear(sensedObstacleDistInches)) {
        drive->startForward();
        state = driving;
        stuckCount = 0;
      }
      break;
    default: // driving
      if (pathIsClear(sensedObstacleDistInches)) {
        stuckCount = 0;
      } else {
        drive->stop();
        state = stopped;
      }
  }
  cout << "New state: " << stateNamer->getStateName(state) << endl;
  return state;
}


bool Controller::pingSensorBlocked(int sensedObstacleDistInches) {
  return sensedObstacleDistInches < START_SIGNAL_DIST_INCHES;
}

bool Controller::pathIsClear(int sensedObstacleDistInches) {
  return sensedObstacleDistInches > OBSTACLE_SAFE_DIST_INCHES;
}

void Controller::ledBlink(int pin, int numBlinks) {
  for (int i=0; i<numBlinks; i++) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
  }
}

Direction Controller::getSafeDirection() {
  int leftDistance = 0;
  int rightDistance = 0;

  cout << "Aiming right" << endl;
  turret->aimRight();
  rightDistance = pinger->getObstacleDistanceInches();

  cout << "Aiming left" << endl;
  turret->aimLeft();
  leftDistance = pinger->getObstacleDistanceInches();
  
  cout << "Aiming straight" << endl;
  turret->aimStraight();

  if (leftDistance > rightDistance) {
    if (pathIsClear(leftDistance)) {
      return Direction::left;
    }
  } else {
    if (pathIsClear(rightDistance)) {
      return Direction::right;
    }
  }

  return none;
}

// TODO: move to Direction
const char * Controller::getDirectionName(Direction dir) {
  const char *p;
  switch(dir) {
    case Direction::left:
	p = "left";
	break;
    case Direction::right:
	p = "right";
	break;
    case Direction::straight:
	p = "straight";
	break;
    default:
        p = "UNKNOWN";
  }
  return p;
}
