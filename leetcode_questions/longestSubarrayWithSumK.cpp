#include <bits/stdc++.h>
#include <vector>
#include<map>
using namespace std;

/*brute force
time - O(n^3)
space - O(n^3)*/
// int longestsubarraySumK(vector<int>& nums, int k) {

//     int n = nums.size();
//     int len=0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             int sum = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 sum += nums[k];
//             }
//             if (sum == k)
//             {
//                 len = max(len, j-i+1);
//             }
//         }

//     }
//     return len;
// }

/*brute
time - O(n^2)*/
// int longestsubarraySumK(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int len = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += nums[j];
//             if (sum == k)
//             {
//                 len = max(len, j-i+1);
//             }
//         }
//     }
//     return len;
// }

/*better
using prefix sum , hashmap*/
int longestsubarraySumK(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxLen = 0;
    map<int, int> preMap;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;
        if (preMap.find(rem) != preMap.end())
        {
            int len = i - preMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preMap.find(sum) == preMap.end())
        {
            preMap[sum] = i;
        }
        
        
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1,2,3,1,1,1,1,4,2,3};
    long long k = 3;
    cout << longestsubarraySumK(nums, k);

    return 0;
}