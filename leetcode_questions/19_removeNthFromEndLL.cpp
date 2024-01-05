/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
       int count = 0;
        ListNode temp1 = head;
        while (temp1!=null)
        {
            count = count+1;
            temp1 = temp1.next;
        }
        int k = count-n;

        if (k == 0) {
            return head.next;
        }

        ListNode p = head;
        ListNode q = head.next;

        for(int i =1 ; i<k; i++)
        {
            p = p.next;
            q = q.next;
        }
        p.next = q.next;
        return head; 

        
    }
}