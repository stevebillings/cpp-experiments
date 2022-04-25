
class PingerMock : public Pinger {
	public:
		PingerMock(unsigned int triggerPin, unsigned int echoPin);
		int getObstacleDistanceInches() override;
		~PingerMock();
	private:
};
