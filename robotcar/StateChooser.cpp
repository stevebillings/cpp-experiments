#include "State.h"
#include "StateChooser.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;

State StateChooser::choose(State currentState) {
	return readyToDrive;
}
