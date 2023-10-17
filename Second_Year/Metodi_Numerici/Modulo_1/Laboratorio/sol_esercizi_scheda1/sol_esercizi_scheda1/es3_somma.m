%calcola la somma dei primi n numeri naturali dispari:
clc
clear all

n=input('inserisci n:');

s = 0;
for i=1:n
    s = s + (2*i-1);
end
disp(s)
%....................
sum(1:2:2*n-1)