class Solution
{
public:
    int solve(vector<int> &nums, int i, int j, vector<int> &dp)
    {

        int n = nums.size();
        if (i > j)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int pick = nums[i] + solve(nums, i + 2, j, dp);
        int notpick = 0 + solve(nums, i + 1, j, dp);

        int ans = max(pick, notpick);

        return dp[i] = ans;
    }
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n, -1);

        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }

        int ans1 = solve(nums, 0, n - 2, dp);

        vector<int> dp1(n, -1);
        int ans2 = solve(nums, 1, n - 1, dp1);

        return max(ans1, ans2);
    }
};