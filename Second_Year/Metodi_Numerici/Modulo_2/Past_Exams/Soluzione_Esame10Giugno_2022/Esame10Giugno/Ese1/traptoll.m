function [IN,N]=traptoll(fun,a,b,tol)

Nmax=2048;
err=1;

N=1;
IN=TrapComp(fun,a,b,N);

while N<=Nmax && err>tol
    N=2*N;
    I2N=TrapComp(fun,a,b,N);
    if abs(IN-I2N)==0
        N=N/2;
        return
    end
    err=abs(IN-I2N)/3;
    IN=I2N;
end

if N>Nmax
    fprintf('Raggiunto nmax di intervalli con traptoll\n')
 end
