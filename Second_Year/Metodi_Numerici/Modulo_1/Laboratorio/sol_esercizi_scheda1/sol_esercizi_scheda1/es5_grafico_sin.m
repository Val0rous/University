clc
clear all

x=linspace(-pi,pi,100); 
vettk=[1/3, 1/2, 1, 2];
col=['r','b','m','g'];
 
figure(1)
hold on 
grid on
for k=1: length(vettk)    
    y=sin(vettk(k)*x);
    plot(x,y,col(k),'LineWidth',1.2)
end
legend('k=1/3','k=1/2','k=1','k=2')