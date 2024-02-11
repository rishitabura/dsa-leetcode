class Solution
{
public:
    int solve(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp)
    {
        int n = coins.size();

        if (amount == 0)
        {
            return 0;
        }
        if (ind == 0)
        {
            if (amount % coins[0] == 0)
            {
                return amount / coins[0];
            }
            else
            {
                return 1e9;
            }
        }
        if (dp[ind][amount] != -1)
        {
            return dp[ind][amount];
        }

        int notTake = 0 + solve(coins, ind - 1, amount, dp);
        int take = INT_MAX;
        if (coins[ind] <= amount)
        {
            take = 1 + solve(coins, ind, amount - coins[ind], dp);
        }
        return dp[ind][amount] = min(take, notTake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(coins, n - 1, amount, dp);
        if (ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
};