clc
clear all

scelta_matrice=input('1. Matrice 1. \n 2. Matrice 2 ');

if scelta_matrice ==1
     A=[1 2 3;0 0 1;1 3 5];
     b=[6;1;9];
     xesatta=[1;1;1];
else
    A=[1 1 0 3;2 1 -1 1;-1 2 3 -1;3 -1 -1 2];
    b=[5;3;3;3];
    xesatta=[1;1;1;1];
end
n=size(A,1);

scelta_metodo=input('1. No Pivot \n 2. Pivot Parziale ');

if scelta_metodo==1
    [L,U,flag]=LU_nopivot(A);
    P=eye(n);
else
 [L,U,P,flag]=LU_parziale(A);
end

if flag == 0
    y=Lsolve(L,P*b);
    x=Usolve(U,y)
    errore_relativo=norm(xesatta-x)/norm(xesatta)
else
    disp('non posso proseguire')
    return
end
