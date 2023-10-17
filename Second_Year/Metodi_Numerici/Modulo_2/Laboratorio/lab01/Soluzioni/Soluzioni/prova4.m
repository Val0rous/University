%Soluzione prova 4
clc
clear all
format long

%  METODO   1
s(1)=1;
s(2)=1.25;
u(1)=1;
u(2)=s(2);
for n=2:40
    s(n+1)=s(n)+(n+1)^(-2);
    u(n+1)=sqrt(6*s(n+1));
end
rel_err_u=abs(u-pi)/pi;

%  METODO   2
z(1)=1;
z(2)=2;
for n=2:40
    c=(4^(1-n))*(z(n))^2;
    inner_sqrt=sqrt(1-c);
    z(n+1)=(2^(n-0.5))*sqrt(1-inner_sqrt) ;
end
rel_err_z=abs(z-pi)/pi;

%  METODO   3
y(1)=1;
y(2)=2;
for n=2:40
    num=(2^(1/2))*abs(y(n));
    c=(4^(1-n))*(z(n))^2;
    inner_sqrt=sqrt(1-c);
    den=sqrt(1+inner_sqrt);
    y(n+1)=num/den;
end
rel_err_y=abs(y-pi)/pi;


[rel_err_u' rel_err_z' rel_err_y']

%  SEMILOGY  PLOT
figure(1)
semilogy(1:length(u),rel_err_u,'k.-',1:length(z),rel_err_z,'g+-',1:length(y),rel_err_y,'ro-');
legend('u_n','z_n','y_n')

%La successione u_n converge molto lentamente a pi 
%La successione z_n diverge 
%La successione y_n converge velocemente a pi
%Per alcuni valori di n, z_n e y_n coincidono per poi rispettivamente divergere e convergere a pi. 
%Tutto cio' e' naturale poiche' le due successioni sono analiticamente (ma non numericamente) equivalenti.
%La successione y_n, dopo aver raggiunto errori relativi prossimi alla precisione di macchina, si
%assesta ad un errore relativo di circa 10^(-15) (per questioni di arrotondamento).