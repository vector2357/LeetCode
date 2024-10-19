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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ans = new ListNode(0, head);
        ListNode *p = ans;

        for(int i=0; i<n; i++) {
            head = head->next;
        }

        while(head != NULL) {
            head = head->next;
            p = p->next;
            cout << 'a' << endl;
        }

        p->next = p->next->next;

        return ans->next;
    }
};