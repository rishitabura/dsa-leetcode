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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *prev;
        ListNode *slow = head;
        ListNode *fast = head;

        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *temp = slow;
        prev->next = slow->next;
        delete temp;

        return head;
    }
};