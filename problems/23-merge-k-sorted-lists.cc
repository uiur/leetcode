// Runtime: 28 ms, faster than 89.19% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 26.7 MB, less than 5.09% of C++ online submissions for Merge k Sorted Lists.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if (lists.size() == 0) return nullptr;
      if (lists.size() == 1) return lists[0];
      if (lists.size() == 2) {
        return merge2Lists(lists[0], lists[1]);
      }

      int pivot = lists.size() / 2;
      vector<ListNode*> ls1(lists.begin(), lists.begin() + pivot);
      vector<ListNode*> ls2(lists.begin() + pivot, lists.end());
      return merge2Lists(mergeKLists(ls1), mergeKLists(ls2));
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;

      if (l1->val <= l2->val) {
        ListNode* merged_head = merge2Lists(l1->next, l2);
        l1->next = merged_head;
        return l1;
      } else {
        return merge2Lists(l2, l1);
      }
    }
};
