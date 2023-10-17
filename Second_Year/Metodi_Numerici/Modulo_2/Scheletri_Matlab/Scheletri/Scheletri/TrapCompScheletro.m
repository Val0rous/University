%formula dei trapezi composita su n sottointervalli 
%definiti da nodi equispaziati

function I=TrapComp(fname,a,b,n)
h=(b-a)/ ;
nodi=[a:h:b];
f=fname(nodi);
I=(f(1)+ +f(n+1))*h/ ;
