%Soluzione prova 2
clear all
close all

Z= @(a) [11+a, 10+a, 14+a; 12+a,11+a,-13+a;14+a,13+a,-66+a];
invZ =@(a) [-55*a-557, 83*a+842,-28*a-284;55*a+610,-83*a-922,28*a+311;2,-3,1];


%Calcolo norma infinito delle matrici Z ed Zinv  utilizzando la function
%my_norm_f
k=1;
for an=linspace(30,1000,50)   
    ninfA(k)=my_norm_inf(Z(an));
    ninfinvA(k)=my_norm_inf(invZ(an));
    k=k+1;
end
%caloclo dell'indice di condizionamento
condZ=ninfA.*ninfinvA;
an=linspace(30,1000,50);

%Formula Analitica della norma infinito di Z e Zinv e calcolo dell'indice
%di codizionamento
ninfA_analitica=35+3*an;
ninfinvA_analitica=166*an+1843;
condZ_analitica=498.*an.^2+11339*an+64505;
figure
plot(an,condZ,'r',an,condZ_analitica,'b')

%fisso il valore di a=30
alpha=30

for pert=10.^[-3:-1:-6]
    Zn=Z(alpha);
    b=[3*alpha+35;3*alpha+10;3*alpha-39];
    Zp=Zn;
    %la soluzione esatta del sistema Z(alpha)xesatta= b è il vettore
    %[1,1,1]
    xesatta=ones(3,1);
    %Al variare di pert costruisco la matrice Z perturbata perturbando
    %l'elemento i posizione (1,1)
    Zp(1,1)=Zp(1,1)+pert;
    %Calolo l'errre relativo sui dati della matrice
    errore_relativo_dati_perc=my_norm_inf(Zp-Zn)/my_norm_inf(Zn)*100;
    %Risolvo il sistema lineare con matrice perturbata
    xcalcolata=Zp\b
    %Calolo l'errore relativo sullasoluzione del sistema
    errore_relativo_perc=my_norm_inf(xcalcolata-xesatta)/my_norm_inf(xesatta)*100;
    fprintf("pert = %e \n",pert)
    fprintf("errore relativo dati precentuale %e \n",errore_relativo_dati_perc)
    fprintf("errore relativo soluzione precentuale %f \n",errore_relativo_perc)
end

%La matrice Z(alpha) con alpha=30 ha indice di condizionamento elevato,
%K=852875, piccole perturbazioni sui dati vengono amplificate sui risultati