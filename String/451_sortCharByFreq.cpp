class Solution
{
public:
    static bool cmp(pair<char, int> &p1, pair<char, int> &p2)
    {
        return (p1.second > p2.second);
    }

    string frequencySort(string s)
    {

        unordered_map<char, int> freq;
        for (auto it : s)
        {
            freq[it]++;
        }

        vector<pair<char, int>> mp;
        for (auto it : freq)
        {
            mp.push_back(make_pair(it.first, it.second));
        }
        sort(mp.begin(), mp.end(), cmp);

        string ans = "";
        for (auto it : mp)
        {
            // string temp += string(it.second,it.first);
            ans += string(it.second, it.first);
        }
        return ans;
    }
};