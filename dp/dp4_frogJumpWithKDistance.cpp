/*memoiazation
time - O(2^n*k)
space - O(n)*/
int calCost(int ind, int n, int k, vector<int> &height)
{
    if (ind == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = calCost(ind - j, n, k, height) + abs(height[ind] - height[ind - j]);
            ans = min(ans, jump);
        }
    }

    return ans;
}
int minimizeCost(int n, int k, vector<int> &height)
{
    return calCost(n - 1, n, k, height);
}

/*memoization
time - O(n*k)
space - O(n) + O(n)*/
int calCost(int ind, int n, int k, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int ans = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = calCost(ind - j, n, k, height, dp) + abs(height[ind] - height[ind - j]);
            ans = min(ans, jump);
        }
    }

    return dp[ind] = ans;
}
int minimizeCost(int n, int k, vector<int> &height)
{

    vector<int> dp(n + 1, -1);
    return calCost(n - 1, n, k, height, dp);
}

/*tabulation
time - O(n)
space - O(n)*/
int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int ans = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                ans = min(ans, jump);
            }
        }
        dp[i] = ans;
    }
    return dp[n - 1];
}