#include <bits/stdc++.h>
using namespace std;

/*
1. max nodes at level L = 2^L
2. max nodes in a tree with height H = 2^H-1
3. for N nodes, min height or levels = log2(N+1)
*/

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

void preorder(node *root)
{
    node *temp = root;
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int height(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if (l > r)
        {
            return l + 1;
        }
        else
        {
            return r + 1;
        }
    }
}

void leafNodes(node* root)
{
    if (root==nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right==nullptr)
    {
        cout << root->data << " "; 
    }
    if (root->left!=nullptr)
    {
        leafNodes(root->left);
    }
    if(root->right!=nullptr)
    {
        leafNodes(root->right);
    }
    
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->left->right->left = new node(7);
    cout << "Preorder : ";
    preorder(root);
    cout << "\nInorder : ";
    inorder(root);
    cout << "\nPostorder : ";
    postorder(root);
    cout << "\nHeight : " << height(root);
    cout << "\nLeaf nodes : ";
    leafNodes(root);

    return 0;
}