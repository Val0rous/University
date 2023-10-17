clc
clear all
close all
kmax=20;
er_nop=zeros(kmax,1);
er_p=zeros(kmax,1); 
er_m=zeros(kmax,1);

n=100;
xe=ones(n,1);  
norm_xe=norm(xe); 
 
v=rand(n,1); v=v/norm(v);
Q=eye(n)-2*v*v';
D=eye(n);

for k=1:kmax
    %...costruisco matrice A...
    D(n,n)=10^k; A=Q*D;
    %..........................
    condA(k)=cond(A);
    %..........................
    b=A*xe;
    %soluzione con LU
    [Lnop,Unop,flag]=LU_nopivot(A);
    Pnop=eye(n);
    [xnop,flag]=LUsolve(Lnop,Unop,Pnop,b);
    er_nop(k)=norm(xe-xnop)/norm_xe;
    %soluzione con LU_parziale
    [L,U,P,flag]=LU_parziale(A);
    [xp,flag]=LUsolve(L,U,P,b);
    er_p(k)=norm(xe-xp)/norm_xe;
   
end


figure 
xn=(1:kmax)';
semilogy(xn,er_nop,xn,er_p)
legend('nopivot','parziale')
ylabel('Log errore relativo')

figure(2)
semilogy(condA)
title('A variabile di dimensione n=100')
ylabel('Log indice condizionamento in norma 2')
