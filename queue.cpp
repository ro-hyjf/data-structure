#include <iostream>
using namespace std;

class queue {
private:
    int front;
    int rear;
    int size;
    int* items;

public:
    queue() {
        cout << "Enter size\n";
        cin >> size;
        items = new int[size];
        front = rear = -1;
    }

    ~queue() {
        delete[] items;
    }

    bool is_empty() {
        return front == -1;
    }

    bool is_full() {
        return rear == size - 1;
    }

    void enque(int val) {
        if (is_full()) {
            cout << "Queue is overflow\n";
            return;
        }
        if (is_empty()) {
            front = 0;
        }
        items[++rear] = val;
    }

    int deque() {
        if (is_empty()) {
            cout << "Queue is underflow\n";
            return -1;
        }

        int item = items[front];

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }

        return item;
    }

    int start() {
        if (is_empty()) {
            cout << "Queue is underflow\n";
            return -1;
        }
        return items[front];
    }

    void display() {
        if (is_empty()) {
            cout << "Queue is underflow\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    queue q;
    q.enque(5);
    q.enque(6);
    q.enque(7);
    q.enque(8); // overflow 
    q.deque();//5
    q.deque();//6
    q.enque(1);//overflow
    cout << "Start = " << q.start() << endl;//7
    q.display();//7
}
