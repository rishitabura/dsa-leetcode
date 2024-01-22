#include <bits/stdc++.h>
#include <vector>
using namespace std;

// vector<int> findErrorNums(vector<int> &nums)
// {
//     int duplicate, missing;
//     int n = nums.size();
//     unordered_map<int, int> mp;
//     for (int i = 1; i <= n; i++)
//     {
//         mp[i]++;
//     }
//     for (auto it : nums)
//     {
//         mp[it]--;
//     }
//     for (auto m : mp)
//     {
//         if (m.second == -1)
//         {
//             duplicate = m.first;
//         }
//         if (m.second == 1)
//         {
//             missing = m.first;
//         }
//     }
//     return {duplicate, missing};
// }

vector<int> findErrorNums(vector<int> &nums)
{
    int duplicate, missing;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
        {
            duplicate = abs(nums[i]);
        }
        else
        {
            nums[abs(nums[i]) - 1] *= (-1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            missing = i + 1;
        }
    }
    return {duplicate, missing};
}
int main()
{

    return 0;
}