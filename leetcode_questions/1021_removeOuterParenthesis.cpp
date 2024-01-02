class Solution {
public:
    string removeOuterParentheses(string s) {
        string str;
        int n = s.length();
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i] == '(')
            {
                if(count>0)
                {
                    str += s[i];
                }
                count++;
            }
            else 
            {
                if(count>1)
                {
                    str += s[i];
                }
                count--;
            }
        }
        return str;
        
    }
};