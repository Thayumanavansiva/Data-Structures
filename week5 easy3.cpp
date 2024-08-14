#include <iostream>
#include <string>
using namespace std;

class revstack
{
public:
    char arr[20];
    int top = -1;
    int size;
    revstack(int size1)
    {
        size = size1;
    }
    void push(char str)
    {
        if (top >= size - 1)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top = top + 1;
            arr[top] = str;
        }
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            char popped = arr[top--];
            return popped;
        }
    }
};

int main()
{
    revstack rs(20);
    string str;
    cout << "Enter a string: ";
    cin >> str;

    // Push each character onto the stack
    for (int i = 0; i < str.length(); i++)
    {
        rs.push(str[i]);
    }

    // Pop characters from the stack to construct the reversed string
    string reversed_str;
    while (rs.top >= 0)
    {
        reversed_str += rs.pop();
    }

    cout << "Reversed string: " << reversed_str << endl;
    return 0;
}
