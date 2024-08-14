//EASY 1

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Stack {
public:
    Node* top;
    Stack()
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

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }

};

int main() {
    Stack s;
    int choice, data;

    do {
        cout << "1) Push" << endl;
        cout << "2) Pop" << endl;
        cout << "3) Peek" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element :";
                cin >> data;
                s.push(data);
                cout<<endl;
                break;
            case 2:
                s.pop();
                cout<<endl;
                break;
            case 3:
                s.peek();
                cout<<endl;
                break;
            case 4:
                cout << "Exit" << endl;
                cout<<endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                cout<<endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
