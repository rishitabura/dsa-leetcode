/*The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.*/
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int distance(node *root, int &d)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = distance(root->left, d);
    int r = distance(root->right, d);
    d = max(d, l + r);
    return max(l, r) + 1;
}
int diameterOfBinaryTree(node *root)
{
    int d = 0;
    distance(root, d);
    return d;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->left->right->left = new node(7);
    root->right->left = new node(8);

    cout << diameterOfBinaryTree(root);

    return 0;
}