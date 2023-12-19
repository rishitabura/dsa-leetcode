void inorder(TreeNode *root, vector<int> &temp)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, temp);
    temp.push_back(root->val);
    inorder(root->right, temp);
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> temp;
    inorder(root, temp);
    return temp[k - 1];
}