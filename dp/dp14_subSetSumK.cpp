#include <bits/stdc++.h> 

/*memoization O(n*k)
spcae - O(n) + O(n*k)*/
bool solve(int ind,int k, vector<int> &arr, vector<vector<int>>&dp)
{
    if(dp[ind][k] != -1){
        return dp[ind][k];
    }
    if(k == 0){
        return true;
    }
    if(ind == 0){
        return (arr[0] == k);
    }

    bool notTake = solve(ind-1, k, arr,dp);
    bool take = false;
    if(k >= arr[ind])
    {
        take = solve(ind-1,k-arr[ind], arr,dp);
    }

    return dp[ind][k] =  take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<int>>dp (n+1, vector<int>(k+1, -1));
    return solve(n-1, k , arr,dp);
}

/*tabulation time -  O(n*k)
spcae - O(n*k)*/
bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<bool>>dp (n, vector<bool>(k+1, false));
    
    for(int i = 0; i<n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int ind = 1; ind <n; ind++)
    {
        for(int target =1; target<=k; target++)
        {
            bool notTake = dp[ind-1][target];
            bool take =false;
            if(arr[ind] <= target){
                take = dp[ind-1][target-arr[ind]];
            }
            dp[ind][target] = take || notTake; 
        }
    }
    return dp[n-1][k];
}