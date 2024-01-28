
void findComb(int ind, vector<int> &candidates, int target,
              vector<vector<int>> &ans, vector<int> &temp)
{

    int n = candidates.size();
    if (ind >= n)
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }

    if (candidates[ind] <= target)
    {
        temp.push_back(candidates[ind]);
        findComb(ind, candidates, target - candidates[ind], ans, temp);
        temp.pop_back();
    }
    findComb(ind + 1, candidates, target, ans, temp);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    findComb(0, candidates, target, ans, temp);
    return ans;
}
