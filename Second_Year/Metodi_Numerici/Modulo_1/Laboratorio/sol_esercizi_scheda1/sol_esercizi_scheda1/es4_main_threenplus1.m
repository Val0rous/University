clc
clear all

n=input('inserisci n:');

y=threenplus1_semplice(n)

figure(1)
hold on
title(['n = ' num2str(y(1))]);
plot(1:length(y),y,'.-')
 


figure(2) 
hold on
title(['n = ' num2str(y(1))]); 
set(gca, 'YScale', 'log')
semilogy(1:length(y),y,'.-')
