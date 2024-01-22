#include <bits/stdc++.h>
#include <vector>
using namespace std;

// // memoiation
// int maxRob(int index, vector<int> &nums, vector<int> &dp)
// {
//     if (index == 0)
//     {
//         return nums[index];
//     }
//     if (index < 0)
//     {
//         return 0;
//     }
//     if (dp[index] != -1)
//     {
//         return dp[index];
//     }

//     int pick = nums[index] + maxRob(index - 2, nums, dp);
//     int notPick = 0 + maxRob(index - 1, nums, dp);

//     return dp[index] = max(pick, notPick);
// }
// int rob(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return maxRob(n - 1, nums, dp);
// }

// tabulation
int maxRob(int index, vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();
    dp[0] = nums[0];
    
   for (int i = 1; i < n; i++)
   {
        int pick = nums[i] ;
        if (i>1)
        {
            pick += dp[i-2];
        }
        
        int notPick = 0 + dp[i-1];

        dp[i] = max(pick,notPick);
   }

    return dp[n-1] ;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    return maxRob(n, nums, dp);
}

int main()
{

    return 0;
}