clc
clear all

t=53; 
U=1024; 
%Poichè il più grande numero positivo rappresentabile in F è RMAX:=(1-2^(-t))*2^U=(2^t-1)*2^(U-t) 
%dobbiamo richiedere 10^n <= RMAX ossia n<=log10(RMAX): 
nmax=floor(log10((2^t-1)*2^(U-t)))  %il piu' grande intero <=log10(RMAX)

[10^(nmax), 10^(nmax+1)]

realmax

 
