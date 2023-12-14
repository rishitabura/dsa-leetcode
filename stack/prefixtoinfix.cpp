#include<bits/stdc++.h>
#include<stack>
using namespace std;

string prefixToinfix(string s)
{
    stack<string> st;
    string res;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]== '/' || s[i]=='%' || s[i]=='^')
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            res = '(' + op1 + s[i] + op2 + ')';
            st.push(res);
        }
        else
        {
            st.push(string(1,s[i]));
        }
    }
    return st.top();
    
}

int main()
{
    string str = "+*AB/CD";
    cout << prefixToinfix(str);
    return 0;
}