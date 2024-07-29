bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i = 0; i<n ;i++)
	{
		sum += arr[i];
	}

	if(sum%2 != 0){
		return false;
	}
	int k = sum/2;

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