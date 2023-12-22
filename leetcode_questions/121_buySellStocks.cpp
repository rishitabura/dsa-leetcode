class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        int n = prices.size();
        int cost;
        for(int i = 0;i<n;i++)
        {
            cost = prices[i] - mini;
            profit = max(cost,profit);
            mini = min(mini,prices[i]);
        }
        
        return profit;
    }
};