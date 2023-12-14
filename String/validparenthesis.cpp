#include <bits/stdc++.h>
using namespace std;
#include <stack>

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.size() == 0)
            {
                return false;
            }
            char t = st.top();
            st.pop();
            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '['))
            {
                return false;
            }
            
        }
    }
    if (!st.size())
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

int main()
{
    string str = ")";
    cout << isValid(str);

    return 0;
}