  function [L,U,flag]=LU_nopivot_imp_I(A)
% Implementazione eplicitando il ciclo in k (passo), i(riga)
% dell'algoritmo: al passo k, modifica la riga i senza svolgere il ciclo in
% j (sulle colonne dekka riga i)


  % Fattorizzazione  A=LU senza pivot 
  % In output:
  %  L matrice triangolare inferiore
  %  U matrice triangolare superiore
  
  % Test dimensione
  [n,m]=size(A);
  flag=0;
  if n ~= m
      disp('errore: matrice non quadrata')
      L=[];
      U=[];
      P=[]; 
      flag=1; 
      return
  end
  
 
  U=A;
  % Fattorizzazione
  for k=1:n-1
      %Test pivot 
      if U(k,k) ==  0
          disp('elemento diagonale nullo')
          L=[]
          U=[]
          flag=1
          return
      end
      %Eliminazione gaussiana
      for i=k+1:n
          U(i,k)=U(i,k)/U(k,k);                         % Memorizza il moltiplicatore della riga i-esima
          U(i,k+1:n)=U(i,k+1:n)-U(i,k)*U(k,k+1:n);  % Modifica la riga i-esima 
      end
  end
  
  L=tril(U,-1)+eye(n); % Estrae i moltiplicatori 
  U=triu(U);           % Estrae la parte triangolare superiore + diagonale
  