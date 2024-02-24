/*recursion
tc - O(exp)
sc - O(n+m)*/
bool isAllStars(string &s1, int i) {
    for (int j = 0; j <= i; j++) {
        if (s1[j] != '*')
            return false;
    }
    return true;
}
bool solve(int i, int j, string s , string p)
{
    if( i < 0 && j < 0)
    {
        return true;
    }
    if(i >= 0 && j < 0)
    {
        return false;
    }
    if(i < 0 && j >=0)
    {
        return isAllStars(p, j);
    }

    if(s[i] == p[j] || p[j] == '?')
    {
        return solve(i-1, j-1, s, p);
    }
    if(p[j] == '*')
    {
        return solve(i, j-1, s, p) || solve(i-1, j, s, p);
    }
    return false;
}
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        return solve(n-1, m-1, s, p);
        
    }



class Solution {
public:
    bool isAllStars(string& s1, int i) {
        for (int j = 0; j <= i; j++) {
            if (s1[j] != '*')
                return false;
        }
        return true;
    }
    bool solve(int i, int j, string s, string p, vector<vector<bool>> &dp) {
        if (i < 0 && j < 0) {
            return true;
        }
        if (i >= 0 && j < 0) {
            return false;
        }
        if (i < 0 && j >= 0) {
            return isAllStars(p, j);
        }

        if(dp[i][j] != -1)
        {
            dp[i][j];
        }
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        } else {
            if (p[j] == '*') {
                return dp[i][j] = solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp);
            }
            else return false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, -1));
        return solve(n - 1, m - 1, s, p, dp);
    }
};