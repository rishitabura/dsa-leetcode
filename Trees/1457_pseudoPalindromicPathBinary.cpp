#include <bits/stdc++.h>
#include <vector>
#include <map>
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

// void getPath(node *root, vector<int> temp, int &count)
// {
//     if (!root)
//     {
//         return;
//     }
//     temp.push_back(root->data);

//     if (root->left == nullptr && root->right == nullptr)
//     {
//         int odd = 0;
//         map<int, int> mp;
//         for (auto it : temp)
//         {
//             mp[it]++;

//         }
//         for (auto it : mp)
//         {
//             if (it.second % 2 == 1)
//             {
//                 odd++;
//             }
//         }
//         if (odd == 1)
//         {
//             count++;
//         }
//         cout << count << endl;
//         // mp.clear();
//         return;
//     }
//     if (root->left)
//     {
//         getPath(root->left, temp, count);
//     }

//     if (root->right)
//     {
//         getPath(root->right, temp, count);
//     }

//     temp.pop_back();
// }

// int rootToLeaf(node *root)
// {
//     int count = 0;
//     vector<int> temp;
//     if (!root)
//     {
//         return 0;
//     }

//     getPath(root, temp, count);

//     return count;
// }

void findPath(node *root, vector<int> &temp, int &count)
{
    if (!root)
    {
        return;
    }

    temp[root->data]++;

    if (!root->left && !root->right)
    {
        int odd = 0;
        for (auto it : temp)
        {
            if (it % 2 == 1)
            {
                odd++;
            }
        }
        if (odd <= 1)
        {
            count++;
        }
    }

    if (root->left)
    {
        findPath(root->left, temp, count);
    }
    if (root->right)
    {
        findPath(root->right, temp, count);
    }

    temp[root->data]--;
}

int pseudoPalindromicPaths(node *root)
{

    int count = 0;
    vector<int> temp(10, 0);
    findPath(root, temp, count);
    return count;
}

int main()
{
    node *root = new node(2);
    root->left = new node(3);
    root->right = new node(1);

    root->left->left = new node(3);
    root->left->right = new node(1);
    root->right->right = new node(1);

    cout << rootToLeaf(root);

    return 0;
}