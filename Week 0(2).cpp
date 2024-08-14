#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[15],n,i,sum=0,pro=1;
    cout<<"Enter The No.of.Elements";
    cin>>n;
    cout<<"Enter the Elements of Array: ";
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++) {
        sum+=a[i];
        pro*=a[i];
    }
    cout<<"The Sum is: "<<sum;
    cout<<"The Pro is: "<<pro;
return 0;
getch();
}

