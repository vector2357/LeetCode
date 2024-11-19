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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* aux = ans;
        ListNode* node1;
        ListNode* node2;

        while(aux->next && aux->next->next) {
            node1 = aux->next;
            node2 = node1->next;
            node1->next = node2->next;
            node2->next = node1;
            aux->next = node2;
            aux = node1;
        }
        return ans->next;
    }
};