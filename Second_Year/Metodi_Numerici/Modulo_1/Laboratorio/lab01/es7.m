clc
clear all

%altro

%matrice di rotazione di un angolo alpha

R = [cos(-alpha), -sin(-alpha); sin(alpha), cos(alpha)];

P = [-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0, -6;
    -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7, -7];

figure(1)
x = P(1,:);
y = P(2,:);
plot(x,y,'b-')

Prot = R*P;


%altro

P = [1, 1, 0.8, -0.8, -1, -1, 0, 1, nan, 0.5, 0.7, 0.5, 0.3, 0.5, nan, -0.5, -0.7, -0.5, -0.3, -0.5, nan, -0.5, 0.5, nan, 0, -0.1, 0.1, 0;
-0.5, 1, 0.8, 0.8, 1, -0.5, -0.9, -0.5, nan, 0.5, 0.4, 0.3, 0.4, 0.5, nan, 0.5, 0.4, 0.3, 0.4, 0.5, nan, -0.5, -0.5, nan, 0, -0.1, -0.1, 0];