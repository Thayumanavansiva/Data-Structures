#include<iostream>
#include<conio.h>
using namespace std;
class Node
{public:
    string data;
    Node*next;
    Node*prev;
};
void insert1(Node**head,string s)
{
    Node*new_node=new Node();
    Node*temp=*head;
    if(*head==NULL)
    {

    new_node->prev=NULL;
        new_node->data=s;
       * head=new_node;
        return;
    }
    while(temp->next!=NULL)
    {

        temp=temp->next;
    }
    new_node->prev=temp;
    new_node->data=s;
    temp->next=new_node;


}
Node*sorted(Node*head)
{Node*temp=head;
Node*curr=new Node();
while(temp!=NULL)
{string a=temp->data;
    if(a[0]=='r')
    {//curr=temp;

       //cout<<temp->data;

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
      //delete curr;
        }
temp=temp->next;

}
return head;

}
int main()
{
    Node*head=NULL;
    int i,n;
    string a;
    cout<<"enter no of inputs:";
    cin>>n;
    for(i=0;i<n;i++)
    {cout<<"\nenter element no "<<i+1<<":";
    cin>>a;

        insert1(&head,a);

    }

    head=sorted(head);

    Node*temp=head;
  while(temp!=NULL)
    {
        cout<<temp->data<<endl;
       temp=temp->next;
    }
}


