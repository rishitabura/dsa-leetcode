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

node *middleNode(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    cout << "Count - " << count << endl;
    int mid = (count) / 2;
    cout << "Mid - " << mid << endl;
    node *p = head;

    if (mid % 2 != 0)
    {
        for (int i = 1; i <= mid; i++)
        {
            p = p->next;
        }
        return p;
    }
    else
    {
        for (int i = 1; i <= mid; i++)
        {
            p = p->next;
        }
        return p;
    }

    return NULL;
}

node *middle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *deleteMiddle(node *head)
{
    node *prev;
    node *slow = head;
    node *fast = head;

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    node *temp = slow;
    prev->next = slow->next;
    delete temp;

    return head;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 3);
    insertEnd(head, 2);
    // insertEnd(head, 1);

    node *p = deleteMiddle(head);
    display(p);

    return 0;
}