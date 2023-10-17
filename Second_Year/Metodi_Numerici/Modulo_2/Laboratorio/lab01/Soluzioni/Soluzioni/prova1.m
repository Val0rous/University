%Soluzione Prova1
clear all
close all
A=@(alpha) [1 1 1; 0 alpha, alpha; 0 2*alpha, alpha];
Ainv=@(alpha)[1, -1/alpha, 0; -1 0 1/alpha;1 1/alpha, -1/alpha];

%Calcolo noema 1 della matrice A ed Ainv  utilizzando la function my_norm1

n1A=zeros(50,1);
n1invA=zeros(50,1);
k=1; 
for alpha=linspace(0.001,2/3,50)
    n1A(k)=my_norm1(A(alpha));
    n1invA(k)=my_norm1(Ainv(alpha));
    k=k+1;
end
condA=n1A.*n1invA;

alpha=linspace(0.001,2/3,50);
%Formula analitica in funzione di alpha per il calcolo della norma 1 della matrice
%A(alpha) e della sua inversa Ainv(alpha)

n1A_analitica=1+3*alpha';
n1invA_2=2./alpha';
%Calcolo indice di condizionamento in norma 1 in forma analitica
condA_analitica=2./alpha'+6;

figure
plot(alpha, condA,'r', alpha, condA_analitica,'b')

b=[-8;-1;9];

%Matrice di perturbazione
deltaA=[0.01 0.001 0.001; 0 0.001 0.001; 0 0.001 0.01];
k=1;
err_sol=zeros(50,1);
err_dat=zeros(50,1);
for alpha=linspace(0.001,2/3,50);
    matA=A(alpha);
    %Per ogni valore di alpha risolvo il sistema A(alpha)xesatta=b
    xesatta=matA\b;
    %Costruisco la matrice perturbata Ap)A(alpha)+deltaA
    Ap=matA+deltaA;
    %Per ogni valore di alpha risolvo il sistema Ap xp=b
    xp=Ap\b;
%Calcolo l'errore relativo percentuale in norma 1 sui dati della matrice
    err_dat(k)=my_norm1(deltaA)/my_norm1(matA)*100;
%Calcolo l'errore relativo percentuale in norma 1 sulla soluzione
    err_sol(k)=my_norm1(xp-xesatta)/my_norm1(xesatta)*100;
    k=k+1;
end
alpha=linspace(0.001,2/3,50)';
Erroredati_percentuale=err_dat;
ErroreSoluzione_percentuale=err_sol;
T=table(alpha,condA_analitica, Erroredati_percentuale, ErroreSoluzione_percentuale)

%Per valori di alpha piccoli, a cui corrisponde un elevato indice di
%condizionamento,  a piccoli errori sui dati  corrisponde un errore relativo sulla soluzione molto elevato, 
%dovuto all'indice di condizionamente che rappresenta il fattore di
%amplificazione dell'errore sui dati sull'errore sulla soluzione,

%Per valori di alpha grandi, a cui corrisponde un ridimensionato indice di
%condizionamento,  a piccoli errori sui dati corrisponde un errore relativo sulla soluzione ridimensionato, 
%dovuto all'indice di condizionamente che rappresenta il fattore di
%amplificazione dell'errore sui dati sull'errore sulla soluzione,


