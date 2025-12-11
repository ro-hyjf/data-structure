#include <iostream>
#include <string>
#include <cmath>
#include <cctype> 
using namespace std;

template<class T>
class Stack {
    int size;
    int top;
    T* arr;
public:
    Stack(int x = 100) : size(x), top(-1) {
        arr = new T[size];
    }
    ~Stack() {
        delete[] arr;
    }

    bool is_empty() const {
        return top == -1;
    }
    bool is_full() const {
        return top == size - 1;
    }

    void push(T x) {
        if (is_full()) {
            cout << "stack overflow\n";
            return;
        }
        top++;
        arr[top] = x;
    }

    T pop() {
        if (is_empty()) {
            cout << "stack underflow\n";
            return T();
        }
        T x = arr[top];
        top--;
        return x;
    }

    void print() const {
        if (is_empty()) {
            cout << "(stack is empty)\n";
            return;
        }
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    T peek() const {
        if (top == -1) {
            cout << "stack is empty\n";
            return T();
        }
        return arr[top];
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/' || op == '%') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}

string inf_to_postf(string inf) {
    string postfix = "";

    inf = "(" + inf + ")";

    Stack<char> st((int)inf.size());
    for (size_t i = 0; i < inf.size(); ++i) {
        char c = inf[i];
        if (isalnum(static_cast<unsigned char>(c))) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.is_empty() && st.peek() != '(') {
                postfix += st.pop();
            }
            if (!st.is_empty()) st.pop();
        }
        else {
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') {
                if (c == '^') {

                    while (!st.is_empty() && precedence(st.peek()) > precedence(c)) {
                        postfix += st.pop();
                    }
                }
                else {
                    while (!st.is_empty() && precedence(st.peek()) >= precedence(c)) {
                        postfix += st.pop();
                    }
                }
                st.push(c);
            }

        }
    }

    return postfix;
}

int postf_ev(const string& postf) {
    Stack<int> st((int)postf.size());
    for (size_t i = 0; i < postf.size(); ++i) {
        char c = postf[i];
        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        }
        else {
            int operand2 = st.pop();
            int operand1 = st.pop();
            int result = 0;
            switch (c) {
            case '^':
                result = (int)pow(operand1, operand2);
                break;
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0) {
                    cout << "Division by zero in postfix evaluation\n";
                    result = 0;
                }
                else result = operand1 / operand2;
                break;
            default:
                cout << "Unsupported operator: " << c << endl;
                break;
            }
            st.push(result);
        }
    }
    return st.pop();
}

int main() {
    string infix;
    cout << "Enter infix : ";
    cin >> infix;

    string postfix = inf_to_postf(infix);
    cout << "The postfix is: " << postfix << endl;

    cout << "Postfix Evaluation = " << postf_ev(postfix) << endl;
    return 0;
}
