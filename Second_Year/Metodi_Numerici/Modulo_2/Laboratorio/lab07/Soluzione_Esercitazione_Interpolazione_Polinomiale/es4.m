clc
clear all

x=linspace(-1,1,22);
y1=sin(2*pi*x);

%costruzione osservazioni perturbate
y2=y1+0.0002*randn(1,22);

xx=linspace(-1,1,301);
%Calcolo il polinomio interpolatore sui dati esatti
yy1=InterpL(x,y1,xx);
%Calcolo il polinomio interpolatore sui dati perturbati
yy2=InterpL(x,y2,xx);

figure(1);
plot(x,y1,'bo',xx,yy1,'b-',xx,sin(2*pi*xx),'g--');
legend('punti di interpolazione','interpolante di Lagrange','y=sin(2*pi*x)');

figure(2);
plot(x,y1,'bo',x,y2,'r*',xx,yy1,'b-',xx,yy2,'r');
legend('dati','dati perturbati','p(x)','p(x) perturbato')

%errore relativo sui dati
errrel_dati=norm(y2-y1,inf)/norm(y1,inf)

%errore relativo sui risultati
errrel_risultati=norm(yy2-yy1,inf)/norm(yy1,inf)