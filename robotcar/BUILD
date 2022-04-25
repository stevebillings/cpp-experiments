cc_test(
  name = "bot",
  size = "small",
  srcs = ["main.cpp", "State.h", "StateNamer.h", "StateChooser.h", "StateNamer.cpp", "StateChooser.cpp",
		"Controller.h", "Controller.cpp", "Drive.h", "DriveMock.h", "DriveMock.cpp", "Mock.h", "Pinger.h",
		"PingerMock.h", "PingerMock.cpp",
		"Turret.h", "TurretMock.h", "TurretMock.cpp"
		],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_test(
  name = "statechoosertest",
  size = "small",
  srcs = ["StateChooserTest.cpp", "StateChooser.cpp", "StateChooser.h", "State.h", "StateNamer.h", "StateNamer.cpp"],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_test(
  name = "hello_test",
  size = "small",
  srcs = ["hello_test.cpp"],
  deps = ["@com_google_googletest//:gtest_main"],
)
