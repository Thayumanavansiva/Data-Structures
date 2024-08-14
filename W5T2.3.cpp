#include <iostream>
using namespace std;
#define SIZE 100
class Stack {
public:
    int data[SIZE];
    int maxData[SIZE];
    int top;
    Stack()
    {
        top=-1;
    }

    void push(int value) {
        if (top >= SIZE - 1) {
            cout << "Stack empty" << endl;
            return;
        }
        top++;
        data[top] = value;


        if (top == 0) {
            maxData[top] = value;
        }

        else if(value>maxData[top-1]){

            maxData[top] = value;//max(value, maxData[top - 1]);
        }

        cout << value << " pushed to stack" << endl;
    }

        void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << data[top] << " popped from stack" << endl;
        top--;
    }


    //void peek() {
       // if (isEmpty()) {
            //cout << "Stack is empty." << endl;
           // return;
       // }
        //cout << "Top element is: " << data[top] << endl;
    //}


    void Max() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Maximum element is: " << maxData[top] << endl;
    }

    bool isEmpty() {
        return top == -1;
    }
};
int main() {

    Stack s;
    int choice, value;
    //int n;
    //cout<<"Enter n:";
    //cin>>n;
    //cout<<"Enter the elements:";


    s.push(1);
    s.push(2);
    s.push(4);
    s.push(5);

    s.Max();
    return 0;

}

    /*do {
        cout << "\nStack Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Get Max" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.getMax();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
*/
