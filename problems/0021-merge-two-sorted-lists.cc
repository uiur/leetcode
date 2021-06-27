class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;

      if (l1->val <= l2->val) {
        ListNode* merged_head = mergeTwoLists(l1->next, l2);
        l1->next = merged_head;
        return l1;
      } else {
        return mergeTwoLists(l2, l1);
      }
    }
};
