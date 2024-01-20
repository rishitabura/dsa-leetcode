class Solution
{
public:
    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        int l = INT_MAX;
        if (root->left)
        {
            l = height(root->left);
        }
        int r = INT_MAX;
        if (root->right)
        {
            r = height(root->right);
        }
        return min(l, r) + 1;
    }
    int minDepth(TreeNode *root) { return height(root); }
};