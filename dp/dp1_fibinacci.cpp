#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*recursion
time - O(2^n)
space - O(n) stack space*/
int fR(int n){
    // if (n == 0){
    //     return 0;
    // }
    // if (n == 1){
    //     return 1;
    // }
    if (n <= 1){
        return n;
    }
    return fR(n - 1) + fR(n - 2);
}

/*memoization
time - O(n)
space - O(n) + O(n)*/
int fM(int n, vector<int> &dp){
    if (n <= 1){
        return n;
    }
    if (dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fM(n - 1,dp) + fM(n - 2,dp);
}

/*tabulation
time - O(n)
spca - O(n)*/
int fT(int n, vector<int>&dp){

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];

}
int main()
{
    int n = 4;
    vector<int> dp(n + 1, -1);
    cout << fT(n, dp);
    return 0;
}