clc
clear all

scelta_matrice=input('1. Matrice 1. \n 2. Matrice 2  \n 3. Matrice 3 \n');

if scelta_matrice ==1
     A=[1 2 3;4 0 2;1 6 2];
     b=[6;6;9];
    xesatta=[1;1;1];
elseif scelta_matrice==2
    A=[2 1 3 4;1 0 3 4;1 5 0 6;2 1 3 0];
    b=[10;8;12;6];
    xesatta=[1;1;1;1];
else
    A=[1 2 3; 4 0 2;1 6 0];
    b=[6;6;7];
    xesatta=[1;1;1];
end

[L,U,flag]=LU_nopivot(A);
P=eye(size(A));
[x,flag]=LUsolve(L,U,P,b)
errore_relativo=norm(xesatta-x)/norm(xesatta)

