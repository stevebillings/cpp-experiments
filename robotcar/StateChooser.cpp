#include "State.h"
#include "StateChooser.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;

State StateChooser::choose(State currentState) {
	return initial;
}

State StateChooser::choose(State currentState, int inchesClearAhead) {

	return initial;
}

State StateChooser::choose(State currentState, int inchesClearAhead, int inchesClearLeft, int inchesClearRight) {

	return initial;
}
