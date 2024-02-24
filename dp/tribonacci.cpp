class Solution {
public:
int  f(int n,vector<int>&dp)
{
    if(dp[n] != -1){
        return dp[n];
    }
    if(n == 0){
        return 0;
    }
    if(n == 1 || n == 2){
        return 1;
    }
    else
        return dp[n] =  f(n-3,dp) + f(n-2, dp) + f(n-1, dp);
}
    int tribonacci(int n) {
        vector<int>dp(n+1, -1);
        return f(n,dp);
    }
};