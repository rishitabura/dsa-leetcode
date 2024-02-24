/*memoization
tc  - O(n*2*3)
sc - O(n*2*3)+ O(n)*/
int solve(int ind, int canBuy, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (limit == 0)
        return 0;
    if (ind == prices.size())
        return 0;

    if (dp[ind][canBuy][limit] != -1)
    {
        return dp[ind][canBuy][limit];
    }
    int profit;
    if (canBuy)
    {
        int buy = -prices[ind] + solve(ind + 1, 0, limit, prices, dp);
        int notBuy = 0 + solve(ind + 1, 1, limit, prices, dp);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[ind] + solve(ind + 1, 1, limit - 1, prices, dp);
        int notSell = 0 + solve(ind + 1, 0, limit, prices, dp);
        profit = max(sell, notSell);
    }
    return dp[ind][canBuy][limit] = profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, 1, 2, prices, dp);
}

/*tabulation
tc - O(n*2*3)
sc- O(n*2*3)*/
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

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
        for (int limit = 0; limit <= 2; limit++)
        {
            dp[n][canBuy][limit] = 0;
        }
    }

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int limit = 1; limit <= 2; limit++)
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
    return dp[0][1][2];
}

/*space optimazation
tc - O(n*3*2)
sc - O(2*3)*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int limit = 1; limit <= 2; limit++)
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
    return after[1][2];
}