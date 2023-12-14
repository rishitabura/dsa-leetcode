#include<bits/stdc++.h>
#include<stack>
using namespace std;

class minStack{

    stack<pair<int , int>> st;
public:
   
    minStack(){ };

    void push(int val)
    {
        if (st.size() == 0)
        {
            st.push({val, val});
        }
        else
        {
            int mini = min(val ,st.top().second);
            st.push({val, mini});
        }
    }

     int getMin() {
        return(st.top().second);
    }

    void display()
    {
        while (!st.empty())
        {
            cout << st.top().first << " " << st.top().second;
            cout << endl;
            st.pop();
        }
        
    }
};

// class MinStack {
//     int topm;
//     stack<pair<int,int>> st;
// public:
//     MinStack() {
           
//     }

//     void push(int val) {
//         if(st.empty())
//         {
//             st.push({val,val});
//         }
//         else
//         {
//             int mini = min(val, st.top().second);
//             st.push({val, mini});
//         }   
//     }
    
//     void pop() {
//         if(!st.empty())
//         {
//             st.pop();
//         }
        
//     }
    
//     int top() {
//         return st.top().first;
        
//     }
    
//     int getMin() {
//         return(st.top().second);
//     }
// };

int main()
{
    minStack s;

    s.push(5);
    s.push(2);
    s.push(3);
    s.push(0);
    
    cout << "min " << s.getMin() << endl;
    s.display();
    
    return 0;
}