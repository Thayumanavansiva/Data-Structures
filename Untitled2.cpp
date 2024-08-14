#include <iostream>
#include <stack>
using namespace std;
void sortedInsert(stack<int>& s, int element) {
    if (s.empty() || element > s.top()) {
        s.push(element);
    }
    else
        {
            int temp = s.top();
            s.pop();
            sortedInsert(s, element);
            s.push(temp);
        }
}

void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, temp);
    }
}
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        s.push(value);
    }

    cout << "Original stack: ";
    printStack(s);

    sortStack(s);

    cout << "Sorted stack: ";
    printStack(s);

    return 0;
}
