/*using stack
sc - O(n)
tc - O(n)*/
class Solution {
public:
    string makeGood(string s) {

        stack<char> st;
        int i = 1;
        st.push(s[0]);
        // i++;
        while (i < s.size()) {

            if (!st.empty() && isupper(s[i]) && islower(st.top()) &&
                tolower(s[i]) == tolower(st.top())) {
                st.pop();
                i++;
            } else if (!st.empty() && islower(s[i]) && isupper(st.top()) &&
                       tolower(s[i]) == tolower(st.top())) {
                st.pop();
                i++;
            } else {
                st.push(s[i]);
                i++;
            }
        }
        string ans = "";
        if(st.size() == 0)
        {
            return ans;
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*using constant space*/
class Solution {
public:
    string makeGood(string s) {

        int w = 0;
        for(int r = 0; r<s.size(); ++r)
        {
            if(w>0 && abs(s[r] - s[w-1]) == 32)
            {
                --w;
            }
            else
            {
                s[w++] = s[r]; 
            }
        }

        return s.substr(0,w);
    }
};