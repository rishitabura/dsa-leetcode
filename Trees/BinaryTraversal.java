package Trees;

class Node{
    int data;
    Node left;
    Node right;

    Node(int data)
    {
        this.data = data;
        left = right = null;
    }

}
public class BinaryTraversal {

    Node root;
    BinaryTraversal()
    {
        root = null;
    }

    public  void preoder(Node root)
    {
        if (root == null)
        {
            return;
        }
        System.out.print(root.data + " " );
        preoder(root.left);
        preoder(root.right);

    }
    public  void inorder(Node root)
    {
        if (root == null)
        {
            return;
        }
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public  void postorder(Node root)
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
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(6);
        tree.root.right.right = new Node(7);

        System.out.print("Preorder : ");
        tree.preoder(tree.root);

        System.out.print("\nInorder : ");
        tree.inorder(tree.root);

        System.out.print("\nPostorder : ");
        tree.postorder(tree.root);

    }
}
