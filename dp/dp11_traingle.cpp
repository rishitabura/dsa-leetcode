/*recursion time - O(2 ^ sum of row no)*/

/*memoization
time - O(n*m)
space - O(n*m) and O(n*m stack space)*/
class Solution {
public:
int solve(int i, int j, vector<vector<int>>& triangle, int n,vector<vector<int>> &dp){

    if(dp[i][j] != -1){
		return dp[i][j];
	}

    if(i == n-1){
        return triangle[n-1][j];
    }

    int down = triangle[i][j] + solve(i+1, j,triangle,n,dp);
    int diagonal = triangle[i][j] + solve(i+1, j+1,triangle,n,dp);
    return dp[i][j] =  min(down, diagonal);
    
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0,0,triangle, n,dp);
    }
};

// tabulation
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}