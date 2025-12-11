// circular queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class circularqueue {
private:
    int front;
    int rear;
    int size;
    int* items;

public:
    circularqueue() {
        cout << "Enter size\n";
        cin >> size;
        items = new int[size];
        front = rear = -1;
    }

    ~circularqueue() {
        delete[] items;
    }

    bool is_empty() {
        return front == -1;
    }

    bool is_full() {
        return( (front==0&&rear == size - 1)||(front==rear+1));
    }

    void enque(int val) {
        if (is_full()) {
            cout << "Queue is overflow\n";
            return;
        }
        if (is_empty()) {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
            items[rear] = val;
        }
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
            front=(front+1)%size;
        }

        return item;
    }

    void display() {
        if (is_empty()) {
            cout << "Queue is underflow\n";
            return;
        }
        cout << "Queue elements: ";
        if (front < rear)
        {
            for (int i = front; i <= rear; i++) {
                cout << items[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << items[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << items[i] << " ";
            }

        }
        cout << endl;
    }
};


int main() {
    circularqueue q;
    q.enque(5);
    q.enque(6);
    q.enque(7);
    q.enque(8); // overflow 
    q.deque();//5
    q.deque();//6
    q.enque(1);
    q.display();//7 1
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
