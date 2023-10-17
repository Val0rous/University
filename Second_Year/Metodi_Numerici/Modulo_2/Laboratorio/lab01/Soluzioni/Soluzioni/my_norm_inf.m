function ninf=my_norm_inf(A)
%Calcolo norma infinito di una matrice
[m,n]=size(A);
tmp=zeros(n,1);
for i=1:m
    tmp(i)=sum(abs(A(i,:)));
end
ninf=max(tmp);