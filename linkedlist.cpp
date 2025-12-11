#include <iostream>
using namespace std;

struct node
{
    int item;
    node *next;
    node(int value)
    {
        item = value;
        next = NULL;
    }
};

class linkedlist
{
private:
    node *list;

public:
    linkedlist()
    {
        list = NULL;
    }

    void addfirst(int val)
    {
        node *p = new node(val);
        p->next = list;
        list = p;
    }

    void addlast(int val)
    {
        node *p = new node(val);
        if (list == NULL)
        {
            list = p;
        }
        else
        {
            node *q = list;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }

    void addbetween(int pos, int val)
    {
        if (pos == 0)
        {
            addfirst(val);
            return;
        }

        node *p = list;
        int i = 0;

        while (p != NULL && i < pos - 1)
        {
            p = p->next;
            i++;
        }

        if (p == NULL)
        {
            cout << "Position not found\n";
            return;
        }

        node *q = new node(val);
        q->next = p->next;
        p->next = q;
    }

    int deletefirst()
    {
        if (list == NULL)
        {
            cout << "linked list is empty\n";
            return -1;
        }

        node *p = list;
        int data = p->item;
        list = list->next;
        delete p;

        return data;
    }

    int deletelast()
    {
        if (list == NULL)
        {
            cout << "linked list is empty\n";
            return -1;
        }

        if (list->next == NULL)
        {
            int data = list->item;
            delete list;
            list = NULL;
            return data;
        }

        node *p = list;
        while (p->next->next != NULL)
        {
            p = p->next;
        }

        int data = p->next->item;
        delete p->next;
        p->next = NULL;

        return data;
    }

    void display()
    {
        node *p = list;
        while (p != NULL)
        {
            cout << p->item << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    linkedlist l;
    l.addfirst(5);
    l.addlast(2);
    l.addbetween(1, 9); // insert 9 at position 1

    l.display(); // output: 5 9 2

    cout << "Deleted First: " << l.deletefirst() << endl;
    cout << "Deleted Last: " << l.deletelast() << endl;

    l.display();

    return 0;
}
