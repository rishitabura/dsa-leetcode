class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        int n = s.length();
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string str = "";
                while(!st.empty() && st.top() != '[')
                {
                    str.push_back(st.top());
                    st.pop();
                }
                // pop [
                st.pop();
                string numC = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9')
                {
                    numC.push_back(st.top());
                    st.pop();
                }
                reverse(numC.begin(), numC.end());
                int number = stoi(numC);
                
                string temp = "";
                for(int j = 0;j<number ; j++)
                {
                    temp += str;
                }
                reverse(temp.begin(), temp.end());

                for(int j =0 ; j< temp.size(); j++)
                {
                    st.push(temp[j]);
                }
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop(); 
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};