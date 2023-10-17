%formula di Simpson composita su n sottointervalli
%definiti da nodi equispaziati.

function I=SimpComp(fname,a,b,n)
h=(b-a)/ ;
nodi=[a:h:b];
f=fname(nodi);
I=(f(1)+...+f(2*n+1))*h/ ;