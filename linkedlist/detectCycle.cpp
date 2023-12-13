// detects if cycle present or not
bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// entry point of cycle
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *current = head;
    ListNode *temp;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            temp = fast;
            while (temp != current)
            {
                current = current->next;
                temp = temp->next;
            }
            return current;
        }
    }
    return NULL;
}

// length of cycle
int FindLength(Node *slow, Node *fast)
{
    int count = 1;
    fast = fast->next;
    while (slow != fast)
    {
        count++;
        fast = fast->next;
    }
    return count;
}
int lengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return FindLength(slow, fast);
        }
    }
    return 0;
}
