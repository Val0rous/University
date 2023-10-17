clear all 
clc

format long

n = 26;

A = zeros(1,n);
b = 2;
s = 1;
for i = 1 : n
    A(i) = b * s;
    s = sqrt( ( 1 - sqrt( 1 - s^2 ) ) / 2 );
    b = 2 * b;
end
semilogy( abs( A - pi ) / pi, 'b-', 'LineWidth', 1.5 )

A_stable = zeros(1,n);
b = 2;
s = 1;
for i = 1 : n
    A_stable(i) = b * s;
    s = s / sqrt( 2 * ( 1 + sqrt( 1 - s^2 ) ) );
    b = 2 * b;
end

hold on
semilogy( abs( A_stable - pi ) / pi, 'r--', 'LineWidth', 1.5 )
