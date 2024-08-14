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
node *insertmidla(node *head,string x)
{
    node *temp=head;
    node *new_node=new node();
    int a=0;
    while(temp!=NULL)
    {
        a++;
        temp=temp->next;
    }
    temp=head;
    for(int i=1;i<=(a/2);i++)
    {
        if(i==(a/2))
        {
            new_node->data=x;
            new_node->prev=temp;
            new_node->next=temp->next;
            temp->next->prev=new_node;
            temp->next=new_node;

        }
        temp=temp->next;
    }
    return head;
}
int main()
{
    node *head=NULL;
    int i,n;
    string q,h;
    cout<<"Enter The No.of elements: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter The Names: ";
        cin>>q;
          insertda(&head,q);
    }
    cout<<"Enter the Element to be Insert in the Middle: ";
    cin>>h;
    head=insertmidla(head,h);

    node *temp=head;
    while(temp!=NULL)

    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }

    return 0;
    getch();
}

