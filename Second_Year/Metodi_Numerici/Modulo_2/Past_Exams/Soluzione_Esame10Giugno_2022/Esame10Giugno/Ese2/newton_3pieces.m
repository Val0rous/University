function [x1,xk,it]=newton_3pieces(f0name,f0pname,f1name,f1pname,f2name,f2pname,x0,tolx,tolf,nmax)

%..............
if abs(x0)<=2
    fx0=f1name(x0);
    dfx0=f1pname(x0);
elseif x0>2
    fx0=f2name(x0);
    dfx0=f2pname(x0);
elseif x0<-2
    fx0=f0name(x0);
    dfx0=f0pname(x0);
end
%..............

if abs(dfx0)>eps
    d=fx0/dfx0;
    x1=x0-d;
    %..............
    if abs(x1)<=2
        fx1=f1name(x1);
    elseif x1>2
        fx1=f2name(x1);
    elseif x1<-2
        fx1=f0name(x1);
         
    end
    %..............
    it=1;
    xk(it)=x1;
    %fprintf('it=%d  x=%8.15f \n',it,x1);
else
    fprintf('Derivata nulla in x0 - EXIT \n')
    disp(dfx0)
   x1=[];
        xk=[];
        it=[];
    return
end

while it<nmax && abs(fx1)>=tolf && abs(d)>=tolx*abs(x1)
    x0=x1;
    %..............
    if abs(x0)<=2
        fx0=f1name(x0);
        dfx0=f1pname(x0);
    elseif x0>2
        fx0=f2name(x0);
        dfx0=f2pname(x0);
    elseif x0<-2
        fx0=f0name(x0);
        dfx0=f0pname(x0);
    end
    %..............
    if abs(dfx0)>eps
        d=fx0/dfx0;
        x1=x0-d;
        %..............
        if abs(x1)<=2
            fx1=f1name(x1);
        elseif x1>2
            fx1=f2name(x1);
        elseif x1<-2
            fx1=f0name(x1);
        end
        %..............
        it=it+1;
        xk(it)=x1;
        %fprintf('it=%d  x=%8.15f \n',it,x1);
    else
        fprintf('Derivata nulla in xi - EXIT \n')
        disp(dfx0)
        break
    end
end
if it==nmax
    fprintf('raggiunto massimo numero di iterazioni \n');
end

