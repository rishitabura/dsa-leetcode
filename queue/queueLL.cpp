#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{

    node *f;
    node *r;

public:
    Queue()
    {
        f = r = nullptr;
    }

    void enqueue(int x)
    {
        node *newNode = new node(x);

        if (newNode == nullptr)
        {
            cout << "Full";
            return;
        }
        else
        {
            if (f == nullptr && r == nullptr)
            {
                f = r = newNode;
            }
            else
            {
                r->next = newNode;
                r = newNode;
                newNode->next = nullptr;
            }
        }
    }

    void dequeue()
    {
        if (f == nullptr)
        {
            cout << "Empty";
            return;
        }
        else
        {
            node *temp = f;
            int a = f->data;
            f = f->next;
            delete temp;
            cout << a << endl;;
        }
    }

    void display()
    {
        if (f == nullptr)
        {
            cout << "Empty";
            return;
        }
        else
        {
            node *temp = f;
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    // q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.display();
    q.dequeue();
    q.dequeue();

    return 0;
}