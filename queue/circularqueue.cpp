#include<bits/stdc++.h>
using namespace std;
#define n 5
class Queue{
    int f;
    int r;
    int *arr;

    public:
    Queue()
    {
        f = r = -1;
        arr = new int[n];
    }

    bool isFull()
    {
        return (r+1)%n == f;
    }
    bool isEmpty()
    {
        return r == -1 && f == -1;
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Full";
            return;
        }
        r = (r+1)%n;
        // first element add
        if (f == -1)
        {
            f = 0;
        }
        
        arr[r] = x;
        
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Empty";
            return -1;
        }
        int result = arr[f];
        // single element
        if (r == f)
        {
            r = f = -1;
        }
        else
        {
            f = (f+1)%n;
        }
        return result;
        
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Empty";
            return -1;
        }
        else
        {
            return arr[f];
        }
        
    }
};


int main()
{
    Queue q;
    // q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    // q.enqueue(6);
    cout << q.dequeue() << endl; 
    q.enqueue(6);

    cout << q.peek() << endl;
    return 0;
}