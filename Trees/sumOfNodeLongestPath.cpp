class Solution
{

public:
    void solve(Node* root, int len, int sum,int &maxLen, int &maxSum)
    {
        if(!root)
        {
            if(maxLen < len)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if (maxLen == len && maxSum < sum)
            {
                maxSum = sum;
            }
            return ;
        }
        
       
        solve(root->left, len+1, sum + root->data, maxLen, maxSum);
        solve(root->right, len+1, sum + root->data, maxLen, maxSum);

    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(!root) return 0;
        
        int maxSum = INT_MIN;
        int maxLen = 0;
        
        solve(root, 0, 0 ,maxLen, maxSum);
        
        return maxSum;
    }
};