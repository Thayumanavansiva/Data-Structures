#include<iostream>
#include<conio.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
};
node* rearrange(node *head)
{
    node *prev=head;
    node *curr=next;
    while(curr!=Null && curr->next!=Null){
        if(prev->data!=curr->next->data){
            prev=prev->next;
            curr=curr->next;
        }
        else{
            curr->next=curr->next->next;
        }
        return head;
    }
}
int main()
{
    node *head=new node();
    node *second=new node();
    node *third=new node();

    head->data=3;
    head->next=second;

    second->data=3;
    second->next=third;

    third->data=1;
    third->next=Null;

    rearrange(head);
    getch ();
    return 0;
}
