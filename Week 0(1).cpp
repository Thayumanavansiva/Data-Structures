#include<iostream>
#include<conio.h>
using namespace std;
int main(){
int arr[5],i,n=0,b=0;
cout<<"Enter The Elements of arrray: ";
for(i=1;i<6;i++){
    cin>>arr[i];
}
for(i=1;i<6;i++){
    if(arr[i]>n){
        n=arr[i];
    }
}
for(i=1;i<6;i++){
    if(arr[i]<b){
        b=arr[i];
    }
}
cout<<"The Max is: "<<n;
cout<<"The Min is: "<<b;
return 0;
getch();
}
