/*recursion
time - O(2^m*n)
space - O(n) stack space*/
int solve(int i, int j)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }

    int up = solve(i - 1, j);
    int down = solve(i, j - 1);

    return up + down;
}
int uniquePaths(int m, int n)
{
    int ans = solve(m - 1, n - 1);
    return ans;
}

/*memoization
time - O(n*m)
space - O(n*m)*/
int solve(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = solve(i - 1, j, dp);
    int down = solve(i, j - 1, dp);

    return dp[i][j] = up + down;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int ans = solve(m - 1, n - 1, dp);
    return ans;
}