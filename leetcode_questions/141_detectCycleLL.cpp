/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NU) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NU && fast->next!=NU)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                return true;
            }
        }
        return false;


        
    }
};