/**********************ABMCIC**************************************************/
#include<fstream.h>
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>
/******************************************************************************/
long  double Rem(long  double a,long double b);

/******************************************************************************/

void main()
{
  cout<<"\t\t***CIC BY ABM***";
  cout<<"\n\nThe message digest of the original image:\n\n";
  cout<<"************++++++++++++++++++++++*************************\n";
  ifstream btt;
  double ch,tt[10];
  btt.open("c:\\betty150.txt",ios::in|ios::binary);
      if (!btt)
         {
           cout<<"\n\n***ERROR!!***\n";
          }
   for(int i=0;i<10;i++)
      {
        btt>>ch;
        tt[i]=ch;
        cout<<tt[i];
       }
     cout<<endl;
    btt.close();
 cout<<"\n*************========+++++++++++++++++=======**************";
/******************************************************************************/
  cout<<"\n\nThe encrypted message digest of the original image is:\n\n";
  cout<<"*******************++++++++++++++++++++********************\n";
  long double n=75301,rr,kk,bb,I,bett[10];
  long int d=7,t;
  for(int q=0;q<10;q++)
   {
    rr=tt[q];
    kk=tt[q];
    t=d-1;
    while(t>0)
    {
     if(t%2==0)
     {
       t=t/2;
       I=kk*kk;
       kk=Rem(I,n);
     }
     else
     {
       bb=rr*kk;
       kk=Rem(bb,n);
       t=t-1;
      }
    }
    bett[q]=kk;
    cout<<setprecision(12)<<bett[q];
  }
 cout<<"\n\n*******************++++++++++++++++++++++******************\n";
  ofstream op;
  op.open("c:\\bet40.doc",ios::out);
  for(int i=0;i<10;i++)
   {
     op<<bett[i]<<" ";
     }
   op.close();

   getch();
   }
/****************Definition of the Rem function********************************/
long double Rem(long double a,long double b)
  {
    long double c;
    c=a;
    while(c>b)
      {
       c=c-b;
       }
     return c;
   }
/***********************End of program*****************************************/