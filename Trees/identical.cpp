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

bool isIdentical(node *r1, node *r2)
{
    if (r1 == nullptr || r2 == nullptr)
    {
        return (r1 == r2);
    }

    return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}

int main()
{
    node *r1 = new node(1);
    r1->left = new node(2);
    r1->right = new node(4);
    r1->left->left = new node(3);
    r1->left->right = new node(6);
    r1->left->right->left = new node(7);
    r1->right->left = new node(8);

    node *r2 = new node(1);
    r2->left = new node(2);
    r2->right = new node(4);
    r2->left->left = new node(3);
    r2->left->right = new node(6);
    r2->left->right->left = new node(7);
    r2->right->left = new node(8);

    node *r3 = new node(1);
    r3->left = new node(2);
    r3->right = new node(4);
    r3->left->left = new node(3);
    r3->left->right = new node(6);
    r3->left->right->left = new node(5);
    r3->right->left = new node(8);

    cout << isIdentical(r1, r2) << endl;
    cout << isIdentical(r1, r3);

    return 0;
}