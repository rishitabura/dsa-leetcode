/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* current = head;
        ListNode* temp;

        while(fast!= NULL && fast->next!= NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                temp = fast;   
                while(temp!=current)
                {
                    current = current->next;
                    temp = temp->next;
                }
                return current;
            }
        }
        return NULL;
        
    }
};