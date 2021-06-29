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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
            
        ListNode* tail = sortList(head->next);
        
        ListNode* tmp = new ListNode();
        tmp->next = tail;
        ListNode* current = tmp;
        while (1) {
            if (current->next == nullptr) {
                current->next = head;
                head->next = nullptr;
                break;
            }
            
            if (head->val < current->next->val) {
                head->next = current->next;
                current->next = head;
                break;
            }
            current = current->next;
        }
        
        return tmp->next;
    }
};
