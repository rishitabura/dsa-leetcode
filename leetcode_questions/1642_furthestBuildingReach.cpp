/*using recursion memoization
time - O(b*l)
memory limit exceeded*/
class Solution
{
public:
    int solve(int ind, vector<int> &heights, int bricks, int ladders, vector<vector<int>> &dp)
    {

        if (ind == heights.size() - 1)
        {
            return 0;
        }

        if (dp[bricks][ladders] != -1)
        {
            return dp[bricks][ladders];
        }

        if (heights[ind] >= heights[ind + 1])
        {
            return dp[bricks][ladders] = 1 + solve(ind + 1, heights, bricks, ladders, dp);
        }
        else
        {
            int bybricks = 0;
            int byladders = 0;
            int diff = heights[ind + 1] - heights[ind];
            if (diff <= bricks)
            {
                bybricks = 1 + solve(ind + 1, heights, bricks - diff, ladders, dp);
            }
            if (ladders > 0)
            {
                byladders = 1 + solve(ind + 1, heights, bricks, ladders - 1, dp);
            }
            return dp[bricks][ladders] = max(bybricks, byladders);
        }
        return -1;
    }
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {

        vector<vector<int>> dp(bricks + 1, vector<int>(ladders + 1, -1));
        return solve(0, heights, bricks, ladders, dp);
    }
};