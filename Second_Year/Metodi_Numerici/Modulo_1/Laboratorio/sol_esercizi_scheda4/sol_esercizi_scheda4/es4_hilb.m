%Esempio di sistema malcondizionato
clc
clear all

A=hilb(4);
b=ones(4,1);

%calcolo soluzione sistema A*x=b
x=A\b

db=0.01*[1 -1 1 -1]';
bp=b+db;

%calcolo soluzione sistema A*xp=bp
xp=A\bp

disp('errore relativo sui dati')
errore_dati=norm(db,inf)/norm(b,inf);   
errore_dati_perc=errore_dati*100   % 1%

disp('errore relativo sulla soluzione') 
errore_sol=norm(x-xp,inf)/norm(x,inf); 
errore_sol_perc=errore_sol*100      % 75%

disp('numero di condizionamento della matrice A (in norma inf):')
K=cond(A,'inf')

%verifico che cond restituisce esattamente il numero di condizionamento di
%A come definito a lezione
verifica=norm(A,'inf')*norm(inv(A),'inf')
