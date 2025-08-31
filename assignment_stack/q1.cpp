#include <iostream>
using namespace std;

#define MAX 5   

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() {
         top = -1; }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = x;
        cout << x ;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. IsEmpty\n6. IsFull\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
            break;
        case 2: s.pop(); break;
        case 3: s.peek(); break;
        case 4: s.display(); break;
        case 5: cout << (s.isEmpty() ? "Yes, stack is empty\n" : "No, stack is not empty\n"); break;
        case 6: cout << (s.isFull() ? "Yes, stack is full\n" : "No, stack is not full\n"); break;
        case 7: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
