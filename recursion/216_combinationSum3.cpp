
void solve(int ind, int k, int n, vector<vector<int>> &res, vector<int> &temp)
{

    if (k == 0)
    {
        if (n == 0)
        {
            res.push_back(temp);
        }
        return;
    }

    for (int i = ind; i <= 9; i++)
    {
        if (i > n)
        {
            break;
        }

        temp.push_back(i);
        solve(i + 1, k - 1, n - i, res, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> temp;
    solve(1, k, n, res, temp);
    return res;
}
