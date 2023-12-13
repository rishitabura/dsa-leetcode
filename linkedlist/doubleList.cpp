#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void insertFirst(node* &head, int val)
{
    node* temp = head;
    node* newNode = new node(val);

    temp->prev = newNode;
    newNode->next = temp;

    head = newNode;
}
void insertEnd(node* &head, int val)
{
    node* newNode = new node(val);
    if (head == nullptr)
    {
        head = newNode;        
        return;
    }
    
    node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nullptr;
    
    
}

void deleteFirst(node* &head)
{
    node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
}
void deleteLast(node* &head)
{
    node* p = head;
    node* q = head->next;

    if(q == nullptr)
    {
        delete p;
    }

    while (q->next!= nullptr)
    {
        p = p->next;
        q = q->next;
    }

    p->next = nullptr;
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
    node* head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);


    insertFirst(head, 5);
    display(head);

    deleteFirst(head);;
    display(head);
    // deleteLast(head);
    // display(head);
    
    return 0;
}