#include <bits/stdc++.h>
#include <vector>
using namespace std;

int printCount(int ind, vector<int> &nums, int sum, int target)
{
    int n = nums.size();
    if (ind >= n || sum > target)
    { // condition satisfied
        if (sum == target)
        {
            return 1;
        }
        // condition satisfied
        else return 0;
    }

    sum += nums[ind];
    int l = printCount(ind + 1, nums,  sum, target) == true;
    
    sum -= nums[ind];
    int r = printCount(ind + 1, nums, sum, target) == true;
    
    return l+r;
}

int main()
{
    vector<int> nums = {1, 2, 1};

    cout << printCount(0, nums,  0, 2);

    return 0;
}