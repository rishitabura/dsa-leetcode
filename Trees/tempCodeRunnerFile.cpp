#include <bits/stdc++.h>
#include <vector>
#include<map>
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

void getPath(node *root, vector<vector<int>> &res, vector<int> temp, int &count, map<int, int>&mp)
{
    if (!root)
    {
        return;
    }
    temp.push_back(root->data);
    mp[root->data]++;

    if (root->left)
    {
        getPath(root->left, res, temp, count,mp);
    }

    if (root->right)
    {
        getPath(root->right, res, temp, count,mp);
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        int odd;
        for(auto it: temp){
            if (mp[it] %2 == 1)
            {
                odd++;
            }
        }
        if (odd == 1)
        {
            count ++;
        }
        
        res.push_back(temp);
        mp.clear();
        return;
    }

    temp.pop_back();
}

int rootToLeaf(node *root)
{
    int count = 0;
    vector<vector<int>> res;
    vector<int> temp;
    map<int, int> mp;
    if (!root)
    {
        return 0;
    }

    getPath(root, res, temp, count,mp);
    return count;
}

int main()
{
    node *root = new node(2);
    root->left = new node(3);
    root->right = new node(1);
    root->left->left = new node(3);
    root->left->right = new node(1);
    root->left->right->right = new node(1);

    cout << rootToLeaf(root);

   

    return 0;
}