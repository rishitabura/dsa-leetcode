#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findMax(vector<int> &nums)
{
    int maxi = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, nums[i]);
    }

    return maxi;
}

int smallestDivisorBrute(vector<int> &nums, int threshold)
{
    int h = findMax(nums);
    // cout << h << endl;

    for (int d = 1; d <= h; d++)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / (double)d);
        }
        cout << d << " - " << sum << endl;

        if (sum <= threshold)
        {
            return d;
        }
    }
    return -1;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int l = 1;
    int h = findMax(nums);
    int ans;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / (double)mid);
        }
        if (sum > threshold)
        {
            l = mid + 1;
        }
        else
        {
            ans = min(mid, ans);
            h = mid -1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << smallestDivisor(nums, threshold);

    return 0;
}