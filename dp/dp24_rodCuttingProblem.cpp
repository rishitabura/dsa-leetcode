/*recursion
tc - O(expo)
sc -O(target) */
#include <bits/stdc++.h>

int solve(int ind, vector<int>&price, int n)
{

	if(ind == 0){
		return n*price[0];
	}

	int notTake = solve(ind-1, price, n);
	int take = INT_MIN;
	int rodLen = ind+1;
	if(rodLen <= n)
	{
		take = price[ind] + solve(ind, price, n- rodLen);
	}
	return max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	return solve(n-1, price, n);
}


/*memoization
tc - o(n*n)
sc - O(n*n) + O(n)*/
int solve(int ind, vector<int>&price, int n, vector<vector<int>> &dp)
{

	if(ind == 0){
		return n*price[0];
	}
	if(dp[ind][n] != -1)
	{
		return dp[ind][n];
	}
	int notTake = solve(ind-1, price, n, dp);
	int take = INT_MIN;
	int rodLen = ind+1;
	if(rodLen <= n)
	{
		take = price[ind] + solve(ind, price, n- rodLen, dp);
	}
	return dp[ind][n] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1, -1));
	return solve(n-1, price, n, dp);
}

/*tabulation
tc - O(n*n)
space - O(n*n)*/
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1, -1));

	for(int N = 0; N<=n; N++)
	{
		dp[0][N] = N*price[0];
	}

	for(int i = 1; i<n ; i++)
	{
		{
			for(int N = 0; N<=n ;N++)
			{
				int notTake = dp[i-1][N];
				int take = INT_MIN;
				int rodLen = i+1;
				if(rodLen <= N)
				{
					take = price[i] + dp[i][N-rodLen]; 
				}
				dp[i][N] = max(take, notTake);
			}
		}
	}	
	return dp[n-1][n];
}
