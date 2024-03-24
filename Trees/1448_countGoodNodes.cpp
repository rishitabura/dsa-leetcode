/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int countNodes(TreeNode* root, int maxi)
    {
        int sum =0;
        if(root->val >= maxi)
        {
            sum++;
        }

        if(root->left)
        {
            sum+= countNodes(root->left, max(maxi, root->val));
        }
        if(root->right)
        {
            sum += countNodes(root->right, max(maxi, root->val));
        }

        return sum;

    }
public:
    int goodNodes(TreeNode* root) {

        return countNodes(root, INT_MIN);
        
    }
};