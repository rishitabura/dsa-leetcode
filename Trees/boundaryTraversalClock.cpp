#include <bits/stdc++.h>
#include <vector>
#include <stack>
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

// anticlockwise
/*1. left bounday excluding leaf
2. inorder for leaf nodes
3. right boundary in reverse excluding leaf node*/

bool isLeaf(node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    return false;
}

void addLeftBoundary(node *root, vector<int> &res)
{
    node *current = root->left;
    stack<int> st;
    while (current)
    {
        if (!isLeaf(current))
        {
            st.push(current->data);
        }
        if (current->left)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
}

void addLeaves(node *root, vector<int> &res)
{
    node *current = root;
    if (isLeaf(current))
    {
        res.push_back(current->data);
        return;
    }
    if (current->right)
    {
        addLeaves(current->right, res);
    }
    if (current->left)
    {
        addLeaves(current->left, res);
    }
}
void addRightBoundary(node *root, vector<int> &res)
{
    node *current = root->right;
    while (current)
    {
        if (!isLeaf(current))
        {
            res.push_back(current->data);
        }
        if (current->right)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
}
vector<int> boundaryTraversalClock(node *root)
{
    vector<int> res;
    if (!root)
    {
        return res;
    }
    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }
    addRightBoundary(root, res);
    addLeaves(root, res);
    addLeftBoundary(root, res);

    return res;
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

    vector<int> result = boundaryTraversalClock(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}