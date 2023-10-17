function yy = InterpL(x, f, xx)
%
%funzione che determina in un insieme di punti il valore del polinomio
%interpolante ottenuto dalla formula di Lagrange.
% DATI INPUT
%  x  vettore con i nodi dell'interpolazione
%  f  vettore con i valori dei nodi 
%  xx vettore con i punti in cui si vuole calcolare il polinomio
% DATI OUTPUT
%  y vettore contenente i valori assunti dal polinomio interpolante
%

n=length(x);
m=length(xx);
yy=zeros(1,m);
for k=1:n
    %calcola i coefficienti del k-esimo polinomio di Lagrange e denota con
    %Lk la sua valutazione nei punti xx 
    yy=yy+f(k)*Lk;
end
