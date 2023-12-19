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

node *insert(node *root, int val)
{
    if (root == nullptr)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
}
void inorder(node *root)
{
    node *temp = root;
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


bool validate(node* root, int minVal, int maxVal)
{
    if (root==nullptr)
    {
        return true;
    }
    if (root->data >= maxVal || root->data<=minVal)
    {
        return false;
    }
    return validate(root->left,minVal,root->data) && validate(root->right,root->data,maxVal);    
}
bool isBst(node* root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    return validate(root,min,max);
    
}

int main()
{
    node *root = nullptr;
    root = insert(root, 5);
    insert(root, 4);
    insert(root, 7);
    insert(root, 1);
    insert(root, 6);
    // cout << "Preorder : ";
    // inorder(root);
    cout << isBst(root);

    return 0;
}