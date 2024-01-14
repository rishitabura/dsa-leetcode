#include <bits/stdc++.h>
#include <queue>
using namespace std;

/*
1. max nodes at level L = 2^L
2. max nodes in a tree with height H = 2^H-1
3. for N nodes, min height or levels = log2(N+1)
*/
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

void preorder(node *root)
{
    node *temp = root;
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void preorderIterative(node *root)
{
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *temp = st.top();
        cout << temp->data << " ";
        st.pop();
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
}

void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorderIterative(node *root)
{
    stack<node *> st;
    // st.push(root);
    node *temp = root;
    while (true)
    {
        if (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty())
                break;

            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}

void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void postorderIterative(node *root)
{
    stack<node *> st1;
    stack<node *> st2;

    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left)
        {
            st1.push(root->left);
        }
        if (root->right)
        {
            st1.push(root->right);
        }
    }
    while (!st2.empty())
    {
        node *temp = st2.top();
        cout << temp->data << " ";
        st2.pop();
    }
}

int height(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if (l > r)
        {
            return l + 1;
        }
        else
        {
            return r + 1;
        }
    }
}

bool isBalanced(node *root)
{
    if (root == nullptr)
    {
        return true;
    }

    if (!isBalanced(root->left) || !isBalanced(root->right))
    {
        return false;
    }

    int l = height(root->left);
    int r = height(root->right);

    if (abs(l - r <= 1))
    {
        return true;
    }
    else
    {
        return false;
    }

}

void leafNodes(node *root, int &count)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->data << " ";
        count++;
    }
    if (root->left != nullptr)
    {
        leafNodes(root->left, count);
    }
    if (root->right != nullptr)
    {
        leafNodes(root->right, count);
    }
}
int countNode(node *root)
{

    if (root == nullptr)
    {
        return 0;
    }

    int l, r;
    l = countNode(root->left);
    r = countNode(root->right);

    return l + r + 1;
}

void levelwiseDisplay(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *temp = q.front();
            cout << temp->data << " ";

            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
            q.pop();
        }
    }
}

void mirrorImage(node *root)
{
    node *temp;
    if (root != nullptr)
    {
        mirrorImage(root->left);
        mirrorImage(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

bool search(node *root, int val)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }

    return search(root->left, val) || search(root->right, val);
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
    return validate(root, INT_MIN, INT_MAX);
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
    // root->left->right->left->left = new node(10);
    // cout << isBst(root);
    // cout << search(root,9);
    // cout << "Preorder : ";
    // preorderIterative(root);
    // cout << endl;
    // preorder(root);
    // cout << "\nInorder : ";
    // inorder(root);
    // inorderIterative(root);
    // cout << "\nPostorder : ";
    // postorder(root);
    // postorderIterative(root);
    // cout << isBalanced(root);
    // cout << "\nHeight : " << height(root);
    // cout << "\nLeaf nodes : ";
    // int count=0;
    // leafNodes(root,count);
    // cout << "\nNo of leaf nodes : " << count;
    // // int count = 0;
    // cout << "\nCount : " << countNode(root);
    // cout << "\nLevel wise display : ";
    // levelwiseDisplay(root);
    // cout << "\nMirror image preeoder : ";
    // mirrorImage(root);
    // preorder(root);

    return 0;
}