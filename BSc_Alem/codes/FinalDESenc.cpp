  #include<fstream.h>
  #include<iostream.h>
  #include<conio.h>
  #include<math.h>
  #include<stdlib.h>
  #include<stdio.h>

  /****************************************************************************/
  void IP(int Image[][64],int BP,int Lo[],int Ro[]);
  void f(int Ro[],int Lo[],int Kn[][48]);
  int BB=0,cv=0;//Global variables
  /****************************************************************************/
  void main ()
	{

		 int i,j;
		 int BP,Lo[32],Ro[32];

  /****************************************************************************/


            unsigned char Img[256][256],Row[256];
            int W,H;
            char Name[20];
            FILE*fope;
            cout<<"\nEnter the image dimensions in pixel:";
            cout<<"\nEnter the width,W:\n\t";
            cin>>W;
            cout<<"\nEnter the height,H:\n\t";
            cin>>H;
            flushall();

/****************Reading the image (cic.png)***********************************/

            printf("\nEnter the proper path of the saved image:\n\n\t");
            gets(Name);
            fope=fopen(Name,"rb");
            if(fope==NULL)
             {
	             printf("\n\tError!!\n");
	             exit(1);
              }

/**************Reading pixels values of the image******************************/

            for(i=0;i<H;i++)
             {
               fread(Row,1,W,fope);
               for(j=0;j<W;j++)
                 {
	                 Img[i][j]=Row[j];
                  }
              }
            fclose(fope);


/****************Conversion of image  into binary numbers**********************/


	  int Q,R,B[100000],P[100000],c1=0,c12=0;//Q=quotient,R=reminder,B=binary number;

	  for( i=0;i<32;i++)

			for(int j=0;j<32;j++)
				{
					int n=Img[i][j],c=0;//c=counter,w/c counts # of bits

					do{
						Q=n/2;
						R=n%2;
						n=Q;
						B[c]=R;
						//cout<<B[c];
						c++;
						c1++;
					}while(c!=8);
               ofstream mtx;
               mtx.open("c:\\MDOI1.doc",ios::out|ios::app);
               if(!mtx)
                 {
                  cout<<"\n ERROR!!";
                }
               else
                {

				     for(int h=0;h<8;h++)
				    	{
                    P[c12]=B[7-h];
						  mtx<<P[c12];
                    //cout<<P[c12];
						  c12++;
                   }
                }

				}

 
/**********************End of conversion***************************************/

		  int Pixel_counter=0;
		  int NBs=(c12/64);
		  int Image[200][64];

			for(  BP=0;BP<NBs;BP++)
			{
				for(int j=0;j<64;j++)
				{
				  Image[BP][j]=P[Pixel_counter];
				  //cout<<Image[BP][j];
					Pixel_counter++;
				  }

			}
			cout<<endl;
 /****************** Key  scheduling*******************************************/

	int key[8];
	cout<<"\n Enter your 8-digit DES key:"<<endl;
	cout<<endl;

	for(i=0;i<8;i++)
	 {
	  cout<<"key["<<(i+1)<<"]=";
	  cin>>key[i];
	  }
	int Keybit[64];
	int ctrl=0;
	long int bi[8];

	for(i=0;i<8;i++)
	 {
		 int N,Q;
		 N=(int)key[i];
		 int j=0;
		 do
			{
			 Q=N/2;
			 bi[j]=N%2;
			 N=Q;
			 j++;
			 }
		  while(j!=8);

		 for(int ctr=0;ctr<8;ctr++)
			{
				Keybit[ctrl]=bi[7-ctr];
				ctrl++;
			}

	  }

 /*****************************************************************************/

		int pc_1[8][7]={
						{Keybit[56],Keybit[48],Keybit[40],Keybit[32],Keybit[24],Keybit[16],Keybit[8]},
						{Keybit[0], Keybit[57],Keybit[49],Keybit[41],Keybit[33],Keybit[25],Keybit[17]},
						{Keybit[9], Keybit[1], Keybit[58],Keybit[50],Keybit[42],Keybit[34],Keybit[26]},
						{Keybit[18],Keybit[10],Keybit[2], Keybit[59],Keybit[51],Keybit[43],Keybit[35]},
						{Keybit[62],Keybit[54],Keybit[46],Keybit[38],Keybit[30],Keybit[22],Keybit[14]},
						{Keybit[6], Keybit[61],Keybit[53],Keybit[45],Keybit[37],Keybit[29],Keybit[21]},
						{Keybit[13],Keybit[5], Keybit[60],Keybit[52],Keybit[44],Keybit[36],Keybit[28]},
						{Keybit[20],Keybit[12],Keybit[4], Keybit[27],Keybit[19],Keybit[11],Keybit[3]}
						};

		int k=0;
		int Co[28],Do[28];

		for (i=0;i<4;i++)
		  for(int j=0;j<7;j++)
			{
			 Co[k]=pc_1[i][j];
			 k++;
			 }
		k=0;
		for (i=4;i<8;i++)
		  for(int j=0;j<7;j++)
			  {
				Do[k]=pc_1[i][j];
				k++;
				}

		 int IT[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
		 int c2,d2;
		 int key2[16][56];
		 int Kn[16][48];

		 for (int l=0;l<16;l++)
			 {
				if ((IT[l])==1)
				 {
					c2=Co[0];
					d2=Do[0];
					for (int j=0;j<27;j++)
					  {
						 Co[j]=Co[j+1];
						 Do[j]=Do[j+1];
						 }
					Co[27]=c2;
					Do[27]=d2;
				 }
				 else
					{
					  for(i=0;i<2;i++)
						{
						  c2=Co[0];
						  d2=Do[0];
						  for (j=0;j<27;j++)
							{
							  Co[j]=Co[j+1];
							  Do[j]=Do[j+1];
							  }
							 Co[27]=c2;
							 Do[27]=d2;
							}
					  }


				for (j=0;j<28;j++)
					 key2[l][j]=Co[j];
				for (j=28;j<56;j++)
					 key2[l][j]=Do[j-28];

				int pc_2[48]={
					  key2[l][13],key2[l][16],key2[l][10],key2[l][23],key2[l][0], key2[l][4],
					  key2[l][2], key2[l][27],key2[l][14],key2[l][5], key2[l][20],key2[l][9],
					  key2[l][22],key2[l][18],key2[l][11],key2[l][3], key2[l][25],key2[l][7],
					  key2[l][15],key2[l][6], key2[l][26],key2[l][19],key2[l][12],key2[l][1],
					  key2[l][40],key2[l][51],key2[l][30],key2[l][36],key2[l][46],key2[l][54],
					  key2[l][29],key2[l][39],key2[l][50],key2[l][44],key2[l][32],key2[l][47],
					  key2[l][43],key2[l][48],key2[l][38],key2[l][55],key2[l][33],key2[l][52],
					  key2[l][45],key2[l][41],key2[l][49],key2[l][35],key2[l][28],key2[l][31]};


			  int ctr=0;
			  for (j=0;j<48;j++)
				{
				  Kn[l][j]=pc_2[j];
				  //cout<<Kn[l][j];
				  ctr++;
				  }
                // cout<<endl;
			 }
             cout<<endl;

			 cout<<"\n The cipher(encrypted) image in integer format is:\n"<<endl;
			 cout<<"\n**+ImageImageImageImageImageImageImageImageImage+**\n"<<endl;

	/********************Function calling**************************************/

			 for (  BP=0;BP<NBs;BP++)
			 {
							IP(Image,BP,Lo,Ro);
							f(Ro,Lo,Kn);
			 }
			 cout<<"\n**+ImageImageImageImageImageImageImageImageImage+**\n"<<endl;
          getch();
		 }


		/***************************** Initial permutation***********************/

		 void IP(int Image[][64],int BP, int Lo[],int Ro[])
		  {
			int Ip[8][8]={
			{Image[BP][57],Image[BP][49],Image[BP][41],Image[BP][33],Image[BP][25],Image[BP][17],Image[BP][9], Image[BP][1]},
			{Image[BP][59],Image[BP][51],Image[BP][43],Image[BP][35],Image[BP][27],Image[BP][19],Image[BP][11],Image[BP][3]},
			{Image[BP][61],Image[BP][53],Image[BP][45],Image[BP][37],Image[BP][29],Image[BP][21],Image[BP][13],Image[BP][5]},
			{Image[BP][63],Image[BP][55],Image[BP][47],Image[BP][39],Image[BP][31],Image[BP][23],Image[BP][15],Image[BP][7]},
			{Image[BP][56],Image[BP][48],Image[BP][40],Image[BP][32],Image[BP][24],Image[BP][16],Image[BP][8], Image[BP][0]},
			{Image[BP][58],Image[BP][50],Image[BP][42],Image[BP][34],Image[BP][26],Image[BP][18],Image[BP][10],Image[BP][2]},
			{Image[BP][60],Image[BP][52],Image[BP][44],Image[BP][36],Image[BP][28],Image[BP][20],Image[BP][12],Image[BP][4]},
			{Image[BP][62],Image[BP][54],Image[BP][46],Image[BP][38],Image[BP][30],Image[BP][22],Image[BP][14],Image[BP][6]}
							 };

			int i,j,k;
			k=0;
			for(i=0;i<4;i++)
			 for(j=0;j<8;j++)
			 {
			  Lo[k]=Ip[i][j];
			  k++;
			  }

		  k=0;
		  for(i=4;i<8;i++)
			 for(j=0;j<8;j++)
			  {
				 Ro[k]=Ip[i][j];
				 k++;
			  }
		}


	/**********************Calculation of f(R,K)********************************/

	void f(int Ro[],int Lo[],int Kn[][48])
	  {
		 int s1(int row,int column);
		 int s2(int row,int column);
		 int s3(int row,int column);
		 int s4(int row,int column);
		 int s5(int row,int column);
		 int s6(int row,int column);
		 int s7(int row,int column);
		 int s8(int row,int column);

		 int i,l=0;
		 int XOR[48];
		 int sbox[8][6];
		 int p[32];
		 int row,column;
		 int IMBF[32];
		 int LP;
		 for(LP=0;LP<16;LP++)
		  {
			int EST[48]={
					Ro[31],Ro[0], Ro[1], Ro[2], Ro[3], Ro[4],
					Ro[3], Ro[4], Ro[5], Ro[6], Ro[7], Ro[8],
					Ro[7], Ro[8], Ro[9], Ro[10],Ro[11],Ro[12],
					Ro[11],Ro[12],Ro[13],Ro[14],Ro[15],Ro[16],
					Ro[15],Ro[16],Ro[17],Ro[18],Ro[19],Ro[20],
					Ro[19],Ro[20],Ro[21],Ro[22],Ro[23],Ro[24],
					Ro[23],Ro[24],Ro[25],Ro[26],Ro[27],Ro[28],
					Ro[27],Ro[28],Ro[29],Ro[30],Ro[31],Ro[0]
					};


	  for(i=0;i<48;i++)
		{
		  XOR[i]=EST[i]^Kn[LP][i];
		}
	  int cr=0;
	  for(i=0;i<8;i++)
		{
		 for(int j=0;j<6;j++)
		  {
			 sbox[i][j]=XOR[cr];
			 cr++;
				}
		  }

	  int q=0;
	  int m=0;
		for(int j=0;j<8;j++)
		 {
		  row=(sbox[j][0]*2)+(sbox[j][5]);
		  column=(sbox[j][1]*8)+(sbox[j][2]*4)+(sbox[j][3]*2)+(sbox[j][4]);

		int B;

		if((j+1)==1)
			{
			  B=s1(row,column);
			}

		else if((j+1)==2)
			{
			  B=s2(row,column);
			}
		else if((j+1)==3)
			{
			  B=s3(row,column);
			}
		else if((j+1)==4)
			{
			  B=s4(row,column);
			}
		else if((j+1)==5)
			{
			  B=s5(row,column);
			}
		else if((j+1)==6)
			{
			  B=s6(row,column);
			}
		else if((j+1)==7)
			{
			  B=s7(row,column);
			}
		else if((j+1)==8)
			{
			  B=s8(row,column);
			}


	  int Qt,IMB1[4];
	  int bc=0;

	  do{
		  Qt=B/2;
		  IMB1[bc]=B%2;
		  B=Qt;
		  bc++;
		 }while(bc!=4);

		 int IMB2[4];
		 for(int u=0;u<4;u++)
		  {
			IMB2[u]=IMB1[3-u];
		  }
		 for(int u=0;u<4;u++)
		  {
			p[m]=IMB2[u];
			 m++;
			}
		  }

	 int IMBF1[32]={
					  p[15],p[6], p[19],p[20],p[28],p[11],p[27],p[16],
					  p[0], p[14],p[22],p[25],p[4], p[17],p[30],p[9],
					  p[1], p[7], p[23],p[13],p[31],p[26],p[2], p[8],
					  p[18],p[12],p[29],p[5], p[21],p[10],p[3], p[24]
					  };

	 for(int t=0;t<32;t++)
		 {
		  IMBF[t]=IMBF1[t];
		  }

	  int L1[32];
	  for(int t=0;t<32;t++)
		  {
			L1[t]=Lo[t];
			Lo[t]=Ro[t];
			Ro[t]=L1[t]^IMBF[t];
			}
	 }

	 int Cm[64];
	 int v,s;
	 for(v=0;v<32;v++)
	  {
		Cm[v]=Ro[v];
		}
	 for(s=32;s<64;s++)
	  {
		Cm[s]=Lo[s-32];
	  }

	  int cipher[64]={
					Cm[39],Cm[7],Cm[47],Cm[15],Cm[55],Cm[23],Cm[63],Cm[31],
					Cm[38],Cm[6],Cm[46],Cm[14],Cm[54],Cm[22],Cm[62],Cm[30],
					Cm[37],Cm[5],Cm[45],Cm[13],Cm[53],Cm[21],Cm[61],Cm[29],
					Cm[36],Cm[4],Cm[44],Cm[12],Cm[52],Cm[20],Cm[60],Cm[28],
					Cm[35],Cm[3],Cm[43],Cm[11],Cm[51],Cm[19],Cm[59],Cm[27],
					Cm[34],Cm[2],Cm[42],Cm[10],Cm[50],Cm[18],Cm[58],Cm[26],
					Cm[33],Cm[1],Cm[41],Cm[9], Cm[49],Cm[17],Cm[57],Cm[25],
					Cm[32],Cm[0],Cm[40],Cm[8], Cm[48],Cm[16],Cm[56],Cm[24]
					};
	  
    // int Cip[10000];
	 ofstream outCIM;
	 outCIM.open("c:\\EIM.doc",ios::out|ios::app);

	 for(int u=0;u<64;u++)
	 {
     //Cip[cv]=cipher[u];
     //outCIM<<Cip[cv];
     outCIM<<cipher[u];
     //cout<<cipher[u];
     if(!((u+1)%64))cout<<endl;
     //cv++;
	  }
	 outCIM.close();

	 int pc=0;
		  do
			{
			 int Encrypted=0;
			 int Index=7;
			 for(int bitc=0;bitc<8;bitc++)
			  {
				Encrypted=Encrypted+cipher[pc]*pow(2,Index);
				pc++;
				Index--;

				}
         cout<<Encrypted<<'\t';
			 }
			while(pc!=64);
	 
	  BB++;
	}

/**************************Definition of the SBOX functions********************/

int s1(int row,int column)
{
 int T1[4][16]={
					{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
					{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
					{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
					{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
					 };
 return T1[row][column];
 }

 int s2(int row,int column)
{
 int T2[4][16]={
					 {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
					 {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
					 {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
					 {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
					 };
 return T2[row][column];
 }

int s3(int row,int column)
{
 int T3[4][16]={
					 {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
					 {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
					 {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
					 {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
					 };
 return T3[row][column];
 }

int s4(int row,int column)
{
 int T4[4][16]={
					 {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
					 {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
					 {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
					 {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
					 };
 return T4[row][column];
 }

int s5(int row,int column)
{
 int T5[4][16]={
					 {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
					 {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
					 {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
					 {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
					 };
 return T5[row][column];
 }

int s6(int row,int column)
{
 int T6[4][16]={
					 {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
					 {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
					 {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
					 {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
					 };
 return T6[row][column];
 }

int s7(int row,int column)
{
 int T7[4][16]={
					 {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
					 {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
					 {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
					 {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
									 };
 return T7[row][column];
 }

int s8(int row,int column)
{
 int T8[4][16]={
					 {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
					 {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
					 {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
					 {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
					 };
 return T8[row][column];
 }
 /*********************End of program******************************************/