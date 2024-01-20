#include <bits/stdc++.h>
#include <vector>
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

void getPath(node *root, vector<vector<int>> &res, vector<int> temp)
{
    if (!root)
    {
        return;
    }

    if(root->left == nullptr && root->right == nullptr)
    {
        temp.push_back(root->data);
        res.push_back(temp);
        return;
    }
    if (root->left)
    {
        getPath(root->left,res, temp);
    }

    if (root->right)
    {
        getPath(root->right, res, temp);
    }

    temp.pop_back();
}

vector<vector<int>> rootToLeaf(node *root)
{
    vector<vector<int>> res;
    vector<int> temp;
    if (!root)
    {
        return res;
    }

    getPath(root, res, temp);
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

    vector<vector<int>> ans = rootToLeaf(root);
    for (auto it: ans)
    {
        cout << "[";
        for (auto s: it)
        {
            cout << s << " ";
        }
        cout << "]";
        
    }

    return 0;
}