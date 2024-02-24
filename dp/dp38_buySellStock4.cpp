class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // for limit = 0
        for (int ind = 0; ind < n; ind++)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                dp[ind][canBuy][0] = 0;
            }
        }

        // for ind == n
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int limit = 0; limit <= k; limit++)
            {
                dp[n][canBuy][limit] = 0;
            }
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int profit;
                    if (canBuy)
                    {
                        int buy = -prices[ind] + dp[ind + 1][0][limit];
                        int notBuy = 0 + dp[ind + 1][1][limit];
                        profit = max(buy, notBuy);
                    }
                    else
                    {
                        int sell = prices[ind] + dp[ind + 1][1][limit - 1];
                        int notSell = 0 + dp[ind + 1][0][limit];
                        profit = max(sell, notSell);
                    }
                    dp[ind][canBuy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};

/*spcae optimzation*/
int maxProfit(int k, vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> after(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int limit = 1; limit <= k; limit++)
            {
                int profit;
                if (canBuy)
                {
                    int buy = -prices[ind] + after[0][limit];
                    int notBuy = 0 + after[1][limit];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[ind] + after[1][limit - 1];
                    int notSell = 0 + after[0][limit];
                    profit = max(sell, notSell);
                }
                curr[canBuy][limit] = profit;
            }
        }
        after = curr;
    }
    return after[1][k];
}