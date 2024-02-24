#include <vector>
long solve(int* denominations, int ind, int amount, vector<vector<long>>&dp) {

        if (ind == 0) {
            return (amount % denominations[0] == 0);
        }
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        long notTake =  solve(denominations, ind - 1, amount,dp);
        long take = 0;
        if (denominations[ind] <= amount) {
            take = solve(denominations, ind, amount - denominations[ind],dp);
        }
        return dp[ind][amount] = take + notTake;
    }
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n+1, vector<long>(value+1, -1));
    return solve( denominations, n-1, value,  dp);
}