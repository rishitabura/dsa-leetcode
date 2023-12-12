#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

Node* constructLL(vector<int>& arr) {
    int n = arr.size();

    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1 ; i<n ; i++)
    {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head; 

}

void display(Node* head)
{
    Node* temp = head;
    while (temp!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

int main()
{
    vector<int> arr = {2,3,4,5};
    Node* head = new Node();

    head = constructLL(arr);
    display(head);

    return 0;
}