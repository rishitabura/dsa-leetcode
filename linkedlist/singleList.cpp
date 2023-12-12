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

void insertFirst(node* &head, int val)
{
    node* newNode = new node(val);

    newNode->next = head;
    head = newNode;
}

void deleteLast(node* &head)
{
    node* p = head;
    node* q = head->next;

    while (q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;    
    
    
}

int length(node* head)
{
    node* temp = head;
    int count = 0;
    while (temp!=nullptr)
    {
        count++;
        temp= temp->next;
    }

    return count;
    
}

bool search(node* head, int key)
{
    node* temp = head;
    while (temp!= NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
        
    }
    return false;
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

node* reverse(node* head)
{
    node* prevptr = nullptr;
    node* currptr = head;
    node *nextptr;

    while (currptr!= nullptr)
    {
        nextptr= currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
    
}

int main()
{
    node* head = NULL;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertFirst(head, 4);

    display(head);

    // deleteLast(head);
    // display(head);

    // cout << length(head);
    // cout << search(head, 5);

    node* newHead = reverse(head);
    display(newHead);
    
    return 0;
}