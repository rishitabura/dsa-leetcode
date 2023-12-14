#include<bits/stdc++.h>
#include<stack>
using namespace std;

void reverseString(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        string words = "";
        while (s[i]!=' ' && i<s.length())
        {
            words+= s[i];
            i++;
        }
        st.push(words);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
    
}

int main()
{
    string str = "Hello! How are you?";
    reverseString(str);
    return 0;
}