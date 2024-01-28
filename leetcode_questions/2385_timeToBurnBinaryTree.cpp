#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;

    node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

int findtime(node *target, map<node *, node *> &mp)
{

    queue<node *> q;
    map<node *, bool> vis;
    int time = 0;

    q.push(target);
    vis[target] = true;
    while (!q.empty())
    {
        int size = q.size();
        int flag = 0;

        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();

            if (temp->left && !vis[temp->left])
            {
                vis[temp->left] = true;
                q.push(temp->left);
                flag = 1;
            }
            if (temp->right && !vis[temp->right])
            {
                vis[temp->right] = true;
                q.push(temp->right);
                flag = 1;
            }
            if (mp[temp] && !vis[mp[temp]])
            {
                vis[mp[temp]] = true;
                q.push(mp[temp]);
                flag = 1;
            }
        }
        if (flag == 1)
        {
            time++;
        }
    }

    return time;
}

node *bfs(node *root, map<node *, node *> &mp, int start)
{

    node *res = nullptr;
    queue<node *> q;
    q.push(root);
    mp[root] = nullptr;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->val == start)
        {
            res = temp;
        }

        if (temp->left)
        {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return res;
}

int timeToBurn(node *root, int start)
{

    map<node *, node *> mp;

    node *target = bfs(root, mp, start);

    int time = findtime(target, mp);
    return time;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->right = new node(7);
    root->right->left = new node(5);
    root->right->right = new node(6);

    cout << timeToBurn(root, 2);

    return 0;
}