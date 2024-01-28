#include <bits/stdc++.h>
#include <vector>
using namespace std;

void generate(int ind, int sum, vector<int> &nums, vector<int> &ans)
{
    int n = nums.size();

    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }

    generate(ind + 1, sum + nums[ind], nums, ans);

    generate(ind + 1, sum, nums, ans);
}

vector<int> subsetSum(vector<int> &nums)
{
    vector<int> ans;
    generate(0, 0, nums, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, 2};
    vector<int> ans = subsetSum(nums);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}