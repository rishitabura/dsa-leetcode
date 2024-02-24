// same as buy sell 2 , you just cannot buy next day after you sell stock
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    dp[n][0] = 0;
    dp[n][1] = 0;
    int profit;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j >= 0; j--)
        {
            if (j)
            {
                int buy = -prices[i] + dp[i + 1][0];
                int notBuy = 0 + dp[i + 1][1];
                dp[i][j] = max(buy, notBuy);
            }
            else
            {
                int sell = prices[i] + dp[i + 2][1];
                int notSell = 0 + dp[i + 1][0];
                dp[i][j] = max(sell, notSell);
            }
        }
    }
    return dp[0][1];
}