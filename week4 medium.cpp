#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;
};

void sumofnodes(node* head)
{
    node* temp=head;
    int sum=0;
    if(head!=NULL)
    {
        do{
            sum=sum+temp->data;
            temp=temp->next;
        }while(temp!=head);
    }
    temp=head;
    do{
        int currentsum=sum-temp->data;
        temp=temp->next;
        cout<<currentsum<<"->";
    }while(temp!=head);
    cout<<"end";
}
int main()
{
    int d1,d2,d3,d4,d5;
    node* head=NULL;
    node* second=NULL;
    node* third=NULL;
    node* four=NULL;
    node* five=NULL;

    cout<<"Enter data for 1st node:";
    cin>>d1;
    cout<<"Enter data for 2nd node:";
    cin>>d2;
    cout<<"Enter data for 3rd node:";
    cin>>d3;
    cout<<"Enter data for 4th node:";
    cin>>d4;
    cout<<"Enter data for 5th node:";
    cin>>d5;
    head=new node();
    second=new node();
    third=new node();
    four=new node();
    five=new node();

    head->prev=five;
    head->data=d1;
    head->next=second;
    second->prev=head;
    second->data=d2;
    second->next=third;
    third->prev=second;
    third->data=d3;
    third->next=four;
    four->prev=third;
    four->data=d4;
    four->next=five;
    five->prev=four;
    five->data=d5;
    five->next=head;
    sumofnodes(head);
}
