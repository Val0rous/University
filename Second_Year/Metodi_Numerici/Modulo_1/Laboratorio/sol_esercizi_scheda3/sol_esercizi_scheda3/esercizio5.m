    clc
    clear all
    
    format long e 
    x=.1e-15;
    
    %i=1,2,...,10
    s=1;
    for i=1:9
        s=s+x;
    end
    disp('Somma per i=1,2,...,10:')
    s
    
    %i=10,9,...,1
    s1=x;
    for i=1:8
        s1=s1+x;
    end
    s1=s1+1;
    disp('Somma per i=10,9,...,1:')
    s1
        
    disp('..............................')
    sum([1 ones(1,9)*x])
    
    sum([ones(1,9)*x 1])