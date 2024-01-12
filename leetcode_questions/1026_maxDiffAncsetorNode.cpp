class Solution {
public:
int findAns(TreeNode *root, int maxi, int mini)
{
    if(root == NULL)
    {
        return abs(maxi - mini);
    }
    mini = min(mini, root->val);
    maxi = max(maxi, root->val);

    int l = findAns(root->left, maxi, mini);
    int r = findAns(root->right, maxi, mini);

    return max(l,r);
}
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int res = findAns(root,root->val, root->val);

        return res;
    }
};