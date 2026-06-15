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
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;

        if (fastPtr == nullptr) return nullptr;
        if (fastPtr->next == nullptr) {
            head->next = nullptr;
            return head;
        }

        fastPtr = fastPtr->next->next;

        while (fastPtr != nullptr) {
            slowPtr = slowPtr->next;
            if (fastPtr->next == nullptr) break;
            fastPtr = fastPtr->next->next;
        }
        slowPtr->next = slowPtr->next->next;

        return head;
    }
};