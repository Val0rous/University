clc
clear all

nmin=10; nmax=50;
errore_relativo_xchol=zeros(nmax-nmin,1);
errore_relativo_lu=zeros(nmax-nmin,1);

for n=nmin:nmax
   
    B=rand(n);
    A=B'*B;
     xesatta=(1:n)';
    norm_xesatta=norm(xesatta);
    b=A*xesatta;
    %PA=LU
    [L,U,P,flaglu]=LU_parziale(A);
    if flaglu == 0,
        ylu=Lsolve(L,P*b);
        xlu=Usolve(U,ylu);
        errore_relativo_lu(n-nmin+1)=norm(xesatta-xlu)/norm_xesatta;
    end
    
    [Lm,flagm]=chol(A,"lower");
    if flagm == 0,  %A is positive definite
        ym=Lsolve(Lm,b);
        xchol=Usolve(Lm',ym);
        errore_relativo_xchol(n-nmin+1)=norm(xesatta-xchol)/norm_xesatta;
    end
    
end

figure(1)
xn=(nmin:nmax)';
semilogy(xn,errore_relativo_xchol,'b',xn,errore_relativo_lu,'r')
legend('chol','lu')
title('Metodo di Fattorizzazione di Cholesky')
xlabel('Dimensione n')
ylabel('Log errore relativo')
