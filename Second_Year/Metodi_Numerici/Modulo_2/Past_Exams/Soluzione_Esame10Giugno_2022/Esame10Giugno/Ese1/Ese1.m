clear all
close all
f0= @(x) sin(x)./(1+exp(x));
f1= @(x) -sin(x.^2);
f2= @(x) -sin(x.^3);

figure
fplot(f0,[-1,0])
figure
fplot(f0,[-2.5,-1.5])
[IN1,N1]=traptoll(f0,-1,0,1e-7);
fprintf("Integrale f0 a=-1.0, b=0.0 --> %f Suddivisioni --> %d \n ",IN1,N1)
[IN2,N2]=traptoll(f0,-2.5,-1.5,1e-6);
fprintf("Integrale f0 a=-2.5, b=-1.5 --> %f Suddivisioni --> %d \n ",IN2,N2)


figure
fplot(f1,[-2,2])
[IN3,N3]=traptoll(f1,-2,2,1e-7);
fprintf("Integrale f1 a=-2.0, b=2.0 --> %f Suddivisioni --> %d \n ",IN3,N3)

figure
fplot(f2,[-2,2])
[IN4,N4]=traptoll(f2,-2,2,1e-7);
fprintf("Integrale f2 a=-2.0, b=2.0 --> %f Suddivisioni --> %d \n ",IN4,N4)

%la formula dei trapezi compositi ha un errore che dipende dalla potenza al quadrato del passo e 
%dalla derivata seconda della funzione integranda e quindi ha un ordine di precisione 1 essendo l’errore nullo per 
%funzioni integrande che sono polinomi di grado 2, cioè rette, che hanno la derivata seconda
%nulla. La funzione f0 nell’intervallo [-1,0] ha un andamento lineare e questo giustifica
%il fatto che l’integrale I0 tra -1 e 0  richieda meno suddivisioni rispetto all’integrale I0 tra
%[-2.5 e -1.5 ] dove la funzione presenta oscillazioni.

% la funzione integranda f2 è una funzione dispari e l’intervallo di integrazione è simmetrico per cui 
%l’integrale è nullo. Trapezi lo calcola in una sola iterazione, infatti la funzione dispari assume 
%negli estremi dell’intervallo di integrazione valori uguali ma con segno opposto per cui la 
%formula di Trapezi dà integrale nullo con una sola suddivisione. 
%Quando si fanno due suddivisioni darà su ciascun sottointervallo valori di integrazione uguali 
%ma con segno opposto per cui il risultato viene zero ed il metodo di arresta.