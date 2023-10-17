% File script che rappresenta una delle seguenti funzioni:
%
%    y = x^3-3x              per    -3 <= x <=3     
%    y = 3xcos(2x)           per     0 <= x <= 2pi   
%    y = sin(x)/x            per  -8pi <= x <= 8pi
%
% scelta dall'utente (struttura switch)
clc
clear all
disp('Lo script grafica una funzione scelta');
disp('dall"utente tra le seguenti:');disp(' ');
disp('      1) y = x^3-3x             per  -3 <= x <=3');
disp('      2) y = 3x cos(2x)          per  0 <= x <= 2pi');
disp('      3) y = sin(x)/x           per  -8pi <= x <= 8pi');
scelta = input('\nScegliere una tra le funzioni indicate, digitandone il numero: ');

switch scelta
    
case 1
    f=@(x) x.^3-3*x;
    x = [-3:0.05:3];
    y = f(x);
    plot(x,y,'r')
    grid on
    xlabel('x'); ylabel('y');
    title('Grafico della funzione 1');
    legend('y=x^3-3*x');
    
case 2
    f=@(x) 3*x.*cos(2*x);
    x = [0:pi/50:2*pi];
    y = f(x);
    plot(x,y,'b')
    grid on
    xlabel('x'); ylabel('y');
    title('Grafico della funzione 2');
    legend('y=3*x*cos(2x)');
    
case 3
    f=@(x) sin(x)./x;
    x = [-8*pi:pi/50:8*pi];
    y = f(x);
    plot(x,y,'m')
    grid on
    xlabel('x'); ylabel('y');
    title('Grafico della funzione 3');
    legend('y=sin(x)/x'); 
    
end  