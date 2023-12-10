/*1752. Check if Array Is Sorted and Rotated
time - O(n)*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count++;
        }
        if (count > 1)
        {
            return false;
        }
    }

    if (count == 1 && nums[0] < nums[n - 1])
    {
        return false;
    }
    return true;
}

int main()
{
    vector<int> nums = {3,4,5,1,2};
    int n = nums.size();

    cout << check(nums);

    return 0;
}