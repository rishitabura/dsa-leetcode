/*memoization
time - O(n)
space - O(n)+O(n)*/
#include <bits/stdc++.h>
int solve(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
    {
        return nums[ind];
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int pick = nums[ind] + solve(ind - 2, nums, dp);
    int notpick = 0 + solve(ind - 1, nums, dp);

    return dp[ind] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{

    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solve(n - 1, nums, dp);
}

/*tabulation
time - O(n)*/
int maximumNonAdjacentSum(vector<int> &nums)
{

    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notpick = 0 + dp[i - 1];
        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
    ;
}