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
bool findTarget(TreeNode *root, int k)
{
    vector<int> temp;
    inorder(root, temp);

    int i = 0, j = temp.size() - 1, sum = 0;
    while (i < j)
    {
        sum = temp[i] + temp[j];
        if (sum == k)
        {
            return true;
        }
        if (sum < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}
