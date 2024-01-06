// Find the length of both the linked lists.
// Traverse the bigger linked list until the remaining nodes count becomes equal to the smaller one's.
// Traverse both the heads together. If both of them are same then the intersecting node is found.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    int findLength(ListNode *l1)
    {
        int count = 0;
        while (l1)
        {
            count++;
            l1 = l1->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        int lA = findLength(headA);
        int lB = findLength(headB);

        if (lA > lB)
        {
            while (lA > lB)
            {
                headA = headA->next;
                lA--;
            }
        }
        else if (lA < lB)
        {
            while (lA < lB)
            {
                headB = headB->next;
                lB--;
            }
        }

        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while (tempA && tempB)
        {
            if (tempA == tempB)
            {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
};