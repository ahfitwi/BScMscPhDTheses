/************Reading an image saved in local disk c as"c:\\cic.png"************/
#include<fstream.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
/******************************************************************************/
void main()
 {
            int i,j;
            int n=3;
            unsigned char Image[256][256],Row[256];
            int W,H;
            char Name[20];
            FILE *fope;
            cout<<"\nEnter the image dimensions:";
            cout<<"\nEnter the width,W:\n\t";
            cin>>W;
            cout<<"\nEnter the height,H:\n\t";
            cin>>H;
            flushall();

/****************Reading the image********************************************/

            printf("\nEnter the proper path of the saved image:\n\n\t");
            gets(Name);
            fope=fopen(Name,"rb");
            if(fope==NULL)
             {
	             printf("\n\tError!!\n");
	             exit(1);
              }

/**************Reading pixels values of the image****************************/

            for(i=0;i<H;i++)
             {
               fread(Row,1,W,fope);
               for(j=0;j<W;j++)
                 {
	                 Image[i][j]=Row[j];
                  }
              }
            fclose(fope);

/******write out the pixel values of the image********************************/


            for(i=0;i<H;i++)
               {
                 for(j=0;j<W;j++)
	                 {
	                  printf("%d",Image[i][j]);
                     printf("\t");
                    }
                 printf("\n");
               }
              getch();


 }
