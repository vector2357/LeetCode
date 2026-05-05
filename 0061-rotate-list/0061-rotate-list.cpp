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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;

        int size = 0;
        ListNode* curr = head;
        ListNode* tail;

        while (curr != NULL) {
            size++;
            if (curr->next == NULL) tail = curr;
            curr = curr->next;
        }
        if (k%size == 0) return head;

        int pos = size - (k%size) - 1;

        curr = head;

        while (pos--) {
            curr = curr->next;
        }
        tail->next = head;
        head = curr->next;
        curr->next = NULL;

        return head;
    }
};