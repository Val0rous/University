clc
clear all

format long e

%prendo F(10,5,L,U) e considero a e b che si rappresentano in modo esatto 
%in F e verificano 1/3<=a^2/b^2<=3  

a=0.1e1;     %1
b=0.14125e1; %1.4125
%......................
vex=a^2-b^2  %-9.951562500000002e-01
%......................

%algoritmo 1
apb=vpa(a+b,5);   %2.4125
amb=vpa(a-b,5);   %-0.4125
ris1=vpa(2.4125*(-0.4125),5)   %-0.99516
%%%%%%%

%algoritmo 2
a2=vpa(a^2,5);   %1.0
b2=vpa(b^2,5);   %1.9952
ris2=vpa(1.0-1.9952,5)  %-0.9952
%%%%%%%

err1=abs(-0.99516 + 9.951562500000002e-01)/abs(9.951562500000002e-01)  %3.768252472773027e-06

err2=abs(-0.9952 + 9.951562500000002e-01)/abs(9.951562500000002e-01)   %4.396294551713563e-05

%l'algoritmo 1 è in effetti più stabile!

