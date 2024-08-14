#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};
Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        newNode->next = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    return newNode;
}
Node* deleteNode(Node* head, int key) {
    if (head == NULL)
        return NULL;
    Node* curr = head;
    Node* prev = NULL;
    do {
        if (curr->data == key) {
            if (prev == NULL) {
                Node* last = head;
                while (last->next != head)
                    last = last->next;
                if (head == head->next) {
                    delete head;
                    return NULL;
                }
                last->next = head->next;
                delete head;
                return last->next;
            }
            prev->next = curr->next;
            delete curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    cout << "Key not found in the list" << endl;
    return head;
}


void printReverse(Node* head) {
    if (head == NULL)
        return;

    Node* prev = NULL;
    Node* current = head;
    Node* next;


    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);


    head = prev;

    cout << "Reversed Circular Linked List: ";
    do {
        cout << head->data << " ";
        head = head->next;
    } while (head != prev);
    cout << endl;
}
int main() {
    Node* head = NULL;
    int key;
    cout<<"Enter key:";
    cin>>key;
    head = insert(head, 10);
    head = insert(head, 8);
    head = insert(head, 7);
    head = insert(head, 5);
    head = insert(head, 2);
    cout << "Deleting node with key = " << key << endl;
    head = deleteNode(head, key);
    printReverse(head);

    return 0;
}
