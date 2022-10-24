function vRobotMap=paintRobot(posRobotXY,thetaRobot,tam,scale),
%
% Get points of robot in order to draw it using the fill fuction 
%
% vRobotMap=paintRobot(posRobotXY,thetaRobot,tam,scale);
%
% posRobotXY:   Position (x,y), center of robot (cm)
%               x are columns, y are rows.
% tethaRobot:   Course of robot (to x) (rad)
% optional params:
%       tam:    size of robot (lengthxwidth), by default (10x10)
%       scale: scale of map, by default (1 pixel = 1 cm.)
