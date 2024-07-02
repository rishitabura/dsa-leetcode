/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, bool isleft) {
        if (root == nullptr) {
            return 0;
        }

        if (!root->left && !root->right) {
            if (isleft) {
                return root->val;
            } else {
                return 0;
            }
        }

        int leftsum = solve(root->left, true);
        int rightsum = solve(root->right, false);

        return leftsum + rightsum;
    }
    int sumOfLeftLeaves(TreeNode* root) { 
        return solve(root, false); 
    }
};