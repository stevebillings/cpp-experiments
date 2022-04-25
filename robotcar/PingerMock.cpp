#include "PingerMock.h"
#include <iostream>
using namespace std;

PingerMock::PingerMock(unsigned int triggerPin, unsigned int echoPin) {
}

int PingerMock::getObstacleDistanceInches() {
  cout << "PingerMock.getObstacleDistanceInches() called; returning 20" << endl;
  return 20;
}

PingerMock::~PingerMock() {
  cout << "PingerMock destructor called" << endl;
}
