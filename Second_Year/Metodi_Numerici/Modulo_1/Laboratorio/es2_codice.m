clc
clear all

av=0.01:0.01:9.99;
n=length(av);
K2_matlab=zeros(1,n);
K2_mio=zeros(1,n);

for i=1:n
    A=[3 0 1;0 av(i) 0;1 0 1];
    K2_matlab(i)=cond(A,2);

    if av(i)<=2-sqrt(2)
       K2_mio(i)=(2+sqrt(2))/av(i);
    elseif av(i)>2-sqrt(2) && av(i)<=2+sqrt(2)
       K2_mio(i)=(2+sqrt(2))/(2-sqrt(2));
    else
       K2_mio(i)=av(i)/(2-sqrt(2));
    end
end

figure(1)
plot(av,K2_mio,'b-',av,K2_matlab,'r--')
legend('mio K2','K2 di matlab')