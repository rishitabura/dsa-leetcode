// O(2^n *(k log(x))
void solve(int ind, vector<int> &nums, set<vector<int>> &res, vector<int> temp)
{
    if (ind == nums.size())
    {

        sort(temp.begin(), temp.end());
        res.insert(temp);
        return;
    }

    temp.push_back(nums[ind]);
    solve(ind + 1, nums, res, temp);
    temp.pop_back();
    solve(ind + 1, nums, res, temp);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> ans;
    solve(0, nums, res, temp);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        ans.push_back(*it);
    }
    return ans;
}