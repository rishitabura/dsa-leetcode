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