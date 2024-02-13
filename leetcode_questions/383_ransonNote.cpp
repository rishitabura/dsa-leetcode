class Solution {
public:
    unordered_map<char,int> mp;
    bool canConstruct(string ransomNote, string magazine) {
        
        int n = magazine.size();
        for(auto ch : ransomNote)
        {
            mp[ch]++;
        }
        for(int i = 0; i< n ; i++)
        {
            if(mp.find(magazine[i]) != mp.end())
            {
                mp[magazine[i]]--;
            }
        }
        for(auto it: mp)
        {
            if(it.second > 0)
            {
                return false;
            }
        }
        return true;
        
    }
};