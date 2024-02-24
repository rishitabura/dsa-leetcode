#include <bits/stdc++.h> 

int solve(int ind, int w, vector<int>&profit, vector<int>&weight, vector<vector<int>> &dp)
{

    if(ind == 0)
    {
        if(weight[0] <= w)
        {
            return ((int)(w/weight[0])) * profit[0];
        }
        else
        {
            return 0;
        }
    }
    if(dp[ind][w] != -1)
    {
        return dp[ind][w];
    }

    int notPick = solve(ind-1, w, profit, weight, dp);
    int pick = INT_MIN;
    if(weight[ind] <= w)
    {
        pick = profit[ind] + solve(ind, w-weight[ind], profit, weight, dp);
    }
    return dp[ind][w] =  max(pick, notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    
    vector<vector<int>>dp(n+1, vector<int>(w+1, -1));
    return solve(n-1, w, profit, weight, dp);
}