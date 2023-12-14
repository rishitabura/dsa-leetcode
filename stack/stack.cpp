#include<bits/stdc++.h>
using namespace std;

#define n 100

class Stack{
 
    int top;
    int arr[n];

    public:
    Stack()
    {
        // arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if(top == n-1)
        {
            cout << "Stack overflow";
            return;
        }
        top++;
        arr[top] = x;
    }
    int pop()
    {
        if(top == -1)
        {
            cout << "Stack empty";
            return -1;
        }
        int ans = arr[top];
        top--;
        return ans;
    }

    int Top()
    {
        if(top == -1)
        {
            cout << "Stack empty";
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        if(top == -1)
        {
            return true;
        }
        return false;
    }

    bool full()
    {
        if(top == n-1)
        {
            return true;
        }
        return false;
    }
};



int main()
{
    Stack st ;
    st.push(1);
    // st.push(2);
    // st.push(3);
    cout << st.Top() << endl;
    cout << st.pop()<< endl;
    cout << st.Top() << endl;
    cout << st.empty();

    return 0;
}