%verificare la formula dello spacing
%e, quando p=0, la precisione di macchina (eps)
clc
clear all

format long e

p=0;   
t=53;

f=2^p  %numero floating point
s=2^(p+1-t) %spacing sul segmento [2^p, 2^(p+1)]=[1,2]
%..............................................
f1=f+s      %numero floating point successivo a f
fprintf('f1= %32.31e \n',f1)
f2=f+s/4;   %risulta f
fprintf('f2= %32.31e \n',f2)

disp('risultati per differenza:')
[f1-f, f2-f]  
 

