#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solve(vector<int> &nums, int ind, vector<int> &dp)
{
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int take = nums[ind] + solve(nums, ind - 2, dp);

    int notTake = solve(nums, ind - 1, dp);

    dp[ind] = max(take, notTake);

    return dp[ind];
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    vector<int> dp(nums.size(), -1);
    int ans = solve(nums, nums.size()-1, dp);
    cout << "Answer:" << ans << endl;
    return 0;
}
