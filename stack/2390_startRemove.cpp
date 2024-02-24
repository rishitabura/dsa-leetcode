class Solution {
public:
stack<char> st;
    string removeStars(string s) {

        int n = s.size();
        int l = 0;
        int i = 0;
        while(i < n)
        {
            if(s[i] == '*')
            {
                st.pop();
                l--;
            }
            else
            {
                st.push(s[i]);
                l++;
            }
            i++;
        }
        string ans = "";
        for(int i = 0; i<l; i++)
	    {
		    ans += '$';
	    }
        while(!st.empty() && l > 0)
        {
            ans[l-1] = st.top();
            st.pop(); 
            l--;
        }

        return ans;


        
    }
};