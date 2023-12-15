#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> nge(n,-1);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            if (!st.empty())
            {
                nge[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        st.push(nums[i % n]);
    }

    return nge;
}

int main()
{
    vector<int> nums = {2,10,12,1,11};
    vector<int> res = nextGreaterElements(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    

    return 0;
}