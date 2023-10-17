function yy = InterpL(x, y, xv)
%
%funzione che determina in un insieme di punti il valore del polinomio
%interpolante ottenuto dalla formula di Lagrange.
% DATI INPUT
%  x  vettore con i nodi dell'interpolazione
%  y  vettore con i valori nei nodi 
%  xv vettore con i punti in cui si vuole calcolare il polinomio
% DATI OUTPUT
%  y vettore contenente i valori assunti dal polinomio interpolante
%

n=length(x);
m=length(xv);
yy=zeros(1,m);
for k=1:n
    p=plagr(x,k);
    Lk=polyval(p,xv);
    %Calcolo della combinazione lineare della funzione base di Lagrange k-esima valutata
    %nei punti di valutazione per il valore y nel valore k-esimo 
    yy=yy+y(k)*Lk;
end
