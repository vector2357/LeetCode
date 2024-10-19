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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        ListNode *head;
        
        if(list1->val < list2->val) {
            head = new ListNode(0, list1);
            list1 = list1->next;
        }
        else {
            head = new ListNode(0, list2);
            list2 = list2->next;
        }
        ListNode *p = head->next;

        while(list1!=NULL && list2!=NULL) {
            if(list1->val < list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        while(list1 != NULL) {
            p->next = list1;
            p = p->next;
            list1 = list1->next;
        }
        while(list2 != NULL) {
            p->next = list2;
            p = p->next;
            list2 = list2->next;
        }
        return head->next;
    }
};