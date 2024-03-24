class Solution {
private:
    void leafNodes(TreeNode* root, vector<int>& leaf) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            leaf.push_back(root->val);
        }
        if (root->left != nullptr) {
            leafNodes(root->left, leaf);
        }
        if (root->right != nullptr) {
            leafNodes(root->right, leaf);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> l1;
        leafNodes(root1, l1);
        vector<int> l2;
        leafNodes(root2, l2);

        int i = 0, j = 0;
        if (l1.size() != l2.size()) {
            return false;
        } else {
            for (int i = 0; i < l1.size(); i++) {
                if (l1[i] != l2[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};