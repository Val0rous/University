%Esercizio 3
%La somma non e' associativa: esempio su cosa accade quando si sommano numeri
%con ordine di grandezza molto diversi (errore di assorbimento)

clc
clear all
format long e

a=1.234567890123400*10^(15);
b=-1.234567890123401*10^(15);
c=0.06;

disp('(a+b)+c=?')
%osservare che a+b=-0.000000000000001*10^(15)=-1
ris1=(a+b)+c


disp('(a+c)+b=?')
%osservare che a+c=a
fprintf('a+c= %32.31e \n',(a+c))
ris2=(a+c)+b


disp('a+(b+c)=?')
%%%osservare che b+c=b
fprintf('b+c= %32.31e \n',(b+c))
ris3=a+(b+c)
 
%quindi il piu' accurato e' ris1

 
disp('.......................................')

clear all
a=0.23371258*10^(-4);
b=0.33678429*10^2;
c=-0.33677911*10^2;

disp('(a+b)+c=?')
ris4=(a+b)+c

disp('(a+c)+b=?')
ris5=(a+c)+b

disp('a+(b+c)=?')
ris6=a+(b+c)
 
%il piu' accurato e' ris6
 
