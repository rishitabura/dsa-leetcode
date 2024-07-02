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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            // node->val = val;
            node->left = root;

            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int l=2;
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (l == depth) {
                    if (node->left != NULL) {
                        TreeNode* n1 = new TreeNode(val);
                        n1->left = node->left;
                        node->left = n1;
                    }
                    else
                    {
                        TreeNode* newNode = new TreeNode(val);
                        node->left = newNode;
                    }
                    if (node->right != NULL) {
                        TreeNode* n2 = new TreeNode(val);
                        n2->right = node->right;
                        node->right = n2;
                    }
                    else
                    {
                        TreeNode* newNode = new TreeNode(val);
                        node->right = newNode;
                    }
                } else {
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }  
            l++;
        }

        return root;
    }
};