/*prime number generastion*/
#include<iostream.h>
#include<math.h>
#include<conio.h>

void main()
{
 long int result,min,max;
 long int j;
 cout<<"\t\t***CIC by ABM***\n\n";
//*********************************************************************
 cout<<"\n A set of prime numbers b/n a min and a max numbers:"<<endl;
 cout<<"************************************************************"<<endl;
 cout<<"\n Enter the min and max values "<<endl;
 cout<<"************************************************************"<<endl;
 cout<<"\n Enter the min value:\t\t\t"<<endl<<'\t';
 cin>>min;
 cout<<"\n Enter the max value:\t\t\t"<<endl<<'\t';
 cin>>max;
 cout<<"************************************************************"<<endl;
 cout<<"\n The prime numbers in the range are:"<<endl;
 cout<<endl;
//*********************************************************************
  /********************Range(4000,9000)*******************************/
  
 do
	{
	 for(j=2;j<min;j++)
		{
		 result=min%j;
		 if(result==0)
			break;
		}
		 if(result!=0)
			cout<<min<<",";
		   min++;
	  }while(min<max);
		  cout<<endl;
		  cout<<endl;
  cout<<"*********************+++++++++END OF PROGRAM++++*******************";
        getch();

 }