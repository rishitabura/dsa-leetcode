/*using rec + memo
time - O(n*sqrt(n))*/
int solve(int n, vector<int> &dp)
{
    int minCount = INT_MAX;

    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    for (int i = 1; i * i <= n; i++)
    {
        int result = 1 + solve(n - i * i, dp);
        minCount = min(result, minCount);
    }
    return dp[n] = minCount;
}
int numSquares(int n)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, dp);
    return ans;
}

/*tabulation
time - O(n*sqrt(n))*/
int numSquares(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            int result = 1 + dp[i - j * j];
            dp[i] = min(result, dp[i]);
        }
    }
    return dp[n];
}
