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

bool validate(node *root, int minVal, int maxVal)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data >= maxVal || root->data <= minVal)
    {
        return false;
    }
    return validate(root->left, minVal, root->data) && validate(root->right, root->data, maxVal);
}
bool isBst(node *root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    return validate(root, min, max);
}

node *searchBST(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        return root;
    }
    else if (root->val > val)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return searchBST(root->right, val);
    }
}

int minVal(node *root)
{
    int mini = 0;
    if (root == NULL)
    {
        return -1;
    }
    while (root)
    {
        mini = root->data;
        root = root->left;
    }
    return mini;
}

int maxVal(node *root)
{
    int maxi = 0;
    if (root == NULL)
    {
        return -1;
    }
    while (root)
    {
        maxi = root->data;
        root = root->right;
    }
    return maxi;
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
    cout << maxVal(root);

    return 0;
}