//Maximum Length Substring With Two Occurrences

class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n = s.size();
        int i = 0;
     
        unordered_map<char, int>mp;
        int maxLen = 0;
        for(int j = 0; j<n; ++j)
        {
            mp[s[j]]++;
            
            while(mp[s[j]] > 2)
            {
                mp[s[i]]--;
                i++;
            }
            
            maxLen = max(maxLen, j-i+1);
            
            
        }
        
        return maxLen;
        
        
    }
};