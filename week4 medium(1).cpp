#include<iostream>
#include<conio.h>
using namespace std;
class Node
{public:
    int d1,d3;
    string d2;
    Node*next;
    Node*prev;
};
void insert1(Node**head,int s,string s1,int a)
{
    Node*new_node=new Node();
    Node*temp=*head;
      if (*head == NULL) {
         Node* new_node = new Node;
        new_node->d1 = s;
        new_node->d2=s1;
        new_node->d3=a;
        new_node->next = new_node->prev = new_node;
        *head = new_node;
        return;
    }
        new_node->d1 = s;
        new_node->d2=s1;
        new_node->d3=a;
    new_node->next = *head;
    new_node->prev = (*head)->prev;
    (*head)->prev->next = new_node;
     (*head)->prev = new_node;
}
void emp(Node* head)
{
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp->d3-=1;
        cout<<"task of"<<temp->d1<<endl;
        temp=temp->next;
        if(temp->d3==0)
        {
            cout<<"\ntask first by employee"<<temp->d1;
            return;
        }
    }

}
int main()
{

    Node*head=NULL;
    int i,n,a,e;
    string s;
    cout<<"enter no of inputs:";
    cin>>n;
    for(i=1;i<=n;i++)
    {cout<<"\nenter employee id:";
    cin>>a;
    cout<<"\nenter employee name:";
    cin>>s;
    cout<<"\nenter no of task :";
    cin>>e;
    insert1(&head,a,s,e);
}
emp(head);
    return 0;
    getch();
}


