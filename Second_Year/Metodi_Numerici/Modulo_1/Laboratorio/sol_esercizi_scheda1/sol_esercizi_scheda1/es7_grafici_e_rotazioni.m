clc
clear all

%scommentare la poligonale desiderata

% P=[ -6 -6 -7 0 7 6  6 -3 -3  0  0 -6;
%     -7  2  1 8 1 2 -7 -7 -2 -2 -7 -7];

P = [   1 1 0.8 -0.8 -1 -1    0    1   nan 0.5 0.7 0.5 0.3 0.5 nan -0.5 -0.7 -0.5 -0.3 -0.5 nan -0.5  0.5 nan 0 -0.1  0.1 0;
    -0.5 1 0.8  0.8  1 -0.5 -0.9 -0.5 nan 0.5 0.4 0.3 0.4 0.5 nan  0.5  0.4  0.3  0.4  0.5 nan -0.5 -0.5 nan 0 -0.1 -0.1 0];

alpha_vett=[pi/4, pi, 3/4*pi];

figure(1) 
subplot(2,2,1)
hold on
title(['\alpha = ',num2str(0)])
plot(P(1,:),P(2,:))

for k=1:length(alpha_vett)
    alpha=alpha_vett(k);
    
    %rotazione in senso antiorario di angolo alpha
    % R=[cos(alpha) -sin(alpha); sin(alpha) cos(alpha)];
    
    %rotazione in senso orario di angolo alpha
    R=[cos(-alpha) -sin(-alpha); sin(-alpha) cos(-alpha)];
    
    subplot(2,2,k+1);
    hold on
    title(['\alpha = ',num2str(alpha)])
    Prot=R*P;
    plot(Prot(1,:),Prot(2,:))
end

