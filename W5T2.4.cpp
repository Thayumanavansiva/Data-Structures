#include <iostream>
using namespace std;
#define SIZE 100
class Stack {
public:
    int elem[SIZE];
    int maxData[SIZE];
    int top;
    Stack()
    {
        top=-1;
    }

    void push(int data) {
        if (top >= SIZE - 1) {
            cout << "Stack full" << endl;
            return;
        }
        top++;
        elem[top] = data;

        // Manage the max stack
        if (top == 0)
        {
            maxData[top] = data;
        }
        else
        {
        if(data>maxData[top-1])
        {
            maxData[top] = data;//max(data, maxData[top - 1]);
        }

        cout << data << " pushed to stack" << endl;
    }

    void pop()
    {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << elem[top] << " popped from stack" << endl;
        top--;
    }

    void peek()
    {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element is: " << elem[top] << endl;
    }

    void Max()
     {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Maximum element: " << maxData[top] << endl;
    }


    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack s;
    //int n;
    //cout<<"Enter n:";
    //cin>>n;
    //cout<<"Enter the elements:";

    int choice, data;
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(5);

    s.Max();
    return 0;
 }
