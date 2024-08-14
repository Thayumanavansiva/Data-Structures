#include<iostream>
#include<conio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,b=0,n,n1,a[i],x=0,max1=0;
    cout<<"Enter the Elements of Array: ";
	for(i=0;i<5;i++)
	{
	    cin>>a[i];
	}
    int c[10]={0};
    for(int i=1;i<n;i++){
        for(int i=i-1;i<n-1;i++){
            if(a[i]-1==a[i-1]){
                b++;
            }
            else if(a[i]-1!=a[i-1]){
                c[j]=b;b=0;
                j++;
            }
        }
        x=*max_element(c,c+10);
        for(int i=0;i<n1;i++){
            if(c[i]>x){
                max1=c[i];
            }
        }
        cout<<x+1;
    }

}
