// all nos thrice except for 1 num - find that num
/*1. using map
2. using bit manipulation - tc - (n*32) sc - O(1)
3. using sort  - tc - nlogn + n/3
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// method 1
int solve(vector<int> &nums)
{
    int ans = 0;
    for (int bitIndex = 0; bitIndex < 31; bitIndex++)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // if bit set or not
            if ((nums[i] & (1 << bitIndex)) != 0)
            {
                count++;
            }
        }
        if (count % 3 == 1)
        {
            // set that bit of answer
            ans = ans | (1 << bitIndex);
        }
    }
    return ans;
}

// method 2
int solve2(vector<int>&nums)
{   
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i+=3)
    {
        if(nums[i-1] != nums[i])
        {
            return nums[i-1];
        }
    }
    return nums[n-1];
    

}
int main()
{
    vector<int> nums = {5, 5, 5, 4, 4, 6, 4, 7, 7, 7};
    cout << solve2(nums);

    return 0;
}