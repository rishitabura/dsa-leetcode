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

void getPath(node *root, int a, vector<int> &temp, vector<vector<int>> &res)
{
    if (!root)
    {
        return;
    }

    temp.push_back(root->data);

    if (root->left)
    {
        getPath(root->left);
    }

    if (root->right)
    {
        getPath(root->right);
    }

    if (root->left == nullptr || root->right == nullptr)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            res[0][i] = temp[i];
        }
        
    }
    

    ans.pop_back();
    return false;
}

vector<int> rootToLeaf(node *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }

    getPath(root, ans);
    return ans;
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

    vector<int> ans = rootToNode(root, 8);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}