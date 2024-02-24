/*recursion
tc - O(2^n)
sc - O(1)*/
int solve(int ind, int canBuy, vector<int> &prices)
{
    int profit;
    if (ind == prices.size())
    {
        return 0;
    }
    if (canBuy)
    {
        int buy = -prices[ind] + solve(ind + 1, 0, prices);
        int notBuy = 0 + solve(ind + 1, 1, prices);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[ind] + solve(ind + 1, 1, prices);
        int notSell = 0 + solve(ind + 1, 0, prices);
        profit = max(sell, notSell);
    }

    return profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    return solve(0, 1, prices);
}

/*memoization
tc - O(n*2)
sc - (n*2) + O*(n)*/
int solve(int ind, int canBuy, vector<int> &prices,
          vector<vector<int>> &dp)
{
    if (dp[ind][canBuy] != -1)
    {
        return dp[ind][canBuy];
    }

    int profit;
    if (ind == prices.size())
    {
        return 0;
    }
    if (canBuy)
    {
        int buy = -prices[ind] + solve(ind + 1, 0, prices, dp);
        int notBuy = 0 + solve(ind + 1, 1, prices, dp);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[ind] + solve(ind + 1, 1, prices, dp);
        int notSell = 0 + solve(ind + 1, 0, prices, dp);
        profit = max(sell, notSell);
    }

    return dp[ind][canBuy] = profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    return solve(0, 1, prices, dp);
}

/*tabulation
tc- O(n*2)
sc - (n*2)*/
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = 0;
    dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            long profit = 0;
            if (j)
            {
                int buy = -prices[i] + dp[i + 1][0];
                int notBuy = 0 + dp[i + 1][1];
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = prices[i] + dp[i + 1][1];
                int notSell = 0 + dp[i + 1][0];
                profit = max(sell, notSell);
            }
            dp[i][j] = profit;
        }
    }
    return dp[0][1];
}

/*space optimization
tc - O(n*2)
sc - O(4)*/
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<int> ahead(2, 0), curr(2, 0);
    ahead[0] = ahead[1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            long profit = 0;
            if (j)
            {
                int buy = -prices[i] + ahead[0];
                int notBuy = 0 + ahead[1];
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = prices[i] + ahead[1];
                int notSell = 0 + ahead[0];
                profit = max(sell, notSell);
            }
            curr[j] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}

/*greedy - said that we can buy ans sell on same day
tc - O(n)
sc - O(1)*/
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            ans += prices[i] - prices[i - 1];
        }
    }
    return ans;
}