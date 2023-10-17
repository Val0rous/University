function x=thomas(a,b,c,d)
n=length(a);
beta=zeros(n,1);
alpha=zeros(n,1);
alpha(1)=a(1);
for i=2:n
    beta(i)=b(i)/alpha(i-1);
    alpha(i)=a(i)-beta(i)*c(i-1);
end

%Soluzione sistema bidiagonale inferiore Ly=d
y(1)=d(1);
for i=2:n
    y(i)=d(i)-beta(i)*y(i-1);
end

%soluzione del sistema bidiagonale superiore Ux=y
x(n)=y(n)/alpha(n);
for i=n-1:-1:1
    x(i)=(y(i)-c(i)*x(i+1))/alpha(i);
end
