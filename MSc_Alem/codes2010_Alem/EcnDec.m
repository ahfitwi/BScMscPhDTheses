%@uthor: Alem Haddush Fitwi, M.Sc in Computer Engineering
%Chaotic Encryption using a shared image as a key
%AAU, FOT, ECE, May, 2010
%--------------------------------------------------------------------------
%------------Constants----------
a=0.0049;
var=5.98732516340;
keyL=136;
k=keyL;
sn=5; %scroll number
mult=69621;
m=2147483647;
Xo=1;%seed-1
X1=1000;%seed-2
X2=7;%seed-3
X3=1100;%seed-4
%--------------------------------------------------------------------------
%Step-1: Accessing the shared image
%________________________________
keyImage=imread('key.jpg');
%--------------------------------------------------------------------------
%Step-2: Image processing
%________________________
%keyImage size=261x326
keyGray=rgb2gray(keyImage);%convert RGB image to grayscale
keyPixel=keyGray;%grabbing pixel values gray image
%--------------------------------------------------------------------------
%Step-3: Key Generation
%______________________
%step-3.1: Key Extraction

%----------PRNG LCG---------
for i=1:17
temp1=mod(mult*Xo,m);
indexX1(i)=mod(temp1,261);
temp2=mod(mult*X1,m);
indexX2(i)=mod(temp2,326);
Xo=indexX1(i);
X1=indexX2(i);
  %--------
temp3=mod(mult*X2,m);
indexY1(i)=mod(temp3,261);
temp4=mod(mult*X3,m);
indexY2(i)=mod(temp3,326);
X2=indexY1(i);
X3=indexY2(i);
end
%----------------------------
countX=1;
countY=1;
n=1;
while(n<=17)
   
        keyExtX(countX)=keyPixel(indexX1(n),indexX2(n));        
        countX=countX+1;
        keyExtY(countY)=keyPixel(indexY1(n),indexY2(n));        
        countY=countY+1;
        n=n+1;
end
%----------------------------
fid = fopen('keyExt.text','wb');
fwrite(fid,keyExtX(1,countX-1),'integer*1');
fclose(fid);
%----------------------------
%step-3.2: Convert the extracted key to binary values
countX=countX-1;
countY=countY-1;
%Xbinary
bitCountX=1;
for ii=1:countX
    cc1=1;
    nnx=keyExtX(ii);
    while(cc1<9)
        Qx=nnx/2;
        Rx=mod(nnx,2);
        nnx=Qx-Rx/2;
        Px(cc1)=Rx;	
        cc1=cc1+1;
    end
    
    for k=1:8
        keyBinaryX(bitCountX)=Px(cc1-k);        
        bitCountX=bitCountX+1;     	                		
    end
end
bitCountX=bitCountX-1;
%Ybinary
bitCountY=1;
for jj=1:countY
    cc2=1;
    nny=keyExtY(jj);
    while(cc2<9)
        Qy=nny/2;
        Ry=mod(nny,2);
        nny=Qy-Ry/2;
        Py(cc2)=Ry;	
        cc2=cc2+1;
    end
    
    for kk=1:8
        keyBinaryY(bitCountY)=Py(cc2-kk);        
        bitCountY=bitCountY+1;     	                		
    end
end
bitCountY=bitCountY-1;
%step-3.2: Key substitution using S-boxes of order GF(2^5)
S1=[14 21 7 28 18 16 27 1 3 17 8 13 25 4 5 22 30 15 19 24 31 6 20 11 2 0 29 10 12 9 23 26;
    24 16 18 0 13 11 19 27 5 12 20 1 7 26 4 8 30 15 21 28 23 31 9 17 29 10 2 22 6 25 3 14; 
    28 19 23 1 25 24 27 21 30 18 15 26 20 13 2 14 29 0 7 5 8 16 17 9 31 11 4 6 10 12 3 22; 
    6 15 18 3 0 27 23 11 12 25 20 4 31 5 9 7 14 1 24 17 21 30 16 10 8 2 13 29 19 26 28 22];

S2=[26 2 31 8 22 15 25 9 18 12 29 24 21 3 20 11 14 0 13 27 30 19 16 4 17 6 1 10 28 7 5 23; 
    1 26 3 0 13 4 25 6 14 18 15 24 21 9 12 19 30 5 11 27 28 20 23 22 2 7 29 16 10 31 8 17;
    14 22 2 10 4 16 8 21 18 27 19 17 28 15 11 9 20 24 29 0 6 23 12 1 3 13 7 26 31 5 30 25; 
    15 1 23 11 21 25 30 12 8 18 4 3 9 29 22 14 0 5 24 19 26 13 16 28 10 31 20 7 6 27 2 17];
 
