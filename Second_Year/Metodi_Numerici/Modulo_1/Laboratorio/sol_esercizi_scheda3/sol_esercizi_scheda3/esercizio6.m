clc
clear all

%In aritmetica esatta, usando la nota identità (a+b)(a-b) = a^2-b^2, y1 e y2 sono equivalenti, ossia
%y1=sqrt(x^2+1)-x=(sqrt(x^2+1)-x)*(sqrt(x^2+1)+x)/(sqrt(x^2+1)+x)=1/(sqrt(x^2+1)+x)=y2

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%in questo primo esempio y1 e y2 danno un risultato molto simile perchè 
%sqrt(x^2+1) non è prossimo a x, e quindi y1 non è affetto da cancellazione numerica
x=7777;
y1=sqrt(x^2+1)-x
y2=1/(sqrt(x^2+1)+x)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
disp('---------------------------------------')
% Esempio di cancellazione numerica in y1:
x=77777777;
 
y1=sqrt(x^2+1)-x
% y1 = 0

y2=1/(sqrt(x^2+1)+x)
% y2 = 6.4286e-09

 

