// Runtime: 932 ms, faster than 5.02% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 14.6 MB, less than 24.65% of C++ online submissions for Intersection of Two Linked Lists.

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
        if (headA == nullptr) return nullptr;
        if (headB == nullptr) return nullptr;
        ListNode* b = headB;
        while (b != nullptr) {
            if (headA == b) return headA;
            b = b->next;
        }
        return getIntersectionNode(headA->next, headB);
    }
};