S3=[13 11 27 10 16 12 30 5 29 17 31 8 24 3 6 4 0 7 20 2 26 22 15 23 19 21 25 28 18 14 1 9; 
    10 4 21 20 31 1 18 3 29 28 12 19 5 15 22 14 17 7 30 24 13 11 2 0 26 9 23 25 8 16 27 6; 
    10 20 21 23 24 26 1 31 27 17 2 0 16 25 22 29 9 14 11 3 19 5 28 6 7 30 15 13 4 18 8 12;
    2 16 21 17 27 7 15 22 28 8 18 23 24 25 12 10 26 14 0 9 31 19 3 29 20 6 5 4 1 11 13 30];
 
S4=[8 24 6 23 26 28 1 0 5 4 11 15 18 19 31 7 29 17 2 21 14 10 30 20 16 27 13 25 12 22 3 9; 
    28 25 2 29 1 12 27 17 3 7 11 6 5 26 13 31 14 21 0 23 9 24 19 10 16 20 18 15 22 4 8 30; 
    5 10 31 28 26 25 13 0 18 19 23 22 3 30 4 16 7 8 15 6 2 27 24 1 21 11 29 20 9 12 17 14; 
    22 31 2 21 27 23 26 0 24 3 25 28 4 7 18 29 14 9 11 5 17 13 8 12 19 15 1 30 16 20 6 10];
 
S5=[18 16 9 23 10 19 8 28 14 6 17 13 2 1 12 25 30 29 24 31 7 5 27 3 15 11 0 21 22 26 20 4; 
    17 23 28 15 0 11 21 25 19 30 7 13 22 27 18 24 16 31 8 12 10 6 3 5 1 29 9 2 4 20 14 26; 
    11 24 20 9 28 6 7 23 19 21 1 18 27 0 30 26 2 22 10 31 8 13 29 3 25 12 14 17 15 5 16 4; 
    10 28 0 21 23 18 7 27 12 14 8 11 29 26 22 4 31 1 3 6 2 19 9 17 20 25 15 5 30 24 16 13];
 
S6=[20 2 11 29 30 18 7 22 1 13 9 23 25 6 5 14 15 28 27 17 8 4 31 24 26 12 21 0 10 3 19 16; 
    21 15 14 0 8 13 4 9 1 23 12 25 20 22 17 16 28 10 30 29 24 19 6 7 26 27 5 2 31 3 11 18; 
    5 28 10 6 15 24 30 7 3 12 0 29 19 25 13 1 22 8 26 27 14 23 2 18 4 31 9 11 17 16 20 21; 
    25 4 8 15 23 14 7 5 24 18 1 17 27 26 31 22 6 21 30 2 16 3 10 13 9 29 19 12 11 20 0 28];
 
S7=[13 28 7 4 24 19 3 2 31 14 29 0 23 1 9 11 20 17 15 16 22 6 8 21 25 18 26 12 10 5 27 30; 
    25 24 1 2 30 8 20 27 11 23 6 12 0 28 19 26 15 3 5 21 9 17 31 16 18 7 29 13 10 14 4 22;
    11 10 4 24 20 5 18 30 17 8 23 15 25 27 19 31 2 7 3 14 28 12 9 16 1 0 21 6 22 13 26 29; 
    21 28 5 24 12 31 2 3 11 17 30 7 0 10 14 1 4 23 16 26 29 27 19 22 18 13 20 6 9 8 15 25];

%------------------------------------------------------------------------
%Padding
mm=mod(8*keyL,49);
for im=1:49-mm
    keyBinaryX(keyL*8+im)=0;
    keyBinaryY(keyL*8+im)=0;
