function [x, xk, it] = regula_falsi(fname,a,b,tol,nmax)
       
fa=fname(a);
fb=fname(b);
if sign(fa)*sign(fb)>=0
   error('intervallo non corretto');
else
    it=0;
    fxk=fname(a);
    while  
        it=it+1;
        xk(it)= 
        %fprintf('it=%d  x=%8.15f \n',it,xk(it));
        fxk=fname(xk(it));
        if fxk==0
            break;
        elseif sign(fxk)*sign(fa)>0
             
        elseif sign(fxk)*sign(fb)>0
             
        end
    end
    if it==nmax 
        error('Raggiunto numero max di iterazioni');
        x=[];
    else
        x=xk(it);
    end
end
