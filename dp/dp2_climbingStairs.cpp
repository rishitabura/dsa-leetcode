#include<bits/stdc++.h>
#include<vector>
using namespace std;

int climbingStairs(int n, vector<int> &dp){

    if (n <= 1){
        return 1;
    }
    if (dp[n] != -1){
        return dp[n];
    }
    int left = climbingStairs(n-1,dp);
    int right = climbingStairs(n-2,dp);

    return dp[n] = left+right;
}
int main()
{
    int n = 3;
    vector<int> dp(n + 1, -1);
    cout << climbingStairs(n, dp);
    
    return 0;
}