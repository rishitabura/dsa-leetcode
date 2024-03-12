class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> prefix(n);
        vector<int> postfix(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = nums[i] * prefix[i - 1];
        }

        postfix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            postfix[i] = nums[i] * postfix[i + 1];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans[0] = postfix[i + 1];
            }
            else if (i == n - 1)
            {
                ans[i] = prefix[i - 1];
            }
            else
            {
                ans[i] = prefix[i - 1] * postfix[i + 1];
            }
        }

        return ans;
    }
};