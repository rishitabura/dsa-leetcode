vector<int> sequentialDigits(int low, int high)
{
    string str = "123456789";
    vector<int> ans;

    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i + 1; j <= str.size(); j++)
        {
            int num = stoi(str.substr(i, j - i));
            if (num <= high && num >= low)
            {
                ans.push_back(num);
            }
        }
    }
    sort(ans.begin(), ans.end());

    return ans;
}
