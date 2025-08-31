 # include<iostream>
 using namespace std;
 class stack
 { char arr[100];
    int top;

public:
    stack() 
    { top = -1; }

    bool isEmpty() { return top == -1; }

    bool isFull() {
         return top == 100 - 1; }

    void push(char x) {
        if (!isFull())
            arr[++top] = x;
        else
            cout << "Stack Overflow";
    }

    char pop() {
        if (!isEmpty())
            return arr[top--];
        else
            return '\0'; 
    }

    char peek() {
        if (!isEmpty())
            return arr[top];
        return '\0';
    }
};




 
 int main()
 {
  



 }
