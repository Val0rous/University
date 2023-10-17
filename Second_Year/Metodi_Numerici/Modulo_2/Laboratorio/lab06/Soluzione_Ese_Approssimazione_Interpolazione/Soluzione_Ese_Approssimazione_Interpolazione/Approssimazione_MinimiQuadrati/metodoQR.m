function [a] = metodoQR(A,y)
% input A = matrice m × n, m > n
% input b = vettore termine noto di m
% output a = vettore soluzione nel senso dei minimi quadrati del sistema lineare
% sovraderterminato Ax=b, ottenuto mediante  il metodo QRLS
 
n=size(A,2);
[Q,R]=qr(A);
h=Q'*y;
a=Usolve(R(1:n,1:n),h(1:n));
