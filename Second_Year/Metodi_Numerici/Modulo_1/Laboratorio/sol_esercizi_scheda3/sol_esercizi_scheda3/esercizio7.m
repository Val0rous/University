clc
clear all

% syms x
% limit((1-cos(x))/x^2,x,0)
% ans =
% 1/2

for n=2:2:12
    x=10^(-n);
    f1=(1-cos(x))/x^2;
    f2=2*(sin(x/2))^2/x^2;
    fprintf('%e\t %e\t %e\n',x,f1,f2);
end