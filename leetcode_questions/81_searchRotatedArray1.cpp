#include <bits/stdc++.h>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return true;

        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

        // left sorted
        if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right sorted
        else
        {
            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    cout << search(nums, 7);

    return 0;
}