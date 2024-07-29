class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i = 0;
        int j = 0;
        int len = 0, ans = 0;
        unordered_map<char, int>mp;
        while(j < s.size())
        {
            if(mp[s[j]] > 0)
            {
                while(s[i] != s[j])
                {
                    mp[s[i]]--;
                    i++;
                }
                mp[s[i]]--;
                i++;
                mp[s[j]]++;
            }
            else
            {
                mp[s[j]]++;
                len = j-i+1;
                ans = max(ans, len);
            }
            j++;
        }
        return ans;
        
    }
};