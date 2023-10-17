%Soluzione prova 3
clear all
close all
format long e

p=10^5;
q=10.^(-[0:10]);


%Calcolo l'indice di condizionamento della formula risolutiva
%x=-p+sqrt(p^2+q)
%CAlcolo la derivata prima di f(p,q)=-p+sqrt(p^2+q)
dp= @(p,q) 1./(2*sqrt(p.^2+q));
funz=@(p,q) -p+sqrt(p.^2+q);
x1= funz(p,q);
%Formula dell'indice di condizionamento
K1=abs(dp(p,q)).*abs(q)./abs(funz(p,q));
Q=q';
Cond=K1';
Sol=x1';
T=table(Q,Cond,Sol)

fprintf('Algoritmo stabile per valori di q > 1e-6 \n')


%Valutazione dell'indice di condizionamento della seconda formula risolutiva x=q/(p+sqrt(p^2+q)
%Uso il calcolo simbolico per calcolare la formula analitica della derivata
%prima della funzione f(p,q)= q/(p+sqrt(p^2+q)
syms p q
funz2=q/(p+sqrt(p^2+q));
dfunz2=diff(funz2);

p=10^5;
q=10.^(-[0:10]);
f2=matlabFunction(funz2);  %Trasformo la funzione analitica funz2 in funzione numerica con il comanto matlabFunction
df2=matlabFunction(dfunz2);
x2= f2(p,q);
%Calcolo indice di condizionamento
K2=abs(df2(p,q)).*abs(q)./abs(f2(p,q));
Q=q';
Cond=K2';
Sol=x2';
T=table(Q,Cond,Sol)
fprintf('Algoritmo  stabile per tutti i valori di q assegnati \n')
