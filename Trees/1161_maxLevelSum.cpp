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
    int maxLevelSum(TreeNode* root) {

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int level = 1;
        int maxlevel = 1;
        int maxsum = root->val;

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                int currlevel = q.front().second;
                q.pop();
                sum += node->val;
                if(node->left){
                    q.push({node->left, currlevel+1});
                }
                if(node->right)
                {
                    q.push({node->right, currlevel+1});
                }
            }
            if(sum > maxsum)
            {
                maxlevel = level;
                maxsum = sum;
            }
            level++;
        }

        return maxlevel;
    }
};