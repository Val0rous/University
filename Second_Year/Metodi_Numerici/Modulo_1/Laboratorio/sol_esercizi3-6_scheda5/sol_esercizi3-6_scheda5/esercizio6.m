format long e

i=0:20;
x=10.^i;

Ax=1./x-1./(x+1);
Bx=1./(x.*(x+1));

Erelx=abs(Ax-Bx)./abs(Bx);

u=eps/2; %roundoff unit

%stima teorica dell'err relativo nel caso x, x+1 stanno in F
ErelTx=(abs(x+1)+abs(x)+1)*u;

%stima teorica dell'err relativo nel caso x non sta in F 
ErelT2x=(2*abs(x+1)+2*abs(x)+x.^2./abs(x+1)+1)*u;

figure(1);
loglog(x,Erelx,'b-',x,ErelTx,'r--',x,ErelT2x,'k:');
legend('Err rel','Stima err','Stima err completa')

%si osserva che le stime teoriche risultano una maggiorazione di Err rel