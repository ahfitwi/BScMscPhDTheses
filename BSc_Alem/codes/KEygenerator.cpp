 /*Alem/Betty/Mehari 2006*/
 #include<iostream.h>
 #include<math.h>
 #include<conio.h>

 /**************************************************************************/

 void main ()
 {

   long int A,B,C,F,G,H,I,J,d;
   long int K,q,p,Q,Phi,e,n,pr;
   cout<<"\t\t***CIC by ABM***\n\n";
   cout<<"\nEnter 2-already generated prime numbers, p and q :\n";
   cout<<"*********************+++++++++++++++++++++++++++*****\n\n";
   cout<<"\n\t\tEnter p:\n\t\t\t";
   cin>>p;
   cout<<"\n\t\tEnter q:\n\t\t\t";
   cin>>q;
   n=p*q;
   cout<<"\n\t\tn="<<n;
   cout<<endl;
   Phi=(p-1)*(q-1);
   cout<<"\n\t\tphi="<<Phi;
   cout<<endl;
   cout<<"\n\t\tEnter e :\n\t\t\t";
   cin>>e;
	A=e;
	B=Phi;
	if(B==0)
	 {
	    d=A;
	    C=1;
	    F=0;
	    cout<<"\n\t\td="<<C;
     }

    G=1;
    H=0;
    I=0;
    J=1;

    long int M;
    M=B;
	  while(B>0)
	  {
		 Q=A/B;
		 K=A-Q*B;
		 C=G-Q*H;
		 F=I-Q*J;
		 A=B;
		 B=K;
		 G=H;
		 H=C;
		 I=J;
		 J=F;
	  }

	  d=A;
	  C=G;
	  F=I;

	  if(C<0)
	    {
		   C=C+M;
	    }

	  if(d!=1)
		 {
		   cout<<"\nWarning!!e="<<e<<"and(p-1)||e="<<e<<"and(q-1)is"
			  <<"\n not relatively prime.";
		   cout<<"\n\t\t!!!Try again!!!";
		 }
	  else
	   {
		  cout<<"\n\t\tgcd ="<<d<<endl;
		  cout<<"\n\t\td="<<C;
		  cout<<endl;
   	 }
 cout<<"\n\n***************++Therefore++*************************";
 cout<<"\n\t\tThe public key is:\n";
 cout<<"\t\t\t"<<e;
 cout<<"\n\n\t\tThe private key is:\n";
 cout<<"\t\t\t"<<C;
 cout<<"\n\n\t\tThe modulus is:\n";
 cout<<"\t\t\t"<<n;
 cout<<"\n\n*************+++END OF PROGRAM+++*********************";
 cout<<endl;
 cout<<endl;
 getch();
 }

 /********************************End of program******************************/
