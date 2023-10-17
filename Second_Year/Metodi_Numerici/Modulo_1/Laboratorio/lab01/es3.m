clc
clear all

n = input('gimme the number n: ')
ris = 0;

for i=1:n
    ris = ris + (2*i-1);
end
ris

sum([1:2:2*n-1])