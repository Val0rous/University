clc
clear all

% Confrontare i risultati delle operazioni (0.3 - 0.2)-0.1 e 0.3-(0.2 + 0.1) 
% fornire una spiegazione a quanto osservato.

format long e 

disp('......esempio 1......')
x = 0.1;
y = 0.2;
z = 0.3;

ris1=(z-y)-x
ris2=z-(y+x)

%ris1= fl( fl(fl(0.3)-fl(0.2)) - fl(0.1) ) = -2^(-55) = -2.775558e-17
%ris2= fl( fl(0.3) - fl(fl(0.2)+fl(0.1)) ) = -2^(-54) = -5.551115e-17
%..................................................
 
disp('......esempio 2......')
x = 0.1;
y = 0.2;
z = 0.5;

ris3=x*(y+z) 
ris4=x*y+x*z
 
% ris3= fl( fl(x) * fl(fl(y)+fl(z)) )
% ris4= fl( fl(fl(x)*fl(y)) + fl(fl(x)*fl(z)) )
