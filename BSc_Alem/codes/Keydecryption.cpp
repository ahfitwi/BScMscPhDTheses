#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<iomanip.h>
#include<fstream.h>

long double R(long double,long double);
int convert(int);
void main()
{
 cout<<"\t\t***CIC by ABM***\n\n";
 cout<<"*******************++++++++++++++++++++++*******************\n\n";
 ifstream keyread;
  keyread.open("abm.key",ios::in);
  if(keyread.bad())
	 {cout<<"\n Error"; }

 char kk;
 char ki[8];
 int co=0;
 while(keyread.get(kk))
	 {
	  ki[co]=kk;
	  co++;
	  }

	  keyread.close();



 long int sum=0,j,c1=7,f;
 int X;
 for (j=0;j<8;j++)
	 {
	  X=( int)ki[j];
	  f=convert(X);
	  sum+=f*pow(10,c1);
	  c1--;
	  }

  long double x,s,z,i,n,h;
  unsigned long int y,t;
  cout<<"Enter your privet key to get your DES key:\t"<<endl;
   cout<<"*******************++++++++++++++++++++++*******************\n\n";
  cout<<"\n Private Key:\t";
  cin>>y;
   cout<<"*******************++++++++++++++++++++++*******************\n\n";
  x=sum;
 n=69175313;
  z=x;
  s=x;
  t=y-1;

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
			 cout<<"\nUse the following DES key to decrypt the image"<<endl;
					cout<<" \nHere is your DES key:\t";
					cout<<setprecision(10)<<z;
					cout<<endl;
					cout<<endl;
         cout<<"*******************++++++++++++++++++++++*******************\n\n";
               getch();

			  }

	  long double R(long double c,long double b )
			  {
				 while(c>b)
				  {
					 c=c-b;
				  }
				return c;
				}

	  int convert( int X)
		  {
				int b;
				switch(X)
				 {
				  case(48):
					{b=0;
					 break;
					}
				  case(49):
					{
					 b=1;
					 break;
					}
				  case(50):
					{b=2;
					 break;
					}
				  case(51):
					{b=3;
					 break;
					}
				  case(52):
					{b=4;
					 break;
					}
				  case(53):
					{
					 b=5;
					 break;
					}
				  case(54):
					{
					b=6;
					break;
				  }
				  case(55):
					{
					 b=7;
					 break;
					}
				  case(56):
					{
					 b=8;
					 break;
					 }
				  case(57):
					{
					 b=9;
					 break;
					}
				  }
				  return b;
			  }

