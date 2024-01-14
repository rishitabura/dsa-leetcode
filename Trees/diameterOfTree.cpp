#include <bits/stdc++.h>
#include <queue>
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

int height(node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return max(l,r)+1;
    
}
// longest path bet 2 nodes
// for a node = l+h+1 and then find max of this 
int diameter(node* root)
{
    if (root==nullptr)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    
    int d = lh + rh + 1;
    int ld = diameter(root->left);
    int rd = diameter(root->right);

    int maxi = max(d, max(ld, rd));
    
    return maxi;
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

    cout << diameter(root);
    return 0;
}