end
%------------------------------------------------------------------------
ctrl=1;
cr=1;
cc4=1;
count1=max(size(keyBinaryX))/49;
while(ctrl~=(count1+1))
            %while begins here
			for i2=1:7
                for j2=1:7
                    sboxX(i2,j2)=keyBinaryX(cr);
					sboxY(i2,j2)=keyBinaryY(cr);
			 		cr=cr+1;
                end
            end
            
            for j3=1:7
                %---                
                rowX=sboxX(j3,1)*2+sboxX(j3,7);
                if(rowX==0)
                    rowX=1;
                end;
		        columnX=sboxX(j3,2)*16+sboxX(j3,3)*8+sboxX(j3,4)*4+sboxX(j3,5)*2+sboxX(j3,6);
                if(columnX==0)
                    columnX=1;
                end;
                rowY=sboxY(j3,1)*2+sboxY(j3,7);
                if(rowY==0)
                    rowY=1;
                end;
		        columnY=sboxY(j3,2)*16+sboxY(j3,3)*8+sboxY(j3,4)*4+sboxY(j3,5)*2+sboxY(j3,6);
                if(columnY==0)
                    columnY=1;
                end;
                if(j3==1)
                    sboxoX=S1(rowX,columnX);
                    sboxoY=S1(rowY,columnY);
                elseif(j3==2)
                    sboxoX=S2(rowX,columnX);
                    sboxoY=S2(rowY,columnY);
                elseif(j3==3)
                    sboxoX=S3(rowX,columnX);
                    sboxoY=S3(rowY,columnY);
                elseif(j3==4)
                    sboxoX=S4(rowX,columnX);
                    sboxoY=S4(rowY,columnY);
                elseif(j3==5)
                    sboxoX=S5(rowX,columnX);
                    sboxoY=S5(rowY,columnY);
                elseif(j3==6)
                    sboxoX=S6(rowX,columnX);
                    sboxoY=S6(rowY,columnY);
                elseif(j3==7)
                    sboxoX=S7(rowX,columnX);
                    sboxoY=S7(rowY,columnY);
                end; 
                %Binarization
                cc3=1;
                tempX=sboxoX;
                tempY=sboxoY;
                while(cc3<6)
                    Q1X=tempX/2;
                    Q1Y=tempY/2;
                    R1X=mod(tempX,2);
                    R1Y=mod(tempY,2);
                    tempX=Q1X-R1X/2;
                    tempY=Q1Y-R1Y/2;
                    BX(cc3)=R1X;
                    BY(cc3)=R1Y;
                    cc3=cc3+1;
                end
                for ll=1:5
                    SoX(cc4)=BX(cc3-ll);
                    SoY(cc4)=BY(cc3-ll);
                    cc4=cc4+1;
                end
                
            %---    
            end
            ctrl=ctrl+1;
   %while ends here
end 
%------------------------------------------------------------------------

%------------------------------------------------------------------------
ccb=1;
checkN=1;
ff=int16((cc4-1)/8);
 for j18=1:ff
     cc18=1;
     index20=7;
     SoXI=0; 
     SoYI=0; 
     while(cc18<9 && checkN~=cc4)
         SoXI=SoXI+SoX(ccb)*power(2,index20);
         SoYI=SoYI+SoY(ccb)*power(2,index20);
         ccb=ccb+1;
         cc18=cc18+1;
         checkN=checkN+1;
         index20=index20-1;
     end
     SoXInt(j18)=SoXI;     
     SoYInt(j18)=SoYI;
 end
%------------------------------------------------------------------------
ccb=1; 
     index20=cc4-1;
     SoXIn=0; 
     SoYIn=0; 
     cc18=1;
     while(cc18<cc4)
         SoXIn=SoXIn+SoX(ccb)*power(2,index20);
         SoYIn=SoYIn+SoY(ccb)*power(2,index20);
         ccb=ccb+1;
         cc18=cc18+1;
         index20=index20-1;
     end     
%------------------------------------------------------------------------
%step-4: generation of chaotic figures
%--------------------------------------------------------------------------
%step-4.1: Calculation of Initial Conditions
%a=0.0225,0.00225
b=sqrt(1-a^2);
Xo=var+SoXIn;% balanced 118811138160210142635318637165
Yo=var+SoYIn;% balanced 11515410245191208781102411495549 
%step-4.2: Solutions of System used for generation of chaos         
t=0.0:.1:9999+var;
X1=exp(a*t).*(Xo*cos(b*t)+1/b*(Yo-a*Xo).*sin(b*t));
Y1=exp(a*t).*(Yo*cos(b*t)+a/b*(Yo-a*Xo-b^2/a*Xo)*sin(b*t));
x=X1/(max(X1));
y=Y1/(max(Y1));
dec=0;
for i=1:sn
    plot(x+i,y-dec);
    dec=dec+0.1;
    hold on
end
%step-5: Saving the chaotic figure as image.
%--------------------------------------------------------------------------
%h=gcf=get current figure handle
saveas(gcf,'chaos.jpg');
chaosImage=imread('chaos.jpg');
%----------------------------------------------
%cropping
imsize=size(chaosImage);
Height=imsize(1);
width=imsize(2);
rect1=[201 181 800 180];
rect2=[201 361 800 180];
rect3=[201 521 800 180];
RGB1 = imcrop(chaosImage,rect1);
RGB2 = imcrop(chaosImage,rect2);
RGB3 = imcrop(chaosImage,rect3);
croppedimgray1=rgb2gray(RGB1);
croppedimgray2=rgb2gray(RGB2);
croppedimgray3=rgb2gray(RGB3);
cimbin1=croppedimgray1/255;
cimbin2=croppedimgray2/255;
cimbin3=croppedimgray3/255;
balancedOne=xor(cimbin1,cimbin2);
balancedFin=xor(balancedOne,cimbin3);
balancedFinG=balancedFin*255;
%---------------------------------------------

