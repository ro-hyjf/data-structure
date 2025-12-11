#include <iostream>
#include<string>
using namespace std;

template <class T>
class Stack {
private:
    int top;
    int size;
    T* items;

public:
    Stack(int s)
    {
        size = s;
        top = -1;
        items = new T[size];
    }
    ~Stack()
    {
        delete[] items;
    }

    bool is_full()
    {
        return top == size - 1;
    }
    bool is_empty()
    {
        return top == -1;
    }
    void push(T val)
    {
        if (is_full()) {
            cout << "Stack is OVERFLOW!\n";
        }
        else {
            items[++top] = val;
            
        }
    }
    T pop()
    {
        if (is_empty()) {
            cout << "Stack is UNDERFLOW\n";
            return -1;  
        }
        else {
            T item = items[top];
            top--;
            return item;
        }
    }
    T peek()
    {
        if (is_empty()) {
            cout << "Stack is UNDERFLOW\n";
            return -1;
        }
        return items[top];
    }
    void display()
    {
       
        if (is_empty()) {
            cout << "Stack is UNDERFLOW\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};
static bool is_Balance(string s)
{
    Stack<char> st(s.length());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (st.is_empty())
                return false;

            char top = st.pop();

            if ((s[i] == ')' && top != '(') ||
                (s[i] == '}' && top != '{') ||
                (s[i] == ']' && top != '['))
                return false;
        }
    }

    return st.is_empty();
}

int main() {
    string s;
    cout << "Enter a string () or{} or[] \n";
    cin >> s;
    if (is_Balance(s))
    {
        cout << "Expresion is BALANCE\n";
    }
    else
    {
        cout << "Expresion is NOTBALANCE\n";
    }
    return 0;
}
