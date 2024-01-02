class Solution {
public:
    string reverseWords(string s) {

        stack<string> st;
        for(int i = 0; i<s.length(); i++)
        {
            string word="";
            while(s[i] != ' ' && i<s.length())
            {
                word += s[i];
                i++;
            }
            if(word.length() > 0)
            {
                st.push(word);
            }
        }

        string res = "";
        while(!st.empty())
        {
            if(res.length()>0)
            {
                res = res + " " + st.top();
            }
            else
            {
                res = st.top();
            }
            st.pop();
        }
        return res;
    }
};