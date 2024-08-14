#include <iostream>
using namespace std;
// Define a constant for the maximum stack size
const int MAX_SIZE = 100;

// Define a Stack class
class Stack {
private:
    int arr[MAX_SIZE]; // Array to store stack elements
    int top; // Index of the top element

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;
    }

    // Method to push an element onto the stack
    void push(int value) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = value;
        } else {
            cout << "Stack overflow! Cannot push element." <<endl;
        }
    }

    // Method to pop an element from the stack
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack underflow! Cannot pop element." << endl;
        }
    }

    // Method to peek at the top element
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1; // Return a sentinel value
        }
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Function to compare two stacks
bool compareStacks(Stack& s1, Stack& s2) {
    if (s1.isEmpty() && s2.isEmpty()) return true;

    if (s1.isEmpty() || s2.isEmpty()) return false;

    Stack temp1, temp2;

    while (!s1.isEmpty()) {
        temp1.push(s1.peek());
        s1.pop();
    }

    while (!s2.isEmpty()) {
        temp2.push(s2.peek());
        s2.pop();
    }

    while (!temp1.isEmpty() && !temp2.isEmpty()) {
        if (temp1.peek() != temp2.peek()) return false;
        temp1.pop();
        temp2.pop();
    }

    return temp1.isEmpty() && temp2.isEmpty();
}

int main() {
    Stack s1;
    Stack s2;

    // Push elements onto s1
    s1.push(1);
    s1.push(2);
    s1.push(3);

    // Push elements onto s2
    s2.push(1);
    s2.push(2);
    s2.push(3);

    // Compare stacks
    if (compareStacks(s1, s2)) {
        cout << "Stacks are identical." << endl;
    } else {
        cout << "Stacks are not identical." << endl;
    }

    return 0;
}

