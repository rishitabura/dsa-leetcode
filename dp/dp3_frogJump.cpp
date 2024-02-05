/*find the minimum energy lost by frog to go from 1 to n stairs
frog can jump 1 or 2 stairs*/

/*recursion
time - o(n)
space - O(n)+O(n)*/
int calEnergy(int ind, int n, vector<int> &heights){
    if(ind == 0){
        return 0;
    }

    int left = calEnergy(ind-1, n, heights) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1){
        right = calEnergy(ind-2, n, heights) + abs(heights[ind] - heights[ind-2]);
    }

    return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return calEnergy(n-1,n,heights);
    
}


/*memoization
time - o(n)
space - O(n)+O(n)*/
int calEnergy(int ind, int n, vector<int> &heights, vector<int>&dp){
    if(ind == 0){
        return 0;
    }

    if(dp[ind] != -1){
        return dp[ind];
    }
    int left = calEnergy(ind-1, n, heights,dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1){
        right = calEnergy(ind-2, n, heights,dp) + abs(heights[ind] - heights[ind-2]);
    }

    return dp[ind] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return calEnergy(n-1,n,heights,dp);
    
}

/*tabulation
time - O(n)
space - O(n)*/
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i = 1; i<n; i++){
        int left = dp[i-1]+ abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1){
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left,right);
    }

    return dp[n-1];
    
}