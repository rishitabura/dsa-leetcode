/* using brute force O(n^2)
using optimmal solution
time - o(n)*/
#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int sum = nums[i] + nums[j];
        if (sum == target)
        {
            return {nums[i], nums[j]};
        }
        else if (nums[i] + nums[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    vector<int> nums = {2,7,11,15};
    vector<int> res = twoSum(nums,9);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
    return 0;
}