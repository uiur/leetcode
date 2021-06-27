// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.5 MB, less than 98.91% of C++ online submissions for Swap Nodes in Pairs.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if (head == nullptr) return nullptr;
      if (head->next == nullptr) return head;

      ListNode* swapped_head = head->next;
      ListNode* tail = swapped_head->next;
      swapped_head->next = head;

      head->next = swapPairs(tail);
      return swapped_head;
    }
};
