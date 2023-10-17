clear all
close all
syms x
f1s=-12/5*x.^2-9*x-27/5;
f2s=(x^2-5*x+1)/(x^2+1);
f3s=2/5*x^2-x-3/5;

f1=matlabFunction(f1s);
f2=matlabFunction(f2s);
f3=matlabFunction(f3s);

df1=matlabFunction(diff(f1s,x,1));
df2=matlabFunction(diff(f2s,x,1));
df3=matlabFunction(diff(f3s,x,1));

xv1=[-4:0.01:-1.9999];
xv2=[-2:0.01:2];
xv3=[2.001:0.01:4];
figure
plot(xv1,f1(xv1),'k',xv2,f2(xv2),'r',xv3,f3(xv3),'b')
hold on
xv4=[-4:0.001:4];
plot(xv4,zeros(size(xv4)),'k')
tolx=1e-10;
tolf=tolx;
nmax=500;
x0=[-2,-1,0,1,2];

hold on
for i=1:5
    [x1,xk,it]=newton_3pieces(f1,df1,f2,df2,f3,df3,x0(i),tolx,tolf,nmax);
    fprintf('Iterato iniziale %f   Numero di iterazioni %d  Zero calcolato %f  \n', x0(i),it,x1)
     
    if it>1
        plot(x1,0,'ro')
    end

    
end


%La funzione ha 3 zeri.
%Per valori di innesco x0=-1 ed x0=1 poichè la derivata prima in questi
%valori si annulla, il metodo si ferma, visto che la formula per calcolare l'iterato
%successvio è data x1=x0-f(x0)/f'(x0), con al denominatore f'(x0).
% Il metodo di Newton è un metodo a convergenza locale, per ogni iterato
% iniziale scelto tra quelli assegnati raggiunge uno zero differente, (più vicino all'iterato iniziale)   con
% velocità di convergenza quadratica.
%Iterato iniziale -2.000000   Numero di iterazioni 7  Zero calcolato -3.000000  
%terato iniziale -1.000000 ed 1, il metodo si arresta perchè in questi
%punti si annulla la derivata prima della funzione.
%Iterato iniziale 0.000000   Numero di iterazioni 4  Zero calcolato 0.208712  
%Iterato iniziale 2.000000   Numero di iterazioni 5  Zero calcolato 3.000000 
