clear all, close all

% ROBOTICA (FDI)
% Ejemplo de robot navegando por una habitación.
% -------------------------------------------------------

% ENTRADAS:

% Mapa: no sabemos nada
M=zeros(500,500);  % Objetos = 1, vacio 0


% --------- Modelo del Robot ------------------------------------------
rob.Nc=100;                           % Pulsos de Encode por vuelta 
rob.Rb=5;                             % Radio de las ruedas (cm)
rob.b=10;                             % Distancia entre ejes (cm)
% ****** RELLENAR ******
rob.x(1)=350; rob.y(1)=190;     % Posición inicial del robot
rob.theta(1)=90*pi/180;            % Orientación inicial del robot
% --------------------------------------------------------------------------

% Readings of encoder sensors (Nl, letf encoder, Nr right encoder):
E=load("encoder.dat");
Nl=E(:,1);
Nr=E(:,2);
% Para tener el movimiento del robot carge el archivo de datos: Encoder.dat
% ****** RELLENAR ******

%---------------------------------------------------------------------------------

% Dibujar el mapa inicial
figure(1)
image(M, 'CDataMapping','scaled')
axis xy
hold on;

% Pintar el robot en la posición inicial: 
xRobCelda(1)=rob.x(1); yRobCelda(1)=rob.y(1); % celda donde está el robot

figure(1)
V=paintRobot([rob.x(1),rob.y(1)],rob.theta(1),[10,20]);
r=fill(V(1,:),V(2,:),[0.100 0.100 0.100]);

pause;

% --------------------------------------------------------------------
% Movimiento del robot:

for i=1:length(Nl)
    
% ----- Calcular nueva posición del robot ----------    

% ****** RELLENAR ******
% La nueva posición del robot depende de la anterior y 
% de cuanto se haya movido (cuenta del encoder)
% Modificar adecuadamente:



di=((2*pi*rob.Rb) / rob.Nc) * Nl(i);

dd=((2*pi*rob.Rb) / rob.Nc) * Nr(i);

dif = (di+dd) / 2;

v = (dd-di) / rob.b;

rob.x(i+1)= rob.x(i)+ (dif * cos(rob.theta(i)));
rob.y(i+1)= rob.y(i)+ (dif * sin(rob.theta(i)));
rob.theta(i+1)= rob.theta(i) + v;

% ---------------------------------------------------------


% ------ Emite señal de ultrasonidos hacia delante --------------
% ****** RELLENAR ******
for h=0:361
thetaScan=h*pi/180; % Dirección donde apunta el sonar respecto a orientación de robot
[rangeObj,pts]=sonar(rob,thetaScan);
if (rangeObj>0), figure(1), plot(pts(:,1),pts(:,2),'.r'); end   
end

% --------------------------------------

% ------- Draw Robot -------------------
figure(1)
r=fill(V(1,:),V(2,:),[0 0 0]); % Clear the last robot 
% Draw new robot 
V=paintRobot([rob.x(i+1),rob.y(i+1)],rob.theta(i+1),[20,10]);
r=fill(V(1,:),V(2,:),[0.100 0.100 0.100]); 
% --------------------------------------

pause(0.1)

end



