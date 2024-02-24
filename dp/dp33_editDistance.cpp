/*recursion memoization
tc - O(m*n)
sc - O(m*n) + O(n)*/

int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        return j + 1;
    }
    if (j < 0)
    {
        return i + 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s1[i] == s2[j])
    {
        return 0 + solve(i - 1, j - 1, s1, s2, dp);
    }

    int ins = 1 + solve(i, j - 1, s1, s2, dp);
    int del = 1 + solve(i - 1, j, s1, s2, dp);
    int rep = 1 + solve(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = min(ins, min(del, rep));
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return solve(n - 1, m - 1, word1, word2, dp);
}

// using shift of index
// int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp)
// {
//     if (i == 0)
//     {
//         return j ;
//     }
//     if (j == 0)
//     {
//         return i ;
//     }

//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }

//     if (s1[i-1] == s2[j-1])
//     {
//         return 0 + solve(i - 1, j - 1, s1, s2, dp);
//     }

//     int ins = 1 + solve(i, j - 1, s1, s2, dp);
//     int del = 1 + solve(i - 1, j, s1, s2, dp);
//     int rep = 1 + solve(i - 1, j - 1, s1, s2, dp);

//     return dp[i][j] = min(ins, min(del, rep));
// }
// int minDistance(string word1, string word2)
// {
//     int n = word1.size();
//     int m = word2.size();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     return solve(n , m , word1, word2, dp);
// }
/*tabulation
tc - O(m*n)
sc- O(m*n)*/
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                }
                else
                {
                    int ins = 1 + dp[i][j - 1];
                    int del = 1 + dp[i - 1][j];
                    int rep = 1 + dp[i - 1][j - 1];

                    dp[i][j] = min(ins, min(del, rep));
                }
            }
        }

        return dp[n][m];
    }
};