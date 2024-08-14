#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a[5],i,j,b=0,c=0;
	cout<<"Enter the Elements of Array: ";
	for(i=0;i<5;i++)
	{
	    cin>>a[i];
	}
	for(i=0;i<5;i++)
	{if(a[i]%2==0)
	{
	    b++;
	    }
	else
	{
	    c++;
	    }
	}
	cout<<"The Even Numbers are: "<<b;
	cout<<"The Odd Numbers Are: "<<c;
	getch();
	return 0;
}
