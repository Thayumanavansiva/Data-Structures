#include<iostream>
#include<algorithm>
#include<conio.h>
using namespace std;
int main()
{
    int m=0,l=0;
    int a[m][l],b[3],c[9],n,i,j,k=0,x;
    cout<<"Enter The Order of the matrix(m): ";
    cin>>m;
    cout<<"Enter The Order of the matrix(n): ";
    cin>>l;
    cout<<"Enter the Values of array: ";
    for(i=0;i<m;i++){
             for(j=0;j<l;j++){
                    cin>>a[i][j];
    }}
    for(i=0;i<m-1;i++){
            x=0;
        for(j=0;j<l;j++){
                c[k]=a[i][j]+a[i+1][j];
            k++;
            }
        }
     cout<<"The sum Before sorted: ";
    for(i=0;i<k;i++){
            cout<<c[i]<<",";
    }

    sort(c, c + k);
    cout<<"\nThe sum of the numbers after sorted: ";
    for(i=0;i<k;i++){
        cout<<c[i]<<",";
    }
    cout<<"\nEnter The Position of the sum: ";
    cin>>n;
    cout<<"The Number is: "<<c[n-1];
    return 0;
    getch();
}
