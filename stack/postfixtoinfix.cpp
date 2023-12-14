#include<bits/stdc++.h>
#include<stack>
using namespace std;

string postdfixToinfix(string s)
{
    stack<string> st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]== '/' || s[i]=='%' || s[i]=='^')
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            res = '(' + op2 + s[i] + op1 + ')';
            st.push(res);
        }
        else
        {
            st.push(string(1,s[i]));
        }
    }
    // string ans = "";
    // while (!st.empty()) {
    //     ans += st.top();
    //     st.pop();
    // }
    return res;
    
}

int main()
{
    string str = "AB*CD/+";
    cout << postdfixToinfix(str);
    return 0;
}