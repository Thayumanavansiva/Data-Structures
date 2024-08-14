//Hard 1

#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* top;
    Node()
    {
        top=NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        cout << data << " is pushed" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* curr = top;
        top = top->next;
        cout << curr->data << " is popped" << endl;
        delete curr;
    }
    void print() {
    while (!isEmpty()) {
        cout << top->data << " ";
    }
    cout << endl;
   }
};

void Insert(Node s, int element) {
    if (s.isEmpty() || element > top->data) {
        s.push(element);
    }
    else
        {
            int curr = s.top();
            Insert(s, element);
            s.push(curr);
        }
}
void sortStack(Stack s) {
    if (!s.isEmpty()) {
        int curr = s.top();
        sortStack(s);
        Insert(s, curr);
    }
}
int main() {
    Node s;
    int n, data;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> data;
        s.push(data);
    }

    cout << "Original stack: ";
    print(s);

    sortStack(s);

    cout << "Sorted stack: ";
    print(s);

    return 0;
}
