function [x1,xk,it]=newton(fname,fpname,x0,tolx,tolf,nmax)

fx0=fname(x0);
dfx0=fpname(x0);
if abs(dfx0)>eps
    
else
    fprintf('Derivata nulla in x0 - EXIT \n')
     
    return
end

while 
    x0=x1;
    fx0=fname(x0);
    dfx0=fpname(x0);
    if abs(dfx0)>eps
         
    else
        fprintf('Derivata nulla in xi - EXIT \n')
        disp(dfx0)
        break
    end
end
if it==nmax
    fprintf('raggiunto massimo numero di iterazioni \n');
end

