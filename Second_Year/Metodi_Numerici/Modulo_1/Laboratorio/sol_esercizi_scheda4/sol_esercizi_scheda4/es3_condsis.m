%Esempi di sistemi malcondizionati
clc
clear all

A=[6 63 662.2;63 662.2 6967.8;662.2 6967.8 73393.5664];
b=[1.1; 2.33; 1.7];

cond(A)

x=A\b

%perturbare la matrice 
dA=[0.01,0 0;0,0 0;0 0 0];

%soluzione del sistema perturbato:
x1=(A+dA)\b

%errore relativo sui dati
errore_dati=norm(dA,inf)/norm(A,inf);   
errore_dati_perc=errore_dati*100

%soluzione del sistema perturbato:
x1=(A+dA)\b

%errore relativo sulla soluzione') 
errore_sol=norm(x-x1,inf)/norm(x,inf); 
errore_sol_perc=errore_sol*100
