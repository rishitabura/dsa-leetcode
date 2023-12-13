#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "NULL";
        }
    }

    cout << endl;
}

void insertEnd(node *&head, int val)
{
    node *newNode = new node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// node *reverse(node *head)
// {
//     node *prevptr = nullptr;
//     node *currptr = head;
//     node *nextptr;

//     while (currptr != nullptr)
//     {
//         nextptr = currptr->next;
//         currptr->next = prevptr;

//         prevptr = currptr;
//         currptr = nextptr;
//     }

//     return prevptr;
// }

// bool isPalindrome(node *head)
// {
//     node *temp = head;
//     node *rev = reverse(head);
//     display(rev);
//     int flag = 0;
//     while (rev != NULL && temp != NULL)
//     {
//         if (rev->data == temp->data)
//         {
//             cout << rev->data << " " << temp->data << endl;
//             flag = 1;
//             rev = rev->next;
//             temp = temp->next;
//         }
//         else
//         {

//             return false;
//         }
//     }

//     if (flag == 1)
//     {
//         return true;
//     }
//     return false;
// }

node *reverse(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newHead = reverse(head->next);
    node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(node *head)
{

    node *slow = head;
    node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    node *newHead = reverse(slow->next);
    node *first = head;
    node *second = newHead;
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;
}

int main()
{
    node *head = NULL;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 1);
    // insertEnd(head, 1);
    // insertEnd(head, 6);
    display(head);
    // node *p = reverse(head);
    // display(p);

    cout << isPalindrome(head);

    return 0;
}