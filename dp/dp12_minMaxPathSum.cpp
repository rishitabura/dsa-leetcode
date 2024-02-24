class Solution {
public:
    int getMin(int i, int j,int m, vector<vector<int>>& matrix,
               vector<vector<int>>& dp) {
        if (j < 0 || j >= m) {
            return 1e9;
        }
        if (i == 0) {
            return matrix[0][j];
        }
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        int up = matrix[i][j] + getMin(i-1,j,m,matrix,dp);
        int leftD = matrix[i][j] + getMin(i-1,j-1,m,matrix,dp);
        int rightD = matrix[i][j] + getMin(i-1,j+1,m,matrix,dp);

        return dp[i][j] = min(up, min(leftD, rightD));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        for (int i = 0; i < m; i++) {
            int ans = getMin(n-1,i,m,matrix,dp);
            mini = min(ans,mini);
        }
        return mini;
    }
};