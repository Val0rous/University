function p=plagr(xnodi,k)
%Restituisce i coefficienti del k-esimo pol di
%Lagrange associato ai punti del vettore xnodi

if k==1
   xzeri=xnodi(2:end);
else
   xzeri=[xnodi(1:k-1) xnodi(k+1:end)];
end
%La funzione poly(xzeri) restituisce i coefficienti del polinomio che si
%annulla nelle componenti del vettore xzeri, cioè i coefficienti del
%polinomio (x-xzeri(1))(x-xzeri(2))(x-xzeri(3))...(x-xzeri(n))

p=poly(xzeri);
%La funzione polyval(p,xnodi(k)) valuta il polinomio i cui coefficienti
%sono memorizzati in p nel punto x_nodi(k)
p=p/polyval(p,xnodi(k));