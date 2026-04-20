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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        int k = lists.size(), menor;      

        ListNode* head = new ListNode();
        ListNode* aux = head;
        aux->next = new ListNode();
        ListNode* minNode = new ListNode(1e5);
        lists.push_back(minNode);

        bool flag = true;

        while (flag) {
            flag = false;
            menor = k;
            for (int i=0; i<k; i++) {
                if (lists[i] && lists[i]->val < lists[menor]->val) {
                    menor = i;
                }
                if (lists[i]) flag = true;
            }
            if (flag) {
                aux = aux->next;
                aux->val = lists[menor]->val;
                ListNode* node = new ListNode();
                aux->next = node;
                lists[menor] = lists[menor]->next;
            }
        }
        aux->next = NULL;

        return head->next;    
    }
};