/*memoization*/
long long  mod = 1e9+7;
int solve(int ind, vector<int>& arr, int k,vector<vector<int>> &dp)
{
	if(k == 0){
		return 1;
	}

	if(ind == 0 ){
		if(arr[0] == k)
		{	
			return 1;
		}
		if( k == 0 && arr[0] == 0)
		{
			return 2;
		}
		return 0;
	}
	
	if(dp[ind][k] != -1)
	{
		return dp[ind][k];
	}

	int notpick = solve(ind-1, arr, k,dp);
	
	int pick = 0;
	if(arr[ind] <= k){
		pick = solve(ind-1, arr, k-arr[ind], dp);
	}
	return dp[ind][k] =  (notpick%mod + pick%mod)%mod;

}
int findWays(vector<int>& arr, int k)
{
	int n= arr.size();
	vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
	return solve (n-1, arr, k,dp);


}


