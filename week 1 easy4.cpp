#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a[5],i,j,b=0,c;
    cout<<"Enter the Elements of Array: ";
    for(i=0;i<5;i++)
	{cin>>a[i];
	}
	cout<<"Enter element to be Counted: ";
	cin>>c;
	for(i=0;i<5;i++)
	{
		if(a[i]==c)
		{
		b++;
		}
	}

	cout<<endl<<"The Count is : "<<b;
	getch();
	return 0;
}
