/*
 * Controller.h
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

enum State {initial, startSignalInProgress, readyToDrive, driving, stopped};
enum Direction {left, straight, right, none};

class Controller {
	public:
    	Controller(Turret* turret, Drive* drive, Pinger* pinger);
		State setup();
		State loop(State state);
	private:
		Turret* turret;
		Drive* drive;
		Pinger* pinger;
		bool pingSensorBlocked(int sensedObstacleDistInches);
		bool pathIsClear(int sensedObstacleDistInches);
		void ledBlink(int pin, int numBlinks);
		Direction getSafeDirection();
};

#endif /* CONTROLLER_H_ */