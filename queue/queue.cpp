#include<bits/stdc++.h>
using namespace std;
#define n 100

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

    void enqueue(int x)
    {
        if (r == n)
        {
            cout << "Full";
            return;
        }
        r++;
        arr[r] = x;
        
    }

    int dequeue()
    {
        if (f == r)
        {
            cout << "Empty";
            return -1;
        }
        f++;
        return arr[f];
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.dequeue();
    cout << q.dequeue();

    
    return 0;
}