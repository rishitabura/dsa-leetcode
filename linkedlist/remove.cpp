#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertEnd(node* &head, int val)
{
    node* newNode = new node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    

    node* temp = head;

    while (temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    
}

void removefromlast(node* &head, int n)
{
    node* temp = head;
    int count = 0;
    while (temp!= nullptr)
    {
        count++;
        temp = temp->next;
    }
    int k = count-n;
    // if(k == 0)
    // {
    //     return head->next;
    // }

    node* p = head;
    node* q = head->next;

    for (int i = 1; i <k; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;

    delete q;
    
    
}
void display(node* head)
{
    node* temp = head;
    while (temp!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

int main()
{
    node* head = NULL;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);


    display(head);
    removefromlast(head, 3);
    display(head);
    
    return 0;
}