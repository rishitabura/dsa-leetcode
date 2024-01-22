#include <bits/stdc++.h>
#include <vector>
using namespace std;

void printSubSeqwithSumK(int ind, vector<int> &nums, vector<int> &ans, int sum, int target)
{
    int n = nums.size();
    if (ind >= n || sum>target)
    {
        if (sum == target)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    ans.push_back(nums[ind]);
    sum += nums[ind];
    printSubSeqwithSumK(ind+1, nums, ans, sum, target);
    ans.pop_back();
    sum -=nums[ind];
    printSubSeqwithSumK(ind+1,nums,ans,sum,target);

}

int main()
{
    vector<int>nums = {1,2,1};
    vector<int>ans;
    printSubSeqwithSumK(0,nums, ans,0,2);

    return 0;
}