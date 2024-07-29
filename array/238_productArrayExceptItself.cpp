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

    void productArray(int arr[], int n)
    {

        // Base case
        if (n == 1)
        {
            cout << 0;
            return;
        }

        int i, temp = 1;

        /* Allocate memory for the product array */
        int *prod = new int[(sizeof(int) * n)];

        /* Initialize the product array as 1 */
        memset(prod, 1, n);

        /* In this loop, temp variable contains product of
           elements on left side excluding arr[i] */
        for (i = 0; i < n; i++)
        {
            prod[i] = temp;
            temp *= arr[i];
        }

        /* Initialize temp to 1
        for product on right side */
        temp = 1;

        /* In this loop, temp variable contains product of
           elements on right side excluding arr[i] */
        for (i = n - 1; i >= 0; i--)
        {
            prod[i] *= temp;
            temp *= arr[i];
        }

        /* print the constructed prod array */
        for (i = 0; i < n; i++)
            cout << prod[i] << " ";

        return;
    }
};