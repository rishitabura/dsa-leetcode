class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<int, int>mp;
        string result = "";
        for(int i = 0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        string temp = "";
        for(int i = 0; i<order.size(); i++)
        {
            if(mp.find(order[i]) != mp.end())
            {
                result.append(mp[order[i]] ,order[i]);
                mp.erase(order[i]);
            }
        }
        for(auto it: mp)
        {
            result.append(it.second, it.first);
        }
        return result;

    }
};