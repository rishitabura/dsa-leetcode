#include<bits/stdc++.h>
#include<stack>
using namespace std;

string postdfixtoprefix(string s)
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
            res = s[i]+op1+op2;
            st.push(res);
        }
        else
        {
            st.push(string(1,s[i]));
        }
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
    
}

int main()
{
    string str = "AB*CD/+";
    cout << postdfixtoprefix(str);
    return 0;
}