function [x,xk,it]=bisez(fname,a,b,tol)

fa=fname(a);
fb=fname(b);
if  
   error('intervallo non corretto');
else
    maxit= 
    %fprintf('n. di passi necessari=%d \n',maxit);
    it=0;
    while  
        it=it+1;
         %calcola xk(it) con la formula corrispondente
        fxk=fname(xk(it));
        if fxk==0
            break;
        elseif sign(fxk)*sign(fa)>0
            

        elseif sign(fxk)*sign(fb)>0
            
        end
    end
    x=xk(it);
end
