/*Alem/Betty/Mehari 2006*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<conio.h>
#include<math.h>
#include<iomanip.h>

/***************Function prototypes********************************************/

void MD(int Digest[]);
void D(int Img [],int cic,int Digest[]);

/*********************Main function********************************************/

void main()
{
  int Digest[160];
  int BP;
  char bb;
  int B[10000];
  ifstream fp;
  fp.open("c:\\MDOI1.doc",ios::in);
  if(!fp)
    {
      cout<<"\n ERROR!!";
    }
  int c=0;
  while(fp.get(bb))
     {
          if(bb==48)
             B[c]=0;
          if(bb==49)
             B[c]=1;
          c++;
      }

    fp.close();
   
  /****************************************************************************/

  int Img[100000],cic;

    for(int j=0;j<c;j++)
	   {
	    Img[j]=B[j];
      }
 /*****************************************************************************/

  for(int i=0;i<512;i++)
      {
         if((c%512)!=0)
           c++;
         else if((c%512)==0)
           break;
       }
      cic=c/512;

/******************************************************************************/
cout<<"\t\t***CIC by ABM***\n\n";
cout<<"\n The message digest of the original image is:\n\n"<<endl;
cout<<"*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*\n\n";
          D(Img,cic,Digest);
          MD(Digest);
cout<<"*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*\n";
getch();
}
/***********************End of main function**********************************/

/*******************Initializing buffers**************************************/
 int H0[32]={0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1};
 int H1[32]={1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1};
 int H2[32]={1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0};
 int H3[32]={0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0};
 int H4[32]={1,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0};


