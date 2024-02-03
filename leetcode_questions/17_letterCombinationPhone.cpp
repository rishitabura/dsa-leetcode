void solve(int ind, string digits, vector<string> &ans, string &temp, string mp[])
{
    if (ind >= digits.size())
    {
        ans.push_back(temp);
        return;
    }

    int dig = digits[ind] - '0';
    string letter = mp[dig];

    for (int i = 0; i < letter.size(); i++)
    {
        temp.push_back(letter[i]);
        solve(ind + 1, digits, ans, temp, mp);
        temp.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string temp = "";
    if (digits.size() == 0)
    {
        return ans;
    }
    string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(0, digits, ans, temp, mp);
    return ans;
}
