clc
clear all
format long e

a=1;
c=1;
k=1:8;
b=10.^k;

x1=(-b+sqrt(b.^2-4*a*c))./(2*a);   %affetta da cancellazione numerica per k grandi
x2=(-b-sqrt(b.^2-4*a*c))./(2*a);

x1_new=c./(a*x2);
x1_vera=-10.^(-k);

err=abs(x1_vera-x1)./abs(x1_vera);
errnew=abs(x1_vera-x1_new)./abs(x1_vera);


disp(['    x1                      x2                       x1_{new}'])
disp([x1' x2' x1_new'])

figure(1)
hold on
set(gca,'yscale','log')
semilogy(1:8, err,'b-','LineWidth', 1.5)
semilogy(1:8, errnew,'r--','LineWidth', 1.5)
legend('x1','x1_{new}')

