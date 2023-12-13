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

void insertBet(node* &head, int val, int n)
{
    int count  = 1;
    node* p = head;
    node* newNode = new node(val);
    while (count != n-1)
    {
        p = p->next;
        count++;
    }
    newNode->next = p->next;
    p->next = newNode;
    
    
}

void deleteFirst(node* &head)
{
    node* temp = head;
    head = head->next;
    delete temp;
}

void deleteBet(node* &head, int n)
{
    node* p = head;
    node* q = head->next;

    int count =1;
    
    while (count != n-1)
    {
        p = p->next;
        q = q->next;
        count++;
    }

    p->next = q->next;
    delete q;
    
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

    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertFirst(head, 1);

    display(head);


    insertBet(head, 6, 4);
    display(head);


    // deleteFirst(head);
    // display(head);
    // deleteLast(head);
    // display(head);

    // deleteBet(head, 2);
    // display(head);

    // cout << length(head);
    // cout << search(head, 5);

    // node* newHead = reverse(head);
    // display(newHead);
    
    return 0;
}