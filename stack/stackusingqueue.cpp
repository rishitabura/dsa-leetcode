#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    MyStack()
    {}

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (q.empty())
        {
            return -1;
        }
        int a = q.front();
        q.pop();
        return a;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        if (q.size() == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.pop();
    return 0;
}