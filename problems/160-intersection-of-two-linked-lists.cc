// Runtime: 52 ms, faster than 36.42% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 17.3 MB, less than 11.04% of C++ online submissions for Intersection of Two Linked Lists.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        
        ListNode* a = headA;
        while (a != nullptr) {
            s.insert(a);
            a = a->next;
        }
        
        ListNode* b = headB;
        while (b != nullptr) {
            if (s.find(b) != s.end()) return b;
            b = b->next;
        }
        return nullptr;
        
    }
};
