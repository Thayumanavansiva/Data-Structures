#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a[5],b[5],i,j,k=0;
	cout<<"Enter the Elements of Array: ";
	for(i=0;i<5;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<k;j++)
		{
			if(a[i]==b[j])
			{
				break;
			}
		}
		if(j==k)
		{b[k]=a[i];
		k++;
		}
	}
	cout<<"After Removing The Duplicates: ";
	for(i=0;i<k;i++)
	{
	    cout<<b[i];
	}
	getch();
	return 0;
}
