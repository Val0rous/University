clc
clear all
close all

x = linspace(-pi,pi,100);
y = sin(1/3*x);

figure(1)
hold on
%plot(x,y,'b-')
%hold on
k=[1/3,1/2,1,2];
color = ['c', 'g', 'y', 'm'];
for i = 1:1:4
   y = sin(k(i)*x);
   plot(x,y,color(i))
end
