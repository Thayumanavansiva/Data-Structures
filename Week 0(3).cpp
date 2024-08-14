#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
   int i,b=0,a[10];
   cout<<"Enter The Elements of Array:";
   for(i=0;i<7;i++){
   cin>>a[i];
   }
   cout<<"Enter The inserting element: ";
   cin>>b;
   for(i=7;i>2;i--){
    a[i]=a[i-1];
   }
   a[2]=b;
   for(i=4;i<8;i++){
    a[i]=a[i+1];
    }
    for(i=0;i<6;i++){
        cout<<a[i]<<endl;

    }
    getch();
    return 0;
}
