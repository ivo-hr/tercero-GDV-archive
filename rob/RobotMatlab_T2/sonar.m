function [rangeObj,arc]=sonar(rob, beta, sensor),
% Finding if there are objects round the robot
%
% [rangeObj,arc]=sonar(rob, beta, sensor),
% 
% rangeObj  Distance to the nearest object (-1 when no object)
% arc       Points could be objects
%
% rob       Robot model
% beta      Orient of the sonar sensor (in relation to course robot)
% sensor   Sensor model (optional)