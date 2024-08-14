#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a[10],i,j,t=0,b[10];
	for(i=0;i<10;i++)
	{cin>>a[i];
	}
	for(j=0;j<10;j++)
	{
		for(i=j+1;i<10;i++)
		{
		if(a[j]>a[i])
		{
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	}
	for(i=0;i<10;i++)
	{cout<<a[i]<<" ";
	}
	cout<<endl<<a[1]<<endl<<a[8];
	getch();
	return 0;
}
