%esercizio 1
clc
clear all
format long


syms a

%denK=2*sqrt(4-a)*(2+sqrt(4-a));   %per l'altra soluzione

denK=2*sqrt(4-a)*(2-sqrt(4-a));
K=abs(a)/abs(denK);

%cerco gli zeri del denominatore di K:
zeri_denK=solve(denK,a)

%verifico che l'unico zero del denominatore di K che mi da problemi e' a=4:
limit(K,a,0)
limit(K,a,4)

disp('------------------------------------------------------')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%cerco i valori di alpha in R tali che fl(alpha)=4

t=53;

s1=2^(2-t); %spacing sul segmento [2^1,2^2]
s2=2^(3-t); %spacing sul segmento [2^2,2^3]

estremo_sinistro=4-s1/2
estremo_destro=4+s2/2

%risultano: 4-s1/2 <= alpha <= 4+s2/2

%per fare un test scelgo alpha in [4-s1/2,4+s2/2] e verifico che fl(alpha)=4

%esempi:
es1_alpha=4-s1/3

es2_alpha=4+s2/3


%se invece scelgo alpha piu' piccolo di estremo_sinistro:

fprintf('%16.32f\n',4-3/4*s1) 

%se invece scelgo alpha piu' grande di estremo_destro:

fprintf('%16.32f\n',4+3/4*s2) 


