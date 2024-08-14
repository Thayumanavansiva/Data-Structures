#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[5],b[5],k=0;
    cout<<"Enter the Elements of array: ";
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    for(int i=0;i<5;i++){
        if(a[i]%3!=0){
            b[k]=a[i];
            k++;
        }
    }
    for(int i=0;i<k;i++){
        cout<<b[i];
    }
    return 0;
    getch();
}
