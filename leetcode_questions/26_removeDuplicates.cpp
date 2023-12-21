#include <bits/stdc++.h>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int index = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] != nums[i])
        {
            nums[index++] = nums[i];
        }
    }

    // vector<int> temp (n);
    // int j = 0;
    // for (int i = 0; i < n-1; i++)
    // {
    //     if (nums[i] != nums[i+1])
    //     {
    //         temp[j++] = nums[i];
    //     }
        
    // }
    // temp[j+1] = nums[n-1];

    // for (int i = 0; i <  j; i++)
    // {
    //     nums[i] = temp[i];
    // }
    // return j;

    return index;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int n= removeDuplicates(nums);
    for (int i = 0; i<n;i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}