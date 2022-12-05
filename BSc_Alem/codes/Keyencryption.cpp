/*Alem/Betty/Mehari 2006*/
#include<fstream.h>
#include"conio.h"
#include<iomanip.h>
#include<math.h>
#include<iostream.h>

long double R(long double,long double);

void main()
 {
	long double x,z,s,i,n,h;
	unsigned long int y,t;
    cout<<"\t\t***CIC by ABM****\n\n";
	cout<<"\n Enter the DES key:\n";
   cout<<"**************************+++++++++++++++++++++****\n";
	cin>>x;
	y=65537;
	n=69175713;
	z=x;
	s=x;
	t=y-1;

 /******************Encryption process***********************************/

  while(t>0)
	{
	  if(t%2==0)
		{
		  t=t/2;
		  i=s*s;
		  s=R(i,n);
		 }
	  else
		{
		  h=z*s;
		  z=R(h,n);
		  t=t-1;
		}
	 }

  /*********************Print out the encrypted key************************/
     cout<<"\n**************************+++++++++++++++++++++****\n\n";
	 cout<<"\nThe encrypted DES key is:";
     cout<<"\n**************************+++++++++++++++++++++****\n";
	 cout<<endl<<setprecision(10)<<z<<endl;

  /*******************Write the encrypted key into a file******************/

	 ofstream outkey;
	 outkey.open("abm.key",ios::out);
	 if(outkey.bad())
	 {
	  cout<<"\n ERROR!!";
	  }
	 else
	  {
		outkey<<setprecision(10)<<z;
		}
	 outkey.close();
    cout<<"\n*********************END**+++++++++++++++++++++****\n\n";
    getch();

  }

  /******************************Define R function***************************/

  long double R(long double c,long double b)
	  {
		  while(c>b)
			 {
				c=c-b;
			  }
		 return c;
	   }
