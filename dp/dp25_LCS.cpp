/*recursion
tc - O(2^n 2^m)*/

int solve(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (s1[i] == s2[j])
    {
        return 1 + solve(i - 1, j - 1, s1, s2);
    }

    return 0 + max(solve(i - 1, j, s1, s2), solve(i, j - 1, s1, s2));
}
int longestCommonSubsequence(string text1, string text2)
{
    int i = text1.size();
    int j = text2.size();

    return solve(i - 1, j - 1, text1, text2);
}

/*memoizaion
tc - O(m*n)
sc - O(m*n) + O(m+n)*/

int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
    }

    return dp[i][j] = max(solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp));
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, text1, text2, dp);
}

/*with right shift indexes*/
int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i - 1] == s2[j - 1])
    {
        return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
    }

    return dp[i][j] = max(solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp));
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n, m, text1, text2, dp);
}

/*tabulation
tc - O(n*m)
sc - O(n*m)*/
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][m];
}