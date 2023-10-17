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

for k=1:n
    p=plagr(x,k);
    L(k,:)=polyval(p,xx);
end

yy=f*L;