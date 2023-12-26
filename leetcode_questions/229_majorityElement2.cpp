#include <bits/stdc++.h>
#include <vector>
using namespace std;

// brute force - time O(n^2)
vector<int> BrutemajorityElement(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (ans.size() == 0 || ans[0] != nums[i])
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == nums[i])
                {
                    count++;
                }
            }
            if (count > n / 3)
            {
                ans.push_back(nums[i]);
            }
        }
        if (ans.size() == 2)
        {
            break;
        }
    }
    return ans;
}

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> ans;
    int count1 = 0;
    int count2 = 0;
    int el1, el2;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && el2 != nums[i])
        {
            count1 = 1;
            el1 = nums[i];
        }
        else if (count2 == 0 && el1 != nums[i])
        {
            count2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
        {
            count1++;
        }
        else if (el2 == nums[i])
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el1 == nums[i])
        {
            count1++;
        }
        if (el2 == nums[i])
        {
            count2++;
        }
    }
    int mini = int(n / 3) + 1;
    if (count1 >= mini)
    {
        ans.push_back(el1);
    }
    if (count2 >= mini)
    {
        ans.push_back(el2);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,2};
    vector<int> ans = majorityElement(nums);
    for(auto it: ans)
    {
        cout << it << " ";
    }

    return 0;
}