class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int res;
        if(s.size() == 0) return 0;

        stack<char> st;
        for(char c: s){
            if(c == '(')
            {
                st.push(c);
                count++;
                res = max(res, count);
            }
            else if(c == ')')
            {
                st.pop();
                count--;
                res = max(count, res);
            }
        }

        return res;        
    }
};