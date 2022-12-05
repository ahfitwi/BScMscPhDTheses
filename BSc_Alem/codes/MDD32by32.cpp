 /*Alem/Betty/Mehari 2006*/
  #include<fstream.h>
  #include<conio.h>
  #include<stdlib.h>
  #include<math.h>
  #include<iomanip.h>
 /******************prototype of functions*************************************/

	 void D(int Img[],int cic,int Digest[]);
	 void MD(int Digest[160],long int betty[10]);

 /******************Beginning of main function*********************************/

	 void main ()
   	{
          int cic;
          long int TMD[10];
	       int Digest[160];
  /****************************************************************************/
    int BP;
    char bb;
    int B[10000];
    ifstream fp;
    fp.open("c:\\MDD.doc",ios::in);
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
           //cout<<B[c];
           c++;
      }

  /****************************************************************************/


    int Img[50000];
      for(int j=0;j<c;j++)
	     {
	      Img[j]=B[j];
         }
  /****************************************************************************/
   for(int i=0;i<512;i++)
      {
         if((c%512)!=0)
           c++;
         else if((c%512)==0)
           break;
       }
      cic=c/512;
   /***************************************************************************/
   cout<<"\t\t***CIC by ABM***\n\n";
  /******************Functio calling*******************************************/
   cout<<"\n Th message digest of the decrypted image is:\n\n";
   cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
        D(Img,cic,Digest);
        MD(Digest,TMD);
   cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
  /****************************************************************************/

          getch();
			}
 /*****************End of main function****************************************/

 /*******************Initializing buffers**************************************/
 int h0[32]={0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1};
 int h1[32]={1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1};
 int h2[32]={1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0};
 int h3[32]={0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0};
 int h4[32]={1,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0};


/******************************************************************************/
 void D(int Img[],int cic,int Digest[])
 {
	int a[32], b[32],c[32],d[32],e[32],f[32],k[32];
	int k1[32]={0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1};
	int k2[32]={0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1};
	int k3[32]={1,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0};
	int k4[32]={1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,1,1,1,0,1,0,1,1,0};
	int Img_pad[30000],i=0,j=0,ctrl,s,Imgpad[100][512];
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

 /*****************************************************************************/

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

 /****************************************************************************/
	 for(i=0;i<32;i++)
	  {
		a[i]=h0[i];
		b[i]=h1[i];
		c[i]=h2[i];
		d[i]=h3[i];
		e[i]=h4[i];
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

	int m,n,Cin=0,Cout,ad1[32],ad2[32],ad3[32],temp[32];
	for(m=31;m>=0;m--)
	 {
	  ad1[m]=Cin^a[m]^f[m];
	  Cout=(Cin&a[m])|(Cin&f[m])|(a[m]&f[m]);
	  Cin=Cout;
	 }
	Cin=0;
	for(m=31;m>=0;m--)
	{
	  ad2[m]=Cin^ad1[m]^e[m];
	  Cout=(Cin&ad1[m])|(Cin&e[m])|(ad1[m]&e[m]);
	  Cin=Cout;
	}
	Cin=0;
	for(m=31;m>0;m--)
	{
	  ad3[m]=Cin^ad2[m]^k[m];
	  Cout=(Cin&ad2[m])|(Cin&k[m])|(ad2[m]&k[m]);
	  Cin=Cout;
	}
	Cin=0;
	for(m=31;m>=0;m--)
	{
	 temp[m]=Cin^ad3[m]^w[i][m];
	 Cout=(Cin&ad3[m])|(Cin&w[i][m])|(ad3[m]&w[i][m]);
	 Cin=Cout;
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

 /************************************************************************************/
int u,q,Cin=0,Cout;
 for(u=31;u>=0;u--)
 {
  h0[u]=Cin^h0[u]^a[u];
  Cout=(Cin&h0[u])|(Cin&a[u])|(h0[u]&a[u]);
  Cin=Cout;
 }
 Cin=0;
 for(u=31;u>=0;u--)
 {
  h1[u]=Cin^h1[u]^b[u];
  Cout=(Cin&h1[u])|(Cin&b[u])|(h1[u]&b[u]);
  Cin=Cout;
 }
 Cin=0;
 for(u=31;u>=0;u--)
 {
  h2[u]=Cin^h2[u]^c[u];
  Cout=(Cin&h2[u])|(Cin&c[u])|(h2[u]&c[u]);
  Cin=Cout;
 }
 Cin=0;
 for(u=31;u>=0;u--)
 {
  h3[u]=Cin^h3[u]^d[u];
  Cout=(Cin&h3[u])|(Cin&d[u])|(h3[u]&d[u]);
  Cin=Cout;
 }
 Cin=0;
 for(u=31;u>=0;u--)
 {
  h4[u]=Cin^h4[u]^e[u];
  Cout=(Cin&h4[u])|(Cin&e[u])|(h4[u]&e[u]);
  Cin=Cout;
 }

 }
 /******************************************************************************/
 for( int q=0;q<32;q++)
 {
  Digest[q]=h0[q];
 }
 for(int q=32;q<64;q++)
 {
  Digest[q]=h1[q-32];
 }
 for(int q=64;q<96;q++)
 {
  Digest[q]=h2[q-64];
 }
 for( int q=96;q<128;q++)
 {
  Digest[q]=h3[q-96];
 }
 for(int q=128;q<160;q++)
 {
  Digest[q]=h4[q-128];
 }
}
/*****************************************************************************/
void MD(int Digest[160], long int TMD[10])
	  {

		   int Cbit=0,con=0,u;
		   do
		   {
		     long int Mdigest=0;
		     int Index=15;
		     for(u=0;u<16;u++)
		       {
		        Mdigest=Mdigest+Digest[Cbit]*(long int)pow(2,Index);
		        Cbit++;
		        Index--;
		       }
		  TMD[con]=Mdigest;
		  cout<<TMD[con];
		  con++;
	  }
	  while(Cbit!=160);
		 cout<<endl;

  ofstream btt;
  btt.open("c:\\MDDE.txt",ios::out|ios::binary);
      if (!btt)
         {
           cout<<"\n\n***ERROR!!***\n";
          }
   for(int i=0;i<10;i++)
      {
        btt<<TMD[i]<<'\t';
       }
     cout<<endl;
    btt.close();
	  }




