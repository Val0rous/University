function n1=my_norm1(A)
%Calcolo norma 1 di una matrice
[m,n]=size(A);
tmp=zeros(n,1);
for j=1:n
    tmp(j)=sum(abs(A(:,j)));
end
n1=max(tmp);