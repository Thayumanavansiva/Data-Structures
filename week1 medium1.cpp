#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a[5],i,j,t=0,b[5];
	cout<<"Enter the Elements of Array: ";
	for(i=0;i<5;i++)
	{
	    cin>>a[i];
	}
	for(j=0;j<5;j++)
	{
		for(i=j+1;i<5;i++)
		{
		if(a[j]>a[i])
		{
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	}
	for(i=0;i<5;i++)
	{
	cout<<a[i]<<" ";
	}
	cout<<"\nThe Second minimum is: "<<a[1]<<endl;
	cout<<"The Second maximum is: "<<a[3];
	getch();
	return 0;
}
