clc
clear all

%calcolo della costante di lebesgue in [-1,1]

xx=linspace(-1,1,200);
LLe=zeros(1,4);
LLc=zeros(1,4);
    
i=0;
for n=5:5:20
    %Calcolo della costante di Lebesgue per il grado n del polinomio
    %interpolatore
    i=i+1;
    %----------------------------
    %nodi equispaziati
    xe=linspace(-1,1,n+1);
    %nodi di Chebyshev 
    xc=-cos((2*[0:n]+1)*pi/(2*(n+1)));
    
    Le=zeros(1,200);
    Lc=zeros(1,200);
    
    %Calcolo la somma dei valori assoluti delle n+1 funzioni base di
    %lagrange di grado n, valutati nei punti xx (sia nel caso in cui i nodi
    %siano equidistanti che nel caso in cui i nodi siano gli zeri dei
    %polinomi di Chebichev)
    for l=1:n+1        
        pe=plagr(xe,l);
        Le=Le+abs(polyval(pe,xx));
        pc=plagr(xc,l);
        Lc=Lc+abs(polyval(pc,xx));
    end
    %La costante di Lebesgue è il massimo della somma dei valori assoluti delle n+1 funzioni base di
    %lagrange di grado n, valutati nei punti xx
    LLe(i)=max(Le);
    LLc(i)=max(Lc);
      
    %----------------------------
end

disp('Costante di Lebesgue con nodi equispaziati al variare di n: ')
LLe
 
disp('Costante di Lebesgue con nodi di Chebyshev al variare di n: ')
LLc 

semilogy(1:4, LLe, 1:4,LLc)
legend('Costante di Lebesgue Nodi equidistanti','Costante di Lebesgue Nodi di Chebichev')
