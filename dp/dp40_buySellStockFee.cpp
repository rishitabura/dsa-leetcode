// same as buy sell stock 2 , you just need to take fee for every trasaction either at buy or sell
int maxProfit(vector<int> &prices, int fee)
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
                int sell = prices[i] - fee + ahead[1];
                int notSell = 0 + ahead[0];
                profit = max(sell, notSell);
            }
            curr[j] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}