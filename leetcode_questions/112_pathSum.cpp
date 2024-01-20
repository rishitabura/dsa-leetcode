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

bool getPathSum(node *root, int target, int sum)
{
    if (!root)
    {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        sum += root->data;
        if (sum == target)
        {
            return true;
        }
    }
    sum += root->data;

    bool left = getPathSum(root->left, target, sum);

    bool right = getPathSum(root->right, target, sum);

    return left || right;
}

bool hasPathSum(node *root, int targetSum)
{
    int sum = 0;
    if (!root)
    {
        return false;
    }

    return getPathSum(root, targetSum, sum);
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

    cout << hasPathSum(root, 6);
    return 0;
}