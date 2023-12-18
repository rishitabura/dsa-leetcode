#include<vector>
#include<bits/stdc++.h>
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

node* create(vector<int>&arr, int start)
{
    if(start>=arr.size())
    {
        return nullptr;
    }
    node *root = new node(arr[start]);

    root->left = create(arr,2*start+1);
    root->right = create(arr, 2*start+2);

    return root;

}
node* createTree(vector<int>&arr){
    return create(arr, 0);
}

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

int main()
{
    vector<int> arr = {1,2,3,4,5};
    node* root = createTree(arr);
    cout << "Preorder : ";
    preorder(root);
    return 0;
}