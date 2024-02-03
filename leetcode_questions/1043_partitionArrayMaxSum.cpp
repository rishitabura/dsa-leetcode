// recursion
int solve(vector<int> &arr, int k, int ind)
{

    int n = arr.size();
    if (ind == n)
    {
        return 0;
    }

    int maxAns;
    int len = 0;
    int maxi = INT_MIN;
    int sum;
    for (int j = ind; j < min(n, ind + k); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        sum = (len * maxi) + solve(arr, k, j + 1);
        maxAns = max(maxAns, sum);
    }

    return maxAns;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{

    return solve(arr, k, 0);
}

// memoiation time - O(n)+O(k) space - O(n)+O(n)
int solve(vector<int> &arr, int k, int ind, vector<int> &dp)
{

    int n = arr.size();
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int maxAns = INT_MIN;
    int len = 0;
    int maxi = INT_MIN;
    int sum;
    for (int j = ind; j < min(n, ind + k); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        sum = (len * maxi) + solve(arr, k, j + 1, dp);
        maxAns = max(maxAns, sum);
    }

    return dp[ind] = maxAns;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(arr, k, 0, dp);
}

// tabulation
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        int maxAns = INT_MIN;
        int len = 0;
        int maxi = INT_MIN;
        int sum;
        for (int j = ind; j < min(n, ind + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            sum = (len * maxi) + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }

    return dp[0];
}