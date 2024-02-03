#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;

string postdfixToinfix(vector<string> s)
{
    stack<string> st;
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]== "+"|| s[i]== "-" || s[i]== "*" || s[i]== "/" || s[i]== "%" || s[i]=="^")
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
            st.push(s[i]);
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
    // string str = "AB*CD/+";
    vector<string>str = {"4","13","5","/","+"};

    cout << postdfixToinfix(str);
    return 0;
}