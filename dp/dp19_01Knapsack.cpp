#include <bits/stdc++.h> 
/*memoization
time  - O(n*w)
spcae - O(n*w)*/
int solve(int ind,vector<int> weight, vector<int> value, int W,vector<vector<int>> &dp)
{
	if(ind == 0)
	{
		if(weight[0] <= W)
		{
			return value[0];
		}
		else
		{
			return 0;
		}
	}
	if(dp[ind][W] != -1)
	{
		return dp[ind][W];
	}

	int notTake = solve(ind-1, weight, value, W ,dp);
	int take = INT_MIN;
	if(weight[ind] <= W)
	{
		take = value[ind] + solve(ind-1, weight, value, W-weight[ind], dp);
	}
	return dp[ind][W]  =  max(notTake,take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n+1, vector<int>(maxWeight+1, -1));
	return solve(n-1, weight, value, maxWeight,dp);
	
}

/*tabulation*/
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n+1, vector<int>(maxWeight+1, 0));
	for(int i = weight[0] ; i<= maxWeight; i++)
	{
		dp[0][i] = value[0];
	}
	for(int i = 1; i<n; i++)
	{
		for(int w = 0; w<=maxWeight;w++)
		{
			int notTake = dp[i-1][w];
			int take = INT_MIN;

			if(weight[i] <= w)
			{
				take = value[i] + dp[i-1][w-weight[i]];
			}
			dp[i][w] = max(take, notTake);
		}

	}
	return dp[n-1][maxWeight];
	
}
/*tabulation
time  - O(n*w)
spcae - O(n*w)*/
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
      
    vector<vector<int>>dp(n+1, vector<int>(w+1, 0));
	for(int i = 0 ; i<= w; i++)
	{
		dp[0][i] = ((int)i/weight[0])*profit[0];
	}
	for(int i = 1; i<n; i++)
	{
		for(int wt = 0; wt<=w;wt++)
		{
			int notTake = dp[i-1][wt];
			int take = INT_MIN;

			if(weight[i] <= wt)
			{
				take = profit[i] + dp[i][wt-weight[i]];
			}
			dp[i][wt] = max(take, notTake);
		}

	}
	return dp[n-1][w];
}