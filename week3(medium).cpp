#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
class Node{
    public:
    string data;
    Node *next=NULL;
};

Node *rearrange(Node *head){
    Node *prev=NULL;
    Node *curr=head,*Next=NULL;
    while(curr!=NULL){
        Next=curr->next;

        curr->next=prev;

        prev=curr;

        curr=Next;
    }
    head=prev;

    while(prev!=NULL){
        string s1=prev->data;
        reverse(s1.begin(),s1.end());
        prev->data=s1;
        prev=prev->next;
    }



   return head;
}

int main(){
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();

    head->data="Pradeep";
    head->next=second;

    second->next=third;
    second->data="Pistol";

    third->data="Perumal";

    Node *result=rearrange(head);

    while(result!=NULL){
        cout<<result->data<<" ";
        result=result->next;
    }


}

