package leetcode_questions;

import java.util.ArrayList;
import java.util.List;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int data)
    {
        val = data;
        left = right = null;
    }
}
public class inorderBinary {
    public void inorder(TreeNode root, List<Integer>ans)
    {
        if (root == null)
        {
            return;
        }
        inorder(root.left, ans);
        ans.add(root.val);
        inorder(root.right,ans);
    }
    public List<Integer>inorderTraversal(TreeNode root)
    {
        List<Integer> ans = new ArrayList<>();
        inorder(root,ans);
        return ans;
    }

    public static void main(String[] args) {

        // Create a sample binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        // Create an instance of inorderBinary
        inorderBinary tree = new inorderBinary();

        // Perform inorder traversal
        List<Integer> inorderList = tree.inorderTraversal(root);

        // Print the inorder traversal result
        System.out.println("Inorder Traversal: " + inorderList);

    }
}
