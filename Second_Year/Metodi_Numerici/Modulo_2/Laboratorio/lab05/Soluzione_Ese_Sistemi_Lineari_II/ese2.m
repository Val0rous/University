clc
clear all

cont=0;
disp(' n    cond      err1      err2      err3')
disp('-----------------------------------------------------')
for n=4:6:40
    cont=cont+1;
    for i=1:n
        for k=i+1-n:i
            if k>0
                A(i,n+k-i)=2^k;
            else
                A(i,n+k-i)=2^(1/(2-k));
            end
        end
    end
    c(cont)=cond(A);
    %soluzione esatta
    x=ones(n,1);
    b=A*x;
    normx=norm(x);
    %---------------------------------------
    %Metodo QR 
    [Q,R]=qr(A);
    y=Q'*b; %Poichè la matrice Q è ortogonale la sua trasporta coincide con la sua inversa, 
    % la soluzione del sistema Qy=b si effettua come y=Q'*b
    x1=Usolve(R,y);
    err1(cont)=norm(x-x1)/normx;
    %---------------------------------------
    %Metodo di Gauss con pivot parziale
    [L,U,P,flag]=LU_parziale(A);
    [x2,flag]=LUsolve(L,U,P,b);
    err2(cont)=norm(x-x2)/normx;
    %---------------------------------------
       disp(sprintf(' %d  %5.2e %5.2e  %5.2e ',n,c(cont),err1(cont),err2(cont)))
    
end

figure

semilogy([4:6:40],err1,'ko-',[4:6:40],err2,'r*-')

legend('QR','Pivot massimo per colonna')
%QR è più stabile rispetto a Guass con Pivot massimo per colonna
