#include<bits/stdc++.h>
#include<stack>
using namespace std;

class MyQueue {
    stack<int> input, output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty())
        {
            int a = output.top();
            output.pop();
            return a;
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int b = output.top();
            output.pop();
            return b;
        }
        
    }
    
    int peek() {
         if(!output.empty())
        {
            return output.top();
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        if(output.size() == 0 && input.size() == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{   
    MyQueue q;
    q.push(2);
    q.push(3);
    cout << q.pop();
    return 0;
}