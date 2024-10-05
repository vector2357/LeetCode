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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode aux = new ListNode(0);
        ListNode ln = aux;
        int carry = 0;

        while (l1!=null || l2!=null || carry!=0) {
            int num1, num2;

            if (l1 != null) num1 = l1.val;
            else num1 = 0;
            if (l2 != null) num2 = l2.val;
            else num2 = 0;

            int sum = num1+num2+carry;
            int num = sum%10;
            carry = sum/10;

            ListNode temp = new ListNode(num);
            ln.next = temp;
            ln = ln.next;

            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        ln = aux.next;
        aux.next = null;

        return ln;
    }
}