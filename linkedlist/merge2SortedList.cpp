ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    ListNode *temp = new ListNode();
    ListNode *ptr = temp;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            ptr->next = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }

    while (list1 != NULL)
    {
        ptr->next = list1;
        list1 = list1->next;
        ptr = ptr->next;
    }
    while (list2 != NULL)
    {
        ptr->next = list2;
        list2 = list2->next;
        ptr = ptr->next;
    }

    return temp->next;
}