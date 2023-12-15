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
        if (r == n-1)
        {
            cout << "Full";
            return;
        }
        r++;
        arr[r] = x;
        
    }

    // O(n)
    int dequeue()
    {
        if (r == -1)
        {
            cout << "Empty";
            return -1;
        }
        int f = arr[0];
        for (int i = 0; i < r; i++)
        {
            arr[i] = arr[i+1];
        }
        r--;
        return f;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.dequeue() << endl;
    cout << q.dequeue();

    
    return 0;
}