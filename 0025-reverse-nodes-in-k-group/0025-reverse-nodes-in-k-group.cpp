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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        ListNode* aux = head;
        ListNode* prev = head;
        ListNode* lastTail = head;
        int i = 0, size = 0;

        while (aux != NULL) {
            size++;
            aux = aux->next;
        }
        aux = head->next;

        while ((aux != NULL && size > k) || size == k) {
            i++;
            if (i == k) {
                size -= k;
                if (tail == head) head = prev;
                else lastTail->next = prev;
                lastTail = tail;
                tail->next = aux;
                tail = aux;
                prev = aux;
                if (aux) aux = aux->next;
                i = 0;
            }
            else {
                ListNode* next = aux->next;
                aux->next = prev;
                prev = aux;
                aux = next;
            }
        }
        return head;
    }
};