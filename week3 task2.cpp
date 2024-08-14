#include<iostream>
#include<conio.h>
using namespace std;
class node
{
public:
    string data;
    node *next;
    node *prev;
};
void insertda(node **head,string x)
{
     node *new_node=new node();
     node *temp=*head;
     if(*head==NULL){
        new_node->data=x;
        *head=new_node;
        return;

     }
     while(temp->next!=NULL){
            temp=temp->next;
     }
        new_node->prev=temp;
        new_node->data=x;
        temp->next=new_node;

}
node *deleter(node *head)
{
    node *curr=head;
    node *temp=new node();
    while(temp!=NULL)
    {
        string x=temp->data;
        if(x[0]=='r')

        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
    temp=temp->next;
    }
    return head;
}
int main()
{
    node *head=NULL;
    int i,n;
    string q;
    cout<<"Enter The No.of elements: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter The Names: ";
        cin>>q;
          insertda(&head,q);
    }
    node *temp=head;

    head=deleter(head);

    while(temp!=NULL)

    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }



    return 0;
    getch();
}
