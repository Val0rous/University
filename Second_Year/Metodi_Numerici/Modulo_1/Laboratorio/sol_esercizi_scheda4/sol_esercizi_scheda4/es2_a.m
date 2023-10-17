clc
clear all

%sistema 1

A=[3 5; 3.01 5.01];
b=[10; 1];

x=A\b    %soluzione del sistema: x=[-2255; 1355]

%perturbo il coeff. di x della seconda equazione:
dA=[0 0; 0.01 0];

disp('errore relativo sui dati')
errore_dati=norm(dA,inf)/norm(A,inf)    %errore percentuale=0.12%
errore_dati_perc=errore_dati*100

%soluzione del sistema perturbato:
x1=(A+dA)\b

disp('errore relativo sulla soluzione') 
errore_sol=norm(x-x1,inf)/norm(x,inf) %errore percentuale=71.43%
errore_sol_perc=errore_sol*100
%quindi ad una piccola perturbazione sui dati corrisponde una grande
%perturbazione sui risultati --> problema mal condizionato

%INTERPRETAZIONE GEOMETRICA:
%La soluzione del sistema lineare e' il punto di intersezione tra le due rette
%Le rette del sistema Ax=b sono quasi parallele. Infatti il coefficiente angolare 
%della prima e' m1=-3/5=-0.6 mentre il coefficiente angolare della seconda e' m2=-3.01/5.01=-0.60008
%Pertanto un piccolo spostamento di una delle due rette provoca un grande
%spostamento del punto di intersezione (soluzione)

xv=linspace(-2260,-2250,100);

f1=@(x) (10-3*x)/5;  %prima retta: 3*x+5*y=10
f2=@(x) (1-3.01*x)/5.01; %seconda retta: 3.01*x+5.01*y=1

f2_p=@(x) (1.2-3.01*x)/5.01;

figure(1)
hold on
loglog(xv,f1(xv),'b-',xv,f2(xv),'r--',-2255,1355,'ko')

figure(2)
hold on
plot(xv,f1(xv),'b-',xv,f2_p(xv),'g--')

