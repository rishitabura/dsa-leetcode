// using recursiontime - (k^n) space - stack space
// DP memoiation time - O(n*k* n) space - O(n*k) + stack space
int MOD = 1e9 + 7;
int solve(int n, int k, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (k == 0)
    {
        return 1;
    }
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    int result = 0;

    for (int inv = 0; inv <= min(k, n - 1); inv++)
    {
        result = (result % MOD + solve(n - 1, k - inv, dp) % MOD) % MOD;
    }

    return dp[n][k] = result;
}
int kInversePairs(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(n, k, dp);
}

// tabulation time - O(n*k) sapce - O(n*k)
int MOD = 1e9 + 7;
int solve(int n, int k, vector<vector<int>> &dp)
{

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int inv = 0; inv <= min(j, i - 1); inv++)
            {
                dp[i][j] = (dp[i][j] % MOD + dp[i - 1][j - inv] % MOD) % MOD;
            }
        }
    }
    return dp[n][k];
}
int kInversePairs(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    return solve(n, k, dp);
}
