int countPoints(int days,int lastTask,vector<vector<int>>&points,vector<vector<int>>&dp)
{   
    if(dp[days][lastTask] != -1)
    {
        return dp[days][lastTask];
    }

    // day last
    if(days == 0)
    {
        int maxi = 0;
        for(int i = 0; i<=2; i++)
        {
            if(i != lastTask)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[0][lastTask] =  maxi;
    }
    

    int maxi = 0;
    for(int i = 0; i<=2; i++)
    {
        if(i != lastTask)
        {
            int ans = points[days][i] + countPoints(days-1,i, points,dp);
            maxi = max(maxi, ans);
        }
    }
    return dp[days][lastTask] = maxi;

}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(4,-1));
    int result = countPoints(n-1,3,points,dp);
    return result;
}