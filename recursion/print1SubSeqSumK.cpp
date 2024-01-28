#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool print1SubSeqwithSumK(int ind, vector<int> &nums, vector<int> &ans, int sum, int target)
{
    int n = nums.size();
    if (ind >= n || sum > target)
    { // condition satisfied
        if (sum == target)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            return true;
        }
        // condition satisfied
        return false;
    }

    ans.push_back(nums[ind]);
    sum += nums[ind];
    if (print1SubSeqwithSumK(ind + 1, nums, ans, sum, target) == true)
    {
        return true;
    }
    ans.pop_back();
    sum -= nums[ind];
    if (print1SubSeqwithSumK(ind + 1, nums, ans, sum, target) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 1};
    vector<int> ans;
    print1SubSeqwithSumK(0, nums, ans, 0,2 );

    return 0;
}