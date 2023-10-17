clc
clear all
close all
%sistema 2

A=[5 10; 2 1];
b=[15; 1];

x=A\b    %soluzione del sistema 

%perturbo il coeff. di x della seconda equazione:
dA=[0 0.1; 0 0];

disp('errore relativo sui dati')
errore_dati=norm(dA,inf)/norm(A,inf);    %errore percentuale=0.66%
errore_dati_perc=errore_dati*100

%soluzione del sistema perturbato:
x1=(A+dA)\b

disp('errore relativo sulla soluzione') 
errore_sol=norm(x-x1,inf)/norm(x,inf); %errore percentuale=1.3%
errore_sol_perc=errore_sol*100
%quindi ad una piccola perturbazione sui dati corrisponde una piccola
%perturbazione sui risultati --> problema ben condizionato

%INTERPRETAZIONE GEOMETRICA:
%La soluzione del sistema lineare e' il punto di intersezione tra le due rette

f1=@(x) (15-5*x)/10;  %5*x+10*y=15
f2=@(x) (1-2*x);  %2*x+y=1
f1_p=@(x) (15-5*x)/10.1;

xv=linspace(-2,2,100);


figure(1)
hold on
plot(xv,f1(xv),'b-',xv,f2(xv),'r--',x(1),x(2),'ko')

figure(2)
hold on
plot(xv,f1_p(xv),'b-',xv,f2(xv),'g--',x(1),x(2),'ko')

%....................................................................

