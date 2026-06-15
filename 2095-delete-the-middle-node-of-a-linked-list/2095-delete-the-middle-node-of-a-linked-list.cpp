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
        ListNode* curr = head;
        int size = 0;

        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }

        if (size == 1) return nullptr;

        int index = size/2;
        curr = head;

        for (int i=1; i<index; i++) {
            curr = curr->next;
        }
        curr->next = curr->next->next;

        return head;
    }
};