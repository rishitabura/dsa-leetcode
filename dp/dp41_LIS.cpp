/*recursion
tc - O(2^n)
sc - O(n)*/
class Solution {
public:
int solve(int ind, int prev, vector<int>& nums)
{
    if(ind == nums.size())
    {
        return 0;
    }

    int len = 0 + solve(ind+1, prev, nums);
    if(prev == -1 || nums[ind] > nums[prev])
    {
        len = max(len, 1 + solve(ind+1, ind, nums));
    }
    return len;
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        return solve(0, prev, nums);
        
    }
};

// memoization
class Solution {
public:
int solve(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp)
{
    if(ind == nums.size())
    {
        return 0;
    }
    if(dp[ind][prev+1] != -1)
    {
        return dp[ind][prev+1];
    }

    int len = 0 + solve(ind+1, prev, nums, dp);
    if(prev == -1 || nums[ind] > nums[prev])
    {
        len = max(len, 1 + solve(ind+1, ind, nums, dp));
    }
    return dp[ind][prev+1] = len;
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(0, prev, nums, dp);
        
    }
};

/*tabulation
tc - O(n^2)
sc - O(n^2)*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int prev = i-1 ; prev >= -1; prev--) {
                int len = 0 + dp[i+1][prev+1]; 
                if (prev == -1 || nums[i] > nums[prev]) {
                    len = max(len, 1 + dp[i+1][i+1]); 
                }
                dp[i][prev + 1] = len;
            }
        }
        return dp[0][0]; 
    }
};