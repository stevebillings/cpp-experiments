#include "State.h"
#include "StateChooser.h"
#include "StateNamer.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;

StateChooser *stateChooser;
StateNamer *stateNamer;

//int test() {
//	printf("StateChooserTest starting up\n");
//	stateChooser = new StateChooser();
//	stateNamer = new StateNamer();
//	State newState = stateChooser->choose(initial);
//	printf("StateChooserTest result: %s\n", stateNamer->getStateName(newState));
//	return 0;
//}

TEST(StateChooserTest, BasicAssertions) {
	stateChooser = new StateChooser();
	stateNamer = new StateNamer();
	State newState = stateChooser->choose(initial);
	EXPECT_EQ(initial, newState);

  //EXPECT_STRNE("hello", "world");
  //EXPECT_EQ(7 * 6, 42);
  //EXPECT_STREQ("hello", "hello");
}
