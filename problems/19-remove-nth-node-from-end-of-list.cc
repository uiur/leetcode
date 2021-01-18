class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(0, head);

      ListNode* node = dummy;
      int size = 1;
      while (node->next != nullptr) {
        size++;
        node = node->next;
      }

      int target_index = size - n;

      node = dummy;
      for (int i = 0; i < target_index - 1; i++) {
        node = node->next;
      }

      ListNode* prev = node;
      ListNode* target = prev->next;
      prev->next = target->next;

      return dummy->next;
    }
};
