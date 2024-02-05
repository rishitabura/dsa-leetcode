/*using unordered map
time - O(n) avg
spcae - O(n)*/
int firstUniqChar(string s)
{
    unordered_map<char, int> mp;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

/*using freq array
time - O(n)
space - O(n)*/
int firstUniqChar(string s)
{
    vector<int> freq(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (freq[ch - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}