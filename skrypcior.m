clear all;
close all;

load('pomiary.mat');
pomiary=transpose(pomiary);
czas = linspace(0,37670,length(pomiary));

lit1=32131232131231;
lit2=0;
li3=3252;

k=1.075;
T=44.3;
tau=25.4;
figure(1)
%[ld, md]=pade(tau,15);
transm1=tf([k],[T 1]);

set(transm1,'outputdelay',tau);
hold on;

model=step(transm1,czas);
plot ( czas , pomiary,czas,model );
e=pomiary-model;
blad1=0.1*sum ( e.^2 )


k=1.08;
T=50;
tau=22;
%[ld, md]=pade(tau,15);
figure(2)
transm1=tf([k],[T 1]);

set(transm1,'outputdelay',tau);
hold on;

model=step(transm1,czas);
plot ( czas , pomiary,czas,model );
e=pomiary-model;
blad1=0.1*sum ( e.^2 )

%% [parametry,blad]=fminsearch('ident',[1.08, 50,22])

for K=1:0.01:1.1
    for T=40:0.5:60
        for tau= 12:0.5:23
            transm1=tf([K],[T 1]);
            set(transm1,'outputdelay',tau);
            model=step(transm1,czas);
            e=pomiary-model;
            blad=0.1*sum ( e );
            lit1=lit1+1
            if abs(blad)<abs(blad1)
                blad1=blad
                parametry=[K T tau]
                lit2=lit2+1
            end
        end
    end
end

            