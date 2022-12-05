%@uthor: Alem Haddush Fitwi, M.Sc in Computer Engineering
%Performance Analysis
%--------------------------------------------------------------------------
%Encryption Times
EncTCE=[0.031  	0.047  	0.078  	0.094  	0.156  	0.250  	0.437  	0.515  	1.232  	3.823 ];
EncTRSA=[0.506	0.978	1.438	1.852	2.326	3.243	4.248	4.596	9.355	32.554];
EncTAES=[0.669	0.692	0.719	0.731	0.735	0.807	0.813	0.821	0.829	0.987];
%--------------------------------------------------------------------------
%Data in kilo bits and in bytes
data=[7.84	15.87	23.36	31.20	39.30	55.16	73.87	79.16	158.30	457.16];
datab=[1004	2031	2990	3994	5030	7060	9455	10132	20262	58516];

for i=1:10
    %Thruputs
    CETH(i)=datab(i)/EncTCE(i);
    RSATH(i)=datab(i)/EncTRSA(i);
    AESTH(i)=datab(i)/EncTAES(i);
    %Power consumption
    PCE(i)=.1*1.25*EncTCE(i);
    PRSA(i)=.1*1.25*EncTRSA(i);
    PAES(i)=.1*1.25*EncTAES(i);
end
%----CEET
plot(data,EncTCE)
title('Chaotic Encryption Times')
xlabel('Data sizes in Kilo bits')
ylabel('Encryption times in sec')
%----CETH
plot(datab,CETH)
title('Throughputs')
xlabel('Data sizes in bytes')
ylabel('Throughputs of various data sizes')
%----PCE
plot(data,PCE)
title('Energy Consumption During Enciphering Process')
xlabel('Data sizes in kilo bits')
ylabel('Energy Consumed in joules')

% CE, AES, RSA Encryption Times
plot(data,EncTCE)
hold on
plot(data,EncTRSA);
hold on
plot(data,EncTAES);
title('Encryption times of Chaotic, RSA and AES')
xlabel('Data sizes in kilo bits')
ylabel('Encryption Times in sec')

% CE, AES, RSA Thruputs
plot(datab,CETH)
hold on
plot(datab,RSATH);
hold on
plot(datab,AESTH);
title('Thruputs of Chaotic, RSA and AES')
xlabel('Data sizes in bytes')
ylabel('Thruputs')

% CE, AES, RSA Power consumptions
plot(datab,PCE)
hold on
plot(datab,PRSA);
hold on
plot(datab,PAES);
title('Energy Consumption of Chaotic, RSA and AES Algorithms')
xlabel('Data sizes in kilo bits')
ylabel('Energy Consumed in joules')

%----------------End of Program--------------------------------