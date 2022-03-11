#include "Mode.h"
#include "Mock.h"
#include "Turret.h"
#include "Drive.h"
#include "Pinger.h"
#include "Controller.h"

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

  int sensedObstacleDistInches = pinger->getObstacleDistanceInches();
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
        if (safeDirection == left) {
          drive->turnLeft();
        } else if (safeDirection == right) {
          drive->turnRight();
        } else if (safeDirection == straight) {
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

  turret->aimRight();
  rightDistance = pinger->getObstacleDistanceInches();

  turret->aimLeft();
  leftDistance = pinger->getObstacleDistanceInches();
  
  turret->aimStraight();

  if (leftDistance > rightDistance) {
    if (pathIsClear(leftDistance)) {
      return left;
    }
  } else {
    if (pathIsClear(rightDistance)) {
      return right;
    }
  }

  return none;
}