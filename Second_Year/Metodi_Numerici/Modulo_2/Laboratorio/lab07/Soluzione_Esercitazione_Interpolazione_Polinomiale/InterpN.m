function [yv,a]= InterpN(x,y,xv)
%costruzione dei  coefficiento del polinomio interpolatore di Newton
a=coeff_InterpN(x,y);
%Valutazione dell'interpolante di Newton
yv=pvalHornerN(a,x,xv);


 

