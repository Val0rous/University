function [x1,xk,it]=secanti(fname,xm1,x0,tolx,tolf,nmax)

fxm1=fname(xm1);
fx0=fname(x0); 
d= 
x1= 
fx1=feval(fname,x1);
it=1;
xk(it)=x1;
%fprintf('it=%d  x=%8.15f \n',it,x1);
while  
    xm1=x0;
    x0=x1;
    fxm1=fname(xm1);
    fx0=fname(x0); 
    %Calcola la soluzione x1 con il metodo delle secanti
    to do
    fx1=fname(x1);
    it=it+1;
    xk(it)=x1;
    %fprintf('it=%d  x=%8.15f \n',it,x1);
end
if it==nmax
   fprintf('raggiunto massimo numero di iterazioni \n');
end
