package leetcode_questions;

class Node1{
    int data;
    Node1 left;
    Node1 right;

    Node1(int data)
    {
        this.data = data;
        left = right = null;
    }

}
public class BinaryTraversal {

    Node1 root;
    BinaryTraversal()
    {
        root = null;
    }

    public  void preoder(Node1 root)
    {
        if (root == null)
        {
            return;
        }
        System.out.print(root.data + " " );
        preoder(root.left);
        preoder(root.right);

    }
    public  void inorder(Node1 root)
    {
        if (root == null)
        {
            return;
        }
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public  void postorder(Node1 root)
    {
        if (root == null)
        {
            return;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");

    }

    public static void main(String[] args) {
        BinaryTraversal tree = new BinaryTraversal();
        tree.root = new Node1(1);
        tree.root.left = new Node1(2);
        tree.root.right = new Node1(3);
        tree.root.left.left = new Node1(4);
        tree.root.left.right = new Node1(5);
        tree.root.right.left = new Node1(6);
        tree.root.right.right = new Node1(7);

        System.out.print("Preorder : ");
        tree.preoder(tree.root);

        System.out.print("\nInorder : ");
        tree.inorder(tree.root);

        System.out.print("\nPostorder : ");
        tree.postorder(tree.root);

    }
}
