/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode*temp1 = list1;
        int count = 1;
        while(count < a)
        {
            temp1 = temp1->next;
            count++;
        }

        int k = b-a+1;
        count = 1;
        ListNode* p = temp1->next;
        ListNode* q = p->next;

        while(count < k)
        {
            p = p->next;
            q = q->next;
            count++;
        }

        p->next = NULL;
        temp1->next = list2;
        ListNode*head = list1;

        while(list1->next != NULL)
        {
            list1 = list1->next;
        }
        list1->next = q;
        return head;

    }
};