%step-6: Accessing and processing the plaintext message.
%--------------------------------------------------------------------------
%step-6.1: accessing the plaintextfavou
fid=fopen('plaintext.m');
if(fid==-1)
    display('File does not exist!');
else
    plainText=fileread('plaintext.m');
    display(plainText);
    plainTextInt=double(plainText);
    %display(plainTextInt);
    textSize=size(plainTextInt);
end;
%----------------------------------------

%step-6.2: converting the plaintext to binary values
cc6=1;
for j6=1:max(textSize)
    temp6=plainTextInt(j6);
    cc66=1;
    while(cc66<9)
        Q6=temp6/2;
        R6=mod(temp6,2);
        temp6=Q6-R6/2;
        B6(cc66)=R6;  
        cc66=cc66+1;
    end    
    for i6=1:8
        textBinary(cc6)=B6(cc66-i6);
        cc6=cc6+1;
    end    
end
%------------2D-DFT of plaintext---------------------
 c20=int16(sqrt(cc6-1))-1;
 c21=1; 
     for i21=1:c20
         for j21=1:c20
             plainTextDFT(i21,j21)=textBinary(c21);
             c21=c21+1;
         end
     end     
 plainDFT=fft2(double(plainTextDFT));
 %mesh(abs(plainDFT));
 %-----------------------------------------------
%step-7: pre-enciphering processes
%--------------------------------------------------------------------------
scale=(sqrt(8*max(textSize)));
sizedChaos=imresize(balancedFinG,[scale scale],'bicubic');
sizedC=imresize(chaosImage,[scale scale],'bicubic');
sizedChaosBin=sizedChaos/255;
cipherchaosran=randerr(int16(scale),int16(scale));

%if((8*max(textSize))<(h5*h25)/16)
i7=1;
size12=size(sizedChaosBin);
for ii7=1:min(size12)
    for jj7=1:max(size12)
        chaosCipher(i7)=sizedChaosBin(ii7,jj7);
        chaosCipherr(i7)=cipherchaosran(ii7,jj7);
        i7=i7+1;
    end
end
for hh=1:(8*max(textSize))
    ChaosCipher(hh)=chaosCipher(hh);
    ChaosCipher2(hh)=chaosCipher(hh);
end
ind=(randperm(20));
kmm=1;
for km=1:max(randperm(20))
    if(ind(km)>10)
        index100(kmm)=ind(km);
        kmm=kmm+1;
    end;
end

ind1=index100(7);
ind1=15;
XXo=33;
for hhh=1:ind1
    indexXx1=mod(3*XXo,137);
    if(ChaosCipher(indexXx1)==1)
        ChaosCipher(indexXx1)=0;
    end;
    XXo=indexXx1;
end

if(i7<(8*max(textSize)))
    for hh=1:(8*max(textSize))-i7
        chaosCipher(i7)=0;
        chaosCipher(i7+hh)=0;        
    end
end;
display('-----------------------------------------------------------------');
%step-8: Enciphering process
%--------------------------------------------------------------------------
 for i8=1:(8*max(textSize))
        cipherText(i8)=xor(textBinary(i8),ChaosCipher(i8));
 end  
 %------------2D DFT of cipher---------------------
 c10=int16(sqrt(8*max(textSize)))-1;
 cipherTextDFT1=int16(rand(c10));
 c11=1; 
     for i11=1:c10
         for j11=1:c10
             cipherTextDFT(i11,j11)=cipherText(c11);
             c11=c11+1;
         end
     end     
 cipherDFT=fft2(double(cipherTextDFT1));
 %mesh(abs(cipherDFT));
 %-----------------------------------------------
 c8=1;
 for j8=1:max(textSize)
     cc8=1;
     index=7;
     cipherIn=0; 
     while(cc8<9)
         cipherIn=cipherIn+cipherText(c8)*power(2,index);
         c8=c8+1;
         cc8=cc8+1;
         index=index-1;
     end
     cipherInt(j8)=cipherIn;     
 end
 %display(cipherInt);
 cipherTextt=char(cipherInt);
 display(cipherTextt);
         
 %step-9: Deciphering process
%--------------------------------------------------------------------------
display('-----------------------------------------------------------------');
 for i9=1:(8*max(textSize))
        DecryptedText(i9)=xor(cipherText(i9),chaosCipher(i9));
 end   
 c9=1;
 for j9=1:max(textSize)
     cc9=1;
     index9=7;
     decryptedIn=0; 
     while(cc9<9)
         decryptedIn=decryptedIn+DecryptedText(c9)*power(2,index9);
         c9=c9+1;
         cc9=cc9+1;
         index9=index9-1;
     end
     decryptedInt(j9)=decryptedIn;     
 end
 %display(decryptedInt);
 decryptedText=char(decryptedInt);
 display(decryptedText);
 %-------------------------------------------------------------------------