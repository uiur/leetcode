// Runtime: 12 ms, faster than 71.21% of C++ online submissions for Linked List Cycle.
// Memory Usage: 8 MB, less than 79.43% of C++ online submissions for Linked List Cycle.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        int checked = INT_MIN;
        if (head->val == checked) return true;
        head->val = checked;
        return hasCycle(head->next);
    }
};
