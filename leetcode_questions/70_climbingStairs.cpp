#include <bits/stdc++.h>
#include <vector>
using namespace std;

int climbStairs(int n, vector<int> &dp)
{
    // brute force
    // if (n == 0)
    // {
    //     return 1;
    // }
    // else if (n == 1)
    // {
    //     return 1;
    // }
    // int left = climbStairs(n-1);
    // int right = climbStairs(n-2);

    // return left+right;

    // memoiation

    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        int left = climbStairs(n - 1, dp);
        int right = climbStairs(n - 2, dp);

        dp[n] = left + right;
    }

    return dp[n];
}

int main()
{
    int n = 3;
    vector<int> dp(n + 1, -1);
    cout << climbStairs(3,dp);

    return 0;
}