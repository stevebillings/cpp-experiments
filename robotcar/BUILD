cc_test(
  name = "bot",
  size = "small",
  srcs = ["main.cpp", "Mode.h", "Controller.h", "Controller.cpp", "Drive.h", "Drive.cpp", "Mock.h", "Pinger.h", "Pinger.cpp",
		"PingerMock.h", "PingerMock.cpp",
		"Servo.h", "Servo.cpp", "ServoWrapper.h", "ServoWrapper.cpp", "Turret.h", "Turret.cpp"],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_test(
  name = "hello_test",
  size = "small",
  srcs = ["hello_test.cpp"],
  deps = ["@com_google_googletest//:gtest_main"],
)
