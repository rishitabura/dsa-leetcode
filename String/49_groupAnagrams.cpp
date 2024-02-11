/*using sorting
time - O(n*k long(k))*/
vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < strs.size(); i++)
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        mp[temp].push_back(strs[i]);
    }

    for (auto ch : mp)
    {
        ans.push_back(ch.second);
    }
    return ans;
}

/*time  O(n*k)
space -O(n*k)*/

string generate(string &s)
{

    string str;
    int count[26] = {0};

    for (char &ch : s)
    {
        count[ch - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            str += string(count[i], i + 'a');
        }
    }
    return str;
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;

    for (string &s : strs)
    {

        string newStr = generate(s);
        mp[newStr].push_back(s);
    }

    for (auto &ch : mp)
    {
        ans.push_back(ch.second);
    }
    return ans;
}
