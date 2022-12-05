/**********************ABMCIC**************************************************/
#include<fstream.h>
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>

/******************************************************************************/
long  double Rem(long  double ,long double );
void CMP(long int Disign[10],long int alem[10]);
/******************************************************************************/

void main()
{
   long int checkMD[10];
  cout<<"\t\t***CIC by ABM***\n";
  cout<<"\n The encrypted message digest of the original image is:\n\n";
  cout<<"*****************+++++++++++++++++++++++++******************\n\n";
  ifstream btt;
  double ch,tt[10];
  btt.open("c:\\bet40.doc",ios::in|ios::binary);
      if (!btt)
      cout<<"\n\n***ERROR!!***\n" ;
    for(int i=0;i<10;i++)
    {
     btt>>ch;
     tt[i]=ch;
     cout<<tt[i];
    }
     cout<<endl;
    btt.close();

    ifstream ttt;
    double chh,ttb[10],alem[10];
    ttt.open("c:\\MDDE.txt",ios::in|ios::binary);
      if (!btt)
         {
           cout<<"\n\n***ERROR!!***\n";
          }
   for(int i=0;i<10;i++)
      {
        ttt>>chh;
        alem[i]=chh;
        checkMD[i]=alem[i];//alem[i]-1; hacking
       }
     cout<<endl;
    ttt.close();
  cout<<"\n*************+++++++++++++++++++++++++++++++++**************\n";
/******************************************************************************/
  long int e;
  cout<<"\n Enter the public key:"; //e=10679;
  cin>>e;
  cout<<"\n\nThe decrypted message digest of the original image is:\n\n";
  cout<<"*********+++++++++++++++++++++++++++++++++******************\n";
  long double n=75301,rr,kk,bb,I,bett[10];
  long int t,Disign[10];
  cout<<endl;
  for(int q=0;q<10;q++)
   {
    rr=tt[q];
    kk=tt[q];
    t=e-1;
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
       rr=Rem(bb,n);
       t=t-1;
      }
    }
    Disign[q]=rr;
    cout<<setprecision(12)<<Disign[q];
  }
  cout<<"\n\n*******++++++++++++COMPARING++++++++++++++******************";
  CMP(Disign,checkMD);
  ofstream op;
  op.open("c:\\bet.doc",ios::out);
  for(int i=0;i<10;i++)
   {
     op<<tt[i]<<'\t';
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

   /*******************Definitio of CMP function*********************************/

  void CMP(long int Disign[10], long int checkMD[10])
    {
	   int counter=0;
	   for (int i=0;i<10;i++)
	       {
	         if(checkMD[i]!=Disign[i])
		         {
		          cout<<"\n\n!!!IMAGE's been modified!!!Contact the sender!!";
		          break;
		         }
		      else
		        {
		          counter++;
		          continue;
		         }
          }
		 if(counter==10)
		  {
		  cout<<"\n\n!!DMD's exactly th same as the OMD!!Image is Intact!!\n\n";
		  }
      cout<<"\n\n***++++++++++++++++++++CHECKING++++++++++++++++++++++++++++*";
	  }

 /*********************end of program******************************************/
/***********************End of program*****************************************/