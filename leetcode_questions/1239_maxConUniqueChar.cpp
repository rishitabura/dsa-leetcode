
bool hasDuplicate(string &s1, string &s2)
{

    vector<int> count(26, 0);
    for (char &ch : s1)
    {

        if (count[ch - 'a'] > 0)
        {
            return true;
        }
        count[ch - 'a']++;
    }

    for (char &ch : s2)
    {

        if (count[ch - 'a'] > 0)
        {
            return true;
        }
    }
    return false;
}

unordered_map<string, int> mp;
int solve(int ind, vector<string> &arr, string temp, int n)
{

    if (ind >= n)
    {
        return temp.length();
    }

    int include = 0;
    int exclude = 0;

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    if (hasDuplicate(arr[ind], temp))
    {
        exclude = solve(ind + 1, arr, temp, n);
    }
    else
    {

        include = solve(ind + 1, arr, temp + arr[ind], n);
        exclude = solve(ind + 1, arr, temp, n);
    }

    return mp[temp] = max(include, exclude);
}

int maxLength(vector<string> &arr)
{
    string temp = "";
    mp.clear();
    int n = arr.size();
    return solve(0, arr, temp, n);
}
