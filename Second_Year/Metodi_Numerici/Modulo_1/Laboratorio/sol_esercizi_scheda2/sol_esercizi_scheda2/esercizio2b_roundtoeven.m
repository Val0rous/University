%rounding to even
clc
clear all

format long

p=52;
t=53;

f=2^p   %numero floating point
sr=2^(p+1-t)   %spacing in [2^p, 2^(p+1)]
sl=2^(p-t)     %spacing in [2^(p-1), 2^p]
%..............................
fs=f+sr   %numero floating point successivo a f
fp=f-sl   %numero floating point che precede f
%..............................
disp('esempi rounding to even:')
f+sr/2 
f-sl/2 
%..............................

