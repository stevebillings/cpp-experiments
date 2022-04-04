#include "State.h"
#include "StateChooser.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;

StateChooser *stateChooser;

int main() {
	printf("StateChooserTest starting up\n");
	stateChooser = new StateChooser();
	printf("StateChooserTest result: %d\n", stateChooser->choose(initial));
}
