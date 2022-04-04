states:
initial
startSignalInProgress
readyToDrive
driving
stopped
stoppedNeedPivot



Decider
inputs:
state
sensedObstacleDistances (ahead, left, right) # if ahead is good, no need to sense/set left and right)

outputs:
state
