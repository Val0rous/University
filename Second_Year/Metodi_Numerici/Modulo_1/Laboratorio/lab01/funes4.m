function f = funes4(n)
    v=n;
    %i = 0;
    while(n>1)
        %n even
        if(rem(v/2,2)==0)
             v=v/2;
        %n odd
        else
            v=3*v+1;
        end
        %v = [v n];
        %i = i+1;
    end

    %f=v(i);
    f=v;
end