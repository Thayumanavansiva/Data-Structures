#include<iostream>
#include<conio.h>
using namespace std;
class emp{
public:
    string name[10];
    int id[10];
    int salary[10];
    int thala=-1;
    void push(string name1,int id1,int salary1)
    {
        if(thala>=10)
            {
                cout<<"stack is full"<<endl;
        }
        else
            {
                thala=thala+1;
                name[thala]=name1;
                id[thala]=id1;
                salary[thala]=salary1;
        }
  }
  void pop()
  {
      if(thala<0){
            cout<<"stack is Empty";
      }
      else{
            string namee=name[thala];
            int idd=id[thala];
            int salaryy=salary[thala];
            cout<<"\nPopped Name: "<<namee<<"  Popped ID: "<<idd<<"  Popped Salary: "<<salaryy<<endl;
    }
}
void peek()
{
    if(thala<0){
        cout<<"Stack is empty";
    }
    else{
       string namees=name[thala];
       int iddd=id[thala];
       int salaryyy=salary[thala];
       cout<<"\nThe Name at The Top: "<<namees<<"   The ID at The Top: "<<iddd<<"   The salary at The Top: "<<salaryyy;
    }
}
};
int main()
{
    emp s;
    string name;
    int id,salary;
    cout<<"Enter The Details of Employee 1: ";
    cin>>name;
    cin>>id;
    cin>>salary;
    s.push(name,id,salary);
    cout<<"Enter The Details of Employee 2: ";
    cin>>name;
    cin>>id;
    cin>>salary;
    s.push(name,id,salary);
    cout<<"Enter The Details of Employee 3: ";
    cin>>name;
    cin>>id;
    cin>>salary;
    s.push(name,id,salary);
    cout<<"\nPeek Elements in the Stack"<<endl;
    s.peek();
    cout<<endl;
    cout<<"\nPopped Data From Stack"<<endl;
    s.pop();

}



