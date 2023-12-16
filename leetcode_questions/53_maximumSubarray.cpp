#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxi = INT_MIN;
    int ansstart, ansend = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        int start;
        if (sum==0)
        {
            start = i;
        }
        
        sum += nums[i];
        if (sum > maxi)
        {
            maxi = sum;
            ansstart = start;
            ansend = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    for (int i = ansstart; i <= ansend; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return maxi;
}
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);

    return 0;
}