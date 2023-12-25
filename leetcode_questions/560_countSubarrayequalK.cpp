#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*brute force
time - O(n^3)
space - O(n^3)*/
// int subarraySum(vector<int>& nums, int k) {

//     int n = nums.size();
//     int count=0;
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
//                 count++;
//             }
//         }

//     }
//     return count;
// }

/*better
time - O(n^2)*/
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<int> nums = {3, 1, 2, 4};
    cout << subarraySum(nums, 6);

    return 0;
}