/**********************************************************************************/
 void D(int Img[],int cic,int Digest[])
 {
	int a[32], b[32],c[32],d[32],e[32],f[32],k[32];
	int k1[32]={0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1};
	int k2[32]={0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1};
	int k3[32]={1,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0};
	int k4[32]={1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,1,1,1,0,1,0,1,1,0};
	int Img_pad[30000],i=0,j=0,ctrl,s,Imgpad[20][512];
	int w[80][32];
	  for(i=0;i<8192;i++)
		  {
			Img_pad[i]=Img[i];
		  }

   int m=0;
   for(int r=0;r<cic;r++)
    {
     for(int de=0;de<512;de++)
      {
        Imgpad[r][de]=Img_pad[m];
        m++;
      }
   }
   for(int p=0;p<cic;p++)
	  {  ctrl=0;
       for(i=0;i<16;i++)
		    {
           for(j=0;j<32;j++)
			   {
				 w[i][j]=Imgpad[p][ctrl];
				 ctrl++;
			   }
         }

	/********************************************************************************/

   for(i=16;i<80;i++)
	  {
			for(j=0;j<32;j++)
			  {
				 w[i][j]=(w[i-3][j])^(w[i-8][j])^(w[i-14][j])^(w[i-16][j]);

           }
		int c2=w[i][0];
		for(j=0;j<31;j++)
			{
			  w[i][j]=w[i][j+1];

			}
		w[i][31]=c2;

	 }
    /**************************************************************************/

    /**************************************************************************/
	 for(i=0;i<32;i++)
	  {
		a[i]=H0[i];
		b[i]=H1[i];
		c[i]=H2[i];
		d[i]=H3[i];
		e[i]=H4[i];
		}
		for(i=0;i<8;i++)
		 {
		  for(j=0;j<32;j++)
		  {
			 if((i>=0)&&(i<=19))
				{
				  f[j]=(b[j]& c[j])|((!b[j])&d[j]);
				  k[j]=k1[j];
				}
			 else if((i>=20)&&(i<=39))
			  {
				 f[j]=(b[j]^c[j]^d[j]);
				 k[j]=k2[j];
			  }
			 else if((i>=40)&&(i<=59))
			 {
			  f[j]=(b[j]&c[j])|(b[j]&d[j])|(c[j]&d[j]);
			  k[j]=k3[j];
			 }
			else if((i>=60)&&(i<=79))
			 {
			  f[j]=(b[j]^c[j]^d[j]);
			  k[j]=k4[j];
			 }


		 }

		 for(s=0;s<5;s++)
		  {
			 int a1=a[0];
			 for(j=0;j<31;j++)
			  {
				 a[j]=a[j+1];
			  }
				 a[31]=a1;

		  }

	int m,n,Cic=0,Co,ad1[32],ad2[32],ad3[32],temp[32];
	for(m=31;m>=0;m--)
	 {
	  ad1[m]=Cic^a[m]^f[m];
	  Co=(Cic&a[m])|(Cic&f[m])|(a[m]&f[m]);
	  Cic=Co;
	 }
	Cic=0;
	for(m=31;m>=0;m--)
	{
	  ad2[m]=Cic^ad1[m]^e[m];
	  Co=(Cic&ad1[m])|(Cic&e[m])|(ad1[m]&e[m]);
	  Cic=Co;
	}
	Cic=0;
	for(m=31;m>0;m--)
	{
	  ad3[m]=Cic^ad2[m]^k[m];
	  Co=(Cic&ad2[m])|(Cic&k[m])|(ad2[m]&k[m]);
	  Cic=Co;
	}
	Cic=0;
	for(m=31;m>=0;m--)
	{
	 temp[m]=Cic^ad3[m]^w[i][m];
	 Co=(Cic&ad3[m])|(Cic&w[i][m])|(ad3[m]&w[i][m]);
	 Cic=Co;
	}
	for(s=0;s<30;s++)
	{
	 int b1=b[0];
	 for(j=0;j<31;j++)
	  {
		b[j]=b[j+1];
	  }
	 b[31]=b1;
	}
	for(n=0;n<32;n++)
	{
	 e[n]=d[n];
	 d[n]=c[n];
	 c[n]=b[n];
	 b[n]=a[n];
	 a[n]=temp[n];
	}
}

/******************************************************************************/
int u,q,Cic=0,Co;
 for(u=31;u>=0;u--)
 {
  H0[u]=Cic^H0[u]^a[u];
  Co=(Cic&H0[u])|(Cic&a[u])|(H0[u]&a[u]);
  Cic=Co;
 }
 Cic=0;
 for(u=31;u>=0;u--)
 {
  H1[u]=Cic^H1[u]^b[u];
  Co=(Cic&H1[u])|(Cic&b[u])|(H1[u]&b[u]);
  Cic=Co;
 }
 Cic=0;
 for(u=31;u>=0;u--)
 {
  H2[u]=Cic^H2[u]^c[u];
  Co=(Cic&H2[u])|(Cic&c[u])|(H2[u]&c[u]);
  Cic=Co;
 }
 Cic=0;
 for(u=31;u>=0;u--)
 {
  H3[u]=Cic^H3[u]^d[u];
  Co=(Cic&H3[u])|(Cic&d[u])|(H3[u]&d[u]);
  Cic=Co;
 }
 Cic=0;
 for(u=31;u>=0;u--)
 {
  H4[u]=Cic^H4[u]^e[u];
  Co=(Cic&H4[u])|(Cic&e[u])|(H4[u]&e[u]);
  Cic=Co;
 }

 }
 /******************************************************************************/
 for( int q=0;q<32;q++)
  {
   Digest[q]=H0[q];
   }
 for(int q=32;q<64;q++)
  {
   Digest[q]=H1[q-32];
   }
 for(int q=64;q<96;q++)
  {
   Digest[q]=H2[q-64];
   }
 for( int q=96;q<128;q++)
  {
   Digest[q]=H3[q-96];
   }
 for(int q=128;q<160;q++)
  {
   Digest[q]=H4[q-128];
   }
}

/***********************Message Digest function definition********************/
void MD(int Digest[160])
{
  int ABM[10];
  int f=0,co=0,u;
  do
  {
	 int Mdig=0;
	 int Index=15;
	 for(u=0;u<16;u++)
	 {
		Mdig=Mdig+Digest[f]*(int)pow(2,Index);
		Index--;
      f++;
	 }
	 ABM[co]=Mdig;
	 cout<<Mdig;
	 co++;
  }while(f!=160);
  cout<<endl;
  cout<<endl;

  ofstream btt;
  double ch,tt[10];
  btt.open("c:\\betty150.txt",ios::in|ios::binary);
      if (!btt)
         {
           cout<<"\n\n***ERROR!!***\n";
          }
   for(int i=0;i<10;i++)
      {
        btt<<ABM[i]<<'\t';

       }
     cout<<endl;
    btt.close();

    }
/******************End of program**********************************